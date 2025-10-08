from pysat.formula import CNF
from pysat.solvers import Solver

# NOTE: Some inspiration for the code structure was taken from boilerplate code
#       given for Problem 2. All CNF encodings were implemented from scratch

class NandEncoder:
    def __init__(self, cnf):
        """
        Initialize encoder with grid and time limit.

        Args:
            cnf (list[list[int]]): Given CNF formula to convert to NAND formula
        """
        self.cnf = cnf
        
        self.variables = set()
        for clause in cnf:
            for atom in clause:
                self.variables.add(abs(atom))

        self.numVar = len(self.variables)
        self.variables = list(self.variables)
        self.dictVar = dict()
        for i, var in enumerate(self.variables):
            self.dictVar[var] = i + 1


    def make_atom(self, numG, varType, valuationNum, gateNum, inputNum):
        '''
        Args:
            numG (int):           number of NAND gates in the formula
            varType (int):        type of atom requested (0 or 1 or 2)
            valuationNum (int):   valuation number (1 to 2^numG)
            gateNum (int):        gate number (1 to numG)
            inputNum (int):       input to gate 'gateNum' (1 to (self.numVar + gateNum - 1))
                                  value = i (for i <= n) denotes x_i
                                  value = n+i denotes gate no. (i-1)

        Returns the atom for:
            - gate    (varType = 0) 
            - alpha   (varType = 1)
            - beta    (varType = 2)

        gate: value of (gateNum)-th gate in valuation(valuationNum)
        alpha: connection of gate(gateNum) to input(inputNum)
        beta: (alpha AND ~input(inputNum))


        Please refer to the report for the formulas encoded
        ============================================================

            Layout of mapping of atomic variables to integers:

                   |   (VALUATION 1)   |   (VALUATION 2)   |    
                   |        ^          |        ^          |    
                   |        |          |        |          |
            ALPHAS | GATES(1) BETAS(1) | GATES(2) BETAS(2) | ...
                   |                   |                   |

        ============================================================
        '''
        n = self.numVar # total number of variables
        g = numG        # total number of gates

        # ending atom for alphas
        alphaEnd = n*g + g*(g-1)//2

        # num of atoms required for each valuation - gates and betas
        atomsPerValuation = g + n*g + g*(g-1)//2

        # gate
        if varType == 0:
            # first block of valuationAtoms is reserved for gates, after which
            # betas come 
            return alphaEnd + atomsPerValuation*(valuationNum-1) + gateNum
        
        # alpha
        if varType == 1:
            return n*(gateNum-1) + (gateNum-2)*(gateNum-1)//2 + inputNum

        # beta
        return alphaEnd + atomsPerValuation*(valuationNum-1) + numG + n*(gateNum-1) \
                + (gateNum-2)*(gateNum-1)//2 + inputNum
    

    def encode(self, numG):
        """
        Encodes the problem of converting given CNF to NAND only
        circuit into another CNF to feed into the SAT solver.

        The make_atom() function gives the propositional atoms to 
        use in the formulas which are implemented here

        Args:
            numG (int): number of NAND gates to model the CNF

        Returns:
            formula (list[list[int]]): CNF encoding to model conversion to NAND formula
        """
        # for every valuation, we need a separate beta for holding AND(~proposition, gate)
        # we need n + (n+1) + ... + (n+g-1) betas for each valuation (same as alphas)
        # gates are valuation_specific
        # we need 'g' (=numG) gates for each valuation
        # alphas are common (wires) ( 1 to n*g + g*(g-1)/2 )
        
        formula = []

        # loop over 2^n valuations
        for valuation in range(1, 1 + (1 << self.numVar)):
            for gateNum in range(1, numG + 1):
                # SECTION 1: CONNECTIONS WITH ALL INPUTS
                # literals are added in the following sections
                gate = self.make_atom(numG, 0, valuation, gateNum, 0) # atom
                gateImpliesNotAllInputsOne = [-gate]
                someConnectionIsMade = []

                # SECTION 2: ITERATE OVER INPUTS IN x_1, x_2, ..., x_n
                for inputNum in range(1, self.numVar + 1):
                    alpha = self.make_atom(numG, 1, valuation, gateNum, inputNum) # atom
                    beta = self.make_atom(numG, 2, valuation, gateNum, inputNum) # atom

                    # clauses containing x_1, x_2, ..., x_n
                    if ((valuation-1) & (1 << (inputNum-1))) != 0:
                        # put ~beta(gateNum, inputNum) = 1
                        formula.append([-beta])
                    else:
                        # put beta(gateNum, inputNum) v ~alpha(gateNum, inputNum) = 1
                        # put gate v ~alpha(gateNum, inputNum) = 1
                        formula.append([beta, -alpha])
                        formula.append([gate, -alpha])

                    # clauses not containing x_1, x_2, ..., x_n
                    formula.append([-beta, alpha])
                    gateImpliesNotAllInputsOne.append(beta)
                    # execute only once
                    if valuation == 1:
                        someConnectionIsMade.append(alpha)

                # SECTION 3: ITERATE OVER INPUTS IN GATES
                for gateNumInput in range(1, gateNum):
                    inputGate = self.make_atom(numG, 0, valuation, gateNumInput, 0) # atom
                    inputNum = gateNumInput + self.numVar
                    alpha = self.make_atom(numG, 1, valuation, gateNum, inputNum) # atom
                    beta = self.make_atom(numG, 2, valuation, gateNum, inputNum) # atom

                    formula.append([-alpha, inputGate, gate])
                    formula.append([beta, -alpha, inputGate])
                    formula.append([-beta, alpha])
                    formula.append([-beta, -inputGate])
                    gateImpliesNotAllInputsOne.append(beta)
                    # execute only once
                    if valuation == 1:
                        someConnectionIsMade.append(alpha)

                formula.append(gateImpliesNotAllInputsOne)
                # execute only once
                if valuation == 1:
                    formula.append(someConnectionIsMade)
        
            # Find CNF output on the valuation
            cnfOutput = 1
            for clause in self.cnf:
                # check if clause is true
                clauseSign = False
                for literal in clause:
                    if literal < 0:
                        # check if assignment is false
                        literal = -literal
                        if (valuation-1) & (1 << (self.dictVar[literal]-1)) == 0:
                            clauseSign = True
                            break
                    else:
                        # check if assignment is true
                        if (valuation-1) & (1 << (self.dictVar[literal]-1)) != 0:
                            clauseSign = True
                            break

                if not clauseSign:
                    cnfOutput = -1
                    break

            # cnfOutput determines sign of literal
            # Output gate of the model should be the same as CNF output
            formula.append([cnfOutput*self.make_atom(numG, 0, valuation, numG, 0)])
        return formula

#####################################################################################################
# END OF CLASS

def decode(model, encoder, numG):
    """
    Return connections to gates for an equivalent NAND formula having numG gates

    Args:
        model (list[int]): Satisfying assignment from SAT solver.
        encoder (NandEncoder): Encoder object with formula info.
        numG (int): number of NAND gates in the model

    Returns:
        list[list[int]]: Connections to each gate for an equivalent NAND formula
                         with numG gates
    """
    n = encoder.numVar
    ind = 0
    connections = []
    for i in range(n, n+numG):
        gate_inputs = []
        for j in range(i):
            if model[ind+j] > 0:
                if j < n:
                    # x_i
                    gate_inputs.append(f'x{encoder.variables[j]}')
                else:
                    gate_inputs.append(f'G{j-n+1}')
        ind += i
        connections.append(gate_inputs)
    return connections


def searchAnswer(cnf, upperLimit):
    """
    Binary search on the range [1, upper limit] to find the 
    minimum number of NAND gates required to express the CNF

    Args:
        upperLimit (int): upper limit on the binary search

    Returns:
        list[list[int]]: Connections for each gate for an optimum 
                         equivalent NAND formula
    """
    l = 1
    r = upperLimit
    model = []
    numG = 0
    while l <= r:
        mid = (l+r)//2
        encoder = NandEncoder(cnf)
        formula = encoder.encode(mid)
        with Solver(name='g3') as solver:
            solver.append_formula(formula)
            if not solver.solve(): # more gates required
                l = mid + 1
            else: # gates are sufficient
                numG = mid 
                model = solver.get_model()
                r = mid - 1

    # return the connections for the optimised NAND formula
    return decode(model, encoder, numG)


# Take input by user
cnf = []
n = int(input())
for _ in range(n):
    line = input()
    clause = [int(x) for x in line.split(' ')]
    cnf.append(clause)

# Theoretical max for no. of NAND gates (See report)
# maxNand = (No. of literals) + (No. of clauses) + 2
maxNand = len(cnf) + 2 
for clause in cnf:
    maxNand += len(clause)

# Connections output by SAT solver
connections = searchAnswer(cnf, maxNand)

for gate, gatecon in enumerate(connections):
    print(f'G{gate+1} = ', end='')

    # special case where only one input to NAND gate
    # works as if same input given twice (note: x&x = x)
    # because NAND gate has been modelled as 1 iff some
    # input is 1
    if len(gatecon) == 1: 
        print(f'NAND({gatecon[0]}, {gatecon[0]})')
    else:
        print(f'NAND({", ".join(gatecon)})')

print(f'OUTPUT = G{len(connections)}')
print(f'Total NAND gates used: {len(connections)}')


from pysat.formula import CNF# type: ignore
from pysat.solvers import Solver # type: ignore

# Finds the bit value of t at i-th position
def bit_at(t, i):
    while(i):
        t = t//2
        i -= 1
    return t%2

class NANDy:
    # Initializes the class with number of variables and CNF clauses as input
    def __init__(self, no_inputs, clauses, no_gates):
        self.no_inputs = no_inputs
        self.clauses = clauses
        self.no_gates = no_gates
        self.max_assignments = 2**no_inputs

    # Encoding of input nodes
    def var_input(self, i, t):
        return 1 + (self.no_inputs+self.no_gates) * t + i

    # Encoding of NAND nodes
    def var_gate(self, i, k, j): 
        return 1 + self.max_assignments*(self.no_inputs+self.no_gates) + (self.no_inputs+i-1)*(i-self.no_inputs) + i*k + j
    
    # Helping function to produce the truth table for the CNF for all the possible assignments
    def truth_table(self):
        table = []
        for t in range(2**self.no_inputs):
            result = 1
            for clause in self.clauses:
                temp = False
                for literal in clause:
                    val = bit_at(t, abs(literal)-1)
                    if (literal > 0 and val == 1) or (literal < 0 and val == 0):
                        temp = True
                        break
                if not temp:
                    result = 0
                    break
            table.append(result)
        return table

    # Try making NAND circuit from G NAND gates
    def encode(self):
        cnf = CNF()
        no_inputs = self.no_inputs
        N = self.no_gates

        # 1. Input of each NAND gate is taken from previous nodes(Can be either input node or NAND node)
        for gate in range(no_inputs, no_inputs + N):
            temp0 = []
            temp1 = []
            for i in range(gate):
                temp0.append(self.var_gate(gate, 0, i))
                temp1.append(self.var_gate(gate, 1, i))
            cnf.append(temp0) # atleast 1
            cnf.append(temp1) # atleast 1
            for i in range(gate):
                for j in range(i+1, gate):
                    cnf.append([-temp0[i], -temp0[j]]) # atmost 2
                    cnf.append([-temp1[i], -temp1[j]]) # atmost 2

        # 2. Fix input values for input nodes for each assignment
        for t in range(2**no_inputs):
            for i in range(no_inputs):
                lit = self.var_input(i, t)
                if bit_at(t, i) == 1:
                    cnf.append([lit]) # input value fixed for every assignment
                else:
                    cnf.append([-lit]) # input value fixed for every assignment

        # 3. For each gate and assignment: y = NAND(a,b)
        for t in range(2**no_inputs):
            for gate in range(no_inputs, no_inputs + N):
                y = self.var_input(gate, t)
                for j0 in range(gate):
                    for j1 in range(gate):
                        sel = (self.var_gate(gate, 0, j0), self.var_gate(gate, 1, j1))
                        a = self.var_input(j0, t)
                        b = self.var_input(j1, t)
                        # implemnt NAND logic
                        cnf.append([-sel[0], -sel[1], y, a])
                        cnf.append([-sel[0], -sel[1], y, b])
                        cnf.append([-sel[0], -sel[1], -y, -a, -b])

        # 4. Fix the last output for all assignments
        truth_tablee = self.truth_table()
        for i in range(len(truth_tablee)):
            truth_value = truth_tablee[i]
            y = self.var_input(no_inputs + N - 1, i)
            cnf.append([y] if truth_value == 1 else [-y]) # force circuit to match with truth table generated from CNF

        # Solve
        with Solver(name='g3') as solver:
            solver.append_formula(cnf)
            if not solver.solve():
                return False
            model = solver.get_model()

        # Decoding
        edges = {}
        for gate in range(no_inputs, no_inputs + N):
            for j in range(gate):
                    if model[self.var_gate(gate, 0, j)-1]>0:
                        src0 = j
                        break
            for j in range(gate):
                    if model[self.var_gate(gate, 1, j)-1]>0:
                        src1 = j
                        break
            edges[gate] = (src0, src1)

        # Print solution if there is one
        for gate in range(no_inputs, no_inputs + N):
            a, b = edges[gate]
            node_a = f"x{a+1}" if a < no_inputs else f"G{a-no_inputs+1}"
            node_b = f"x{b+1}" if b < no_inputs else f"G{b-no_inputs+1}"
            print(f"G{gate-no_inputs+1} = NAND({node_a}, {node_b})")
        print(f"OUTPUT = G{N}")
        print(f"Total NAND gates used: {N}")
        return True

# Initializes an instance of NANDy with number of variables, given CNF, and number of gates(tries to make a NANDy 
# circuit with minimal gates starting from 1 till it finds a solution)
def make_NANDy(no_inputs, clauses):
    G = 0
    while (True):
        G += 1
        synth = NANDy(no_inputs, clauses, G)
        ok = synth.encode()
        if ok:
            return True

if __name__ == "__main__":
    m = int(input())
    clauses = []
    no_inputs = 0
    for _ in range(m):
        clause = list(map(int, input().split()))
        clauses.append(clause)
        no_inputs = max(no_inputs, max(abs(l) for l in clause))
    make_NANDy(no_inputs, clauses)

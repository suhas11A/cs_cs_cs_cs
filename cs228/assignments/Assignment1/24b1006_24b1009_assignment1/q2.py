"""
Sokoban Solver using SAT (Boilerplate)
--------------------------------------
Instructions:
- Implement encoding of Sokoban into CNF.
- Use PySAT to solve the CNF and extract moves.
- Ensure constraints for player movement, box pushes, and goal conditions.

Grid Encoding:
- 'P' = Player
- 'B' = Box
- 'G' = Goal
- '#' = Wall
- '.' = Empty space
"""

from pysat.formula import CNF # type: ignore
from pysat.solvers import Solver # type: ignore

# Directions for movement
DIRS = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
DIRS_ME = [(-1, 0), (1, 0), (0, -1), (0, 1)]


class SokobanEncoder:
    def __init__(self, grid, T):
        self.grid = grid
        self.T = T+1
        self.N = len(grid)
        self.M = len(grid[0])

        self.goals = []
        self.boxes = []
        self.walls = []
        self.player_start = None

        self._parse_grid()

        self.num_boxes = len(self.boxes)
        self.cnf = CNF()

    def _parse_grid(self):
        for i in range(self.N):
            for j in range(self.M):
                if (self.grid[i][j]=="B"):
                    self.boxes.append([j,i])
                elif (self.grid[i][j]=="G"):
                    self.goals.append([j,i])
                elif (self.grid[i][j]=="#"):
                    self.walls.append([j,i])
                elif (self.grid[i][j]=="P"):
                    self.player_start = [j,i]

    # ---------------- Variable Encoding ----------------
    def var_player(self, x, y, t):
        return self.N*self.T*x + self.T*y + t + 1

    def var_box(self, b, x, y, t):
        return self.N*self.M*self.T*b + self.N*self.T*x + self.T*y + t + 1
    
    def inv_box(self, code):
        code -= 1
        t = code%self.T
        code //= self.T
        y = code%self.N
        code //= self.N
        x = code%self.M
        b = code//self.M
        return [b,x,y,t]
    
    def is_valid(self, x, y):
        if ([x,y] in self.walls):
            return False
        if (self.inv_box(self.var_box(0, x, y, 0))!=[0,x,y,0]):
            return False
        return True
    # ---------------- Encoding Logic ----------------
    def encode(self):
        # 1. Initial conditions
        for b_num in range(1, len(self.boxes)+1):
            self.cnf.append([self.var_box(b_num, self.boxes[b_num-1][0], self.boxes[b_num-1][1],0)])            
        self.cnf.append([self.var_box(0, self.player_start[0], self.player_start[1],0)])

        # 2. Player movement
        for x in range(self.M):
            for y in range(self.N):
                for t in range(self.T-1):
                    temp=[-self.var_box(0,x,y,t),self.var_box(0,x,y,t+1)] # 
                    for i in DIRS_ME:
                        if(self.is_valid(x+i[0],y+i[1])):
                            temp.append(self.var_box(0,x+i[0],y+i[1],t+1))
                    self.cnf.append(temp)

        # 3. Box movement
        for x in range(self.M):
            for y in range(self.N):
                for t in range(self.T-1):
                    for i in DIRS_ME:
                        for b_num in range(1,len(self.boxes)+1):
                            if(self.is_valid(x+i[0],y+i[1])):
                                if(self.is_valid(x+2*i[0],y+2*i[1])):
                                    self.cnf.append([-self.var_box(0,x,y,t),-self.var_box(0,x+i[0],y+i[1],t+1),-self.var_box(b_num,x+i[0],y+i[1],t),self.var_box(b_num,x+2*i[0],y+2*i[1],t+1)])
                                else:
                                    self.cnf.append([-self.var_box(0,x,y,t),-self.var_box(0,x+i[0],y+i[1],t+1),-self.var_box(b_num,x+i[0],y+i[1],t),self.var_box(b_num,x+i[0],y+i[1],t+1)])
        
        # 4. Non-overlap constraints
        for x in range(self.M):
            for y in range(self.N):
                for t in range(self.T):
                    for b1 in range(len(self.boxes)+1):
                        for b2 in range(b1+1,len(self.boxes)+1):
                            self.cnf.append([-self.var_box(b1,x,y,t),-self.var_box(b2,x,y,t)])

        # 5. Goal conditions
        for b_num in range(1,len(self.boxes)+1):
            temp = []
            for g in range(len(self.goals)):
                temp.append(self.var_box(b_num,self.goals[g][0],self.goals[g][1],self.T-1))
            self.cnf.append(temp)

        # 6. There is only one player/box at a time
        for b_num in range(0, len(self.boxes)+1):
            for t in range(self.T):
                temp = []
                for x in range(self.M):
                    for y in range(self.N):
                        temp.append(self.var_box(b_num, x, y, t))
                self.cnf.append(temp)
                for index1 in range(self.M * self.N):
                    x1, y1 = index1%self.M, index1//self.M
                    for index2 in range(index1+1, self.M * self.N):
                        x2, y2 = index2%self.M, index2//self.M
                        self.cnf.append([-self.var_box(b_num, x1, y1, t), -self.var_box(b_num, x2, y2, t)])
        
        # 7. Box doesnt move on its own
        for b_num in range(1, len(self.boxes)+1):
            for x in range(self.M):
                for y in range(self.N):
                    for t in range(self.T-1):
                        self.cnf.append([-self.var_box(b_num,x,y,t),self.var_box(0,x,y,t+1),self.var_box(b_num,x,y,t+1)])

        return self.cnf

            
def decode(model, encoder):
    """
    Decode SAT model into list of moves ('U', 'D', 'L', 'R').

    Args:
        model (list[int]): Satisfying assignment from SAT solver.
        encoder (SokobanEncoder): Encoder object with grid info.

    Returns:
        list[str]: Sequence of moves.
    """
    N, M, T = encoder.N, encoder.M, encoder.T
    cords={}
    moves=[]
    for i in range(M*N*T):
        if(model[i]>0):
            cords[i%T]=encoder.inv_box(model[i])[1:3]
    for t in range(T-1):
        diff_x = cords[t+1][0] - cords[t][0]
        diff_y = cords[t+1][1] - cords[t][1]
        if diff_x==0 and diff_y==1:
            moves.append('D')
        elif diff_x==1 and diff_y==0:
            moves.append('R')
        elif diff_x==0 and diff_y==-1:
            moves.append('U')
        elif diff_x==-1 and diff_y==0:
            moves.append('L')
    return moves


def solve_sokoban(grid, T):
    """
    DO NOT MODIFY THIS FUNCTION.

    Solve Sokoban using SAT encoding.

    Args:
        grid (list[list[str]]): Sokoban grid.
        T (int): Max number of steps allowed.

    Returns:
        list[str] or "unsat": Move sequence or unsatisfiable.
    """
    encoder = SokobanEncoder(grid, T)
    cnf = encoder.encode()

    with Solver(name='g3') as solver:
        solver.append_formula(cnf)
        if not solver.solve():
            return -1

        model = solver.get_model()
        if not model:
            return -1

        return decode(model, encoder)
    
# if __name__ == "__main__":
#     print(solve_sokoban([["P","B","G"]], 1))
#     print(solve_sokoban([["P"],["B"],["G"]], 1))
#     print(solve_sokoban([["P",".","."], [".","B","G"], [".",".","."]], 2))
#     print(solve_sokoban([["P",".",".",".","."], [".",".",".","B","G"]], 4))
#     print(solve_sokoban([["P","B","G"], [".",".","."], [".",".","."]], 1))
#     print(solve_sokoban([[".", "#", "G"], ["P", "B", "."], [".", ".", "."]], 4))
#     print(solve_sokoban([[".", "G", ".", "G", "."], [".", ".", ".", ".", "."], [".", "B", ".", "B", "."], ["P", ".", ".", ".", "."], [".", ".", ".", ".", "."]], 9))
#     print(solve_sokoban([[".", "G", "."], [".", ".", "."], [".", "B", "."], [".", ".", "."], [".", ".", "."], [".", "P", "."]], 4))
#     print(solve_sokoban([["G",".","G"], ["B",".","."], ["P",".","."]], 1))
#     print(solve_sokoban([["P"] + ["."]*17 + ["B","G"]], 18))
#     print(solve_sokoban([["P"]] + [["."]]*22 + [["B"],["G"]], 23))
#     # === UNSAT cases (any T, I’m just giving one representative T) ===
#     print(solve_sokoban([["B",".","G"], ["P",".","."], [".",".","."]], 100))
#     print(solve_sokoban([["P",".",".","."], [".","B",".","G"], [".","B",".","."]], 100))
#     print(solve_sokoban([["#","#","#","#","#"], ["#","G","#","#","#"], ["#","#","#",".","#"], ["#","P",".","B","#"], ["#","#","#","#","#"]], 100))
#     print(solve_sokoban([[".",".","G",".","."], ["#","#","#","#","#"], ["P",".","B",".","."]], 100))
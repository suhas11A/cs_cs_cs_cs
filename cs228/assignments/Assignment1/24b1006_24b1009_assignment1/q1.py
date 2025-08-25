"""
sudoku_solver.py

Implement the function `solve_sudoku(grid: List[List[int]]) -> List[List[int]]` using a SAT solver from PySAT.
"""

from pysat.formula import CNF # type: ignore
from pysat.solvers import Solver # type: ignore
from typing import List

def bij(i,j,n):
    return 81*i + 9*j + n - 90

def inv_bij(k):
    k -= 1
    n = k%9 + 1
    k //= 9
    j = k%9 + 1
    i = k//9 + 1
    return (i, j, n)

def solve_sudoku(grid: List[List[int]]) -> List[List[int]]:
    cnf = CNF() # Start
    # For each Cell
    for i in range(1,10):
        for j in range(1,10):
            temp = [bij(i, j, n) for n in range(1, 10)]
            cnf.append(temp)
            for a in range(len(temp)):
                for b in range(a + 1, len(temp)):
                    cnf.append([-temp[a], -temp[b]])
    # For each Row
    for i in range(1,10):
        for n in range(1,10):
            temp = [bij(i, j, n) for j in range(1, 10)]
            cnf.append(temp)
    # For each Column
    for j in range(1,10):
        for n in range(1,10):
            temp = [bij(i, j, n) for i in range(1, 10)]
            cnf.append(temp)
    # For each 3x3 Block
    for b in range(9):
        for n in range(1,10):
            temp = []
            for i in range(3*(b//3) + 1, 3*(b//3) + 4):
                for j in range(3*(b%3) + 1, 3*(b%3) + 4):
                    temp.append(bij(i,j,n))
            cnf.append(temp)
    # Initial conditions
    filled = []
    for i in range(1, 10):
        for j in range(1, 10):
            n = grid[i-1][j-1]
            if n != 0:
                filled.append([bij(i, j, n)])
    cnf.extend(filled)
    # Solve
    ans = [[0 for _ in range(9)] for _ in range(9)]
    with Solver(name='glucose3') as solver:
        solver.append_formula(cnf.clauses)
        if solver.solve():
            model = solver.get_model()
            for hehe in model:
                if hehe>0:
                    i,j,n = inv_bij(hehe)
                    ans[i-1][j-1] = n
            return ans
        else:
            return []
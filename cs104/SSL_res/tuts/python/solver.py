# Some mathematical tools defined like in a module
import math

def solve_linear(a,b):
    """
        Solves the linear equation a*x + b = 0.
        Takes two arguments, a and b, and returns the solution x.
    """
    if a != 0:
        return -b/a
    else:
        print("No solution")
        return None

def solve_quadratic(a,b,c):
    """
    Solves the quadratic equation a*x**2 + b*x + c = 0.
    Takes three arguments, a, b and c, and returns the solutions x_1 and x_2, 
    or None, None if there are no real solutions.
    """
    D = b**2 - 4*a*c
    if D >= 0:
        x_1 = (-b + math.sqrt(D))/(2*a)
        x_2 = (-b - math.sqrt(D))/(2*a)
        return x_1, x_2
    else:
        print("No real solution")
        return None, None


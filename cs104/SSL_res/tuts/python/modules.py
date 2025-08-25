# Modules can be user-defined, like branch_change or student

# importing specific functions, classes from a module
# from solver import solve_linear, solve_quadratic, solve_cubic

# Importing everything from a module
from solver import *

print("The solution of 4x + 3 = 0 is x =", solve_linear(4,3))
print("The solutions of x**2 - 4x + 3 = 0 are x =", solve_quadratic(1,-4,3))

#-------------------------------------------------------------

# Some are built-in modules
import math
import random
import time 

# time module
start = time.time()

# math module
a = 5
b = 7
c = math.sqrt(a**2 + b**2)
print(c)
c = math.floor(c)
print(c)
c = math.sin(math.pi/2)
print(c)

# random module
a = random.random()
print(a)
a = random.randint(1,10)
print(a)
a = random.choice(['a','b','c','d'])
print(a)

end = time.time()
print("Time taken:", end - start, "seconds")
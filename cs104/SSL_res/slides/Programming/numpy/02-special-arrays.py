import numpy as np

# Special types of arrays

# Array with ones on the main diagonal and zeros elsewhere (Identity matrix)
arr = np.eye(3)
print("0 (Identity matrix)\n", arr)

# Array with zeros everywhere
arr = np.zeros((2, 3))
print("1 (Zeros array)\n", arr)

# Array with ones everywhere
arr = np.ones((3, 4))
print("2 (Ones array)\n", arr)

# An array with evenly spaced values via step within a specified interval
arr = np.arange(10, 20, 2, dtype=float)
print("3 (Arange array)\n", arr)

# Evenly spaced values between the interval as specified
arr = np.linspace(10, 20, 5)
print("4 (Linspace array)\n", arr)

print('\nRandom values\n')

# Random values between 0 and 1 in a 3x2 matrix
arr = np.random.rand(3, 2)
print("5 (Random array - uniform distribution)\n", arr)

# Random integers from 0 to 50, 2-D with size 3x5
x = np.random.randint(50, size=(3, 5))
print("6 (Random integers)\n", x)

# Array without initialization (empty array with random data)
arr = np.empty((3, 3))
print("7 (Empty array)\n", arr)

# Diagonal matrix (values along the diagonal)
arr = np.diag([1, 2, 3, 4])
print("8 (Diagonal array)\n", arr)

# Create a 2D array
arr = np.array([[1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]])

print("9 (Original 2D array)\n", arr)

# Extract the diagonal of the array
diagonal = np.diag(arr)
print("10 (Extracted diagonal)\n", diagonal)

# Random choice of elements from a specified list (random sampling)
arr = np.random.choice([10, 20, 30, 40, 50], size=(2, 3))
print("11 (Random choice array)\n", arr)


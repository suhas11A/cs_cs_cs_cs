import numpy as np

# 1. Basic Arithmetic Operations
a = np.array([10, 20, 30])
b = np.array([1, 2, 3])

# Addition, Subtraction, Multiplication, Division, Modulus, Exponentiation, Floor Division
add_result = a + b
sub_result = a - b
mul_result = a * b
div_result = a / b
mod_result = a % b
exp_result = a ** b
floor_div_result = a // b

print("\n1. Basic Arithmetic Operations:")
print("a + b:", add_result)
print("a - b:", sub_result)
print("a * b:", mul_result)
print("a / b:", div_result)
print("a % b:", mod_result)
print("a ** b:", exp_result)
print("a // b:", floor_div_result)

# 2. Broadcasting with Scalar
scalar = 2
broadcast_add = a + scalar
broadcast_mul = a * scalar

print("\n2. Broadcasting with Scalar:")
print("a + scalar:", broadcast_add)
print("a * scalar:", broadcast_mul)

# 3. Universal Functions (ufuncs)
sqrt_result = np.sqrt(a)  # Square root
exp_result_ufunc = np.exp(a)  # Exponential
log_result = np.log(a)  # Natural logarithm
sin_result = np.sin(a)  # Sine function
abs_result = np.abs(a)  # Absolute value

print("\n3. Universal Functions (ufuncs):")
print("Square root of a:", sqrt_result)
print("Exponential of a:", exp_result_ufunc)
print("Natural logarithm of a:", log_result)
print("Sine of a:", sin_result)
print("Absolute value of a:", abs_result)

# 4. Arrays with the Same Shape: Arithmetic is straightforward (Element by element)
print("\n4. Arrays with same shape:")
arr = np.array([[1, 2, 3], [4, 5, 6]])
print("Array 1:")
print(arr)
print("\nArray 1 * Array 1:")
print(arr * arr)  # Element-wise multiplication
print("\nArray 1 - Array 1:")
print(arr - arr)  # Element-wise subtraction
print("\nArray 1 ** 2:")
print(arr ** 2)  # Element-wise power

# 5. Comparison between Arrays
arr1 = np.array([[0, 2, 4], [7, 2, 8]])
print("\n5. Array 1:")
print(arr1)
print("\nArray 1 > Array 1:")
print(arr1 > arr)  # Element-wise comparison (True/False)

# 6. Arrays with Different Shapes: Broadcasting
print("\n6. Arrays in different shape:")
a = np.array([[0.0, 0.0, 0.0], [10.0, 10.0, 10.0], [20.0, 20.0, 20.0], [30.0, 30.0, 30.0]])
b = np.array([1.0, 2.0, 3.0])

print('First array:')
print(a)
print('\nSecond array:')
print(b)

# The smaller array (b) is broadcast to the size of the larger array (a)
print('\nFirst Array + Second Array (Broadcasted):')
print(a + b)

# 7. Matrix Transpose
matrix_a = np.array([[1, 2], [3, 4]])
print('\n7. Transpose of Matrix A:')
print(np.transpose(matrix_a))  # Transpose of A

# 8. Sine of Different Angles (Trigonometric Functions)
a = np.array([0, 30, 45, 60, 90])
print('\n8. Sine of different angles (converted to radians):')
print(np.sin(a * np.pi / 180))  # Convert degrees to radians and compute sine

# 9. Statistics Functions: Median
a = np.array([[30, 65, 70], [80, 95, 10], [50, 90, 60]])

print('\n9. Our array is:')
print(a)

print('\nApplying median() function:')
print(np.median(a))  # Median of all elements

print('\nApplying median() function along axis 0 (columns):')
print(np.median(a, axis=0))  # Median of each column

print('\nApplying median() function along axis 1 (rows):')
print(np.median(a, axis=1))  # Median of each row

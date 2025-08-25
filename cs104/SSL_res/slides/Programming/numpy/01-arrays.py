import numpy as np

print("0", np.__version__)

# Creating arrays using lists and tuples
arr = np.array([1, 2, 3, 4, 5])
# arr = np.array((1, 2, 3, 4, 5))
#type of array and data type of array
print("1", arr)
print("2", type(arr))
print("3", arr.dtype)

# Creating arrays with explicit data types
arr = np.array([1, 2, 3, 4], dtype='i4')
print("4", arr)
print("5", arr.dtype)
arr = np.array([1, 2, 3], dtype=complex)
print("6", arr)
print("7", arr.dtype)

# Converting data types using astype()
arr = np.array([1.1, 2.1, 3.1])
newarr = arr.astype('i')
print("8", newarr)
print("9", newarr.dtype)

# Creating arrays with different dimensions
arr0 = np.array(42)  # 0D array
arr1 = np.array([1, 2, 3, 4, 5])  # 1D array
arr2 = np.array([[1, 2, 3], [4, 5, 6]])  # 2D array
arr3 = np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])  # 3D array
arr5 = np.array([1, 2, 3, 4], ndmin=5)  # 5D array

# Checking dimensions
print("10", arr0.ndim)
print("11", arr1.ndim)
print("12", arr2.ndim)
print("13", arr3.ndim)
print("14", 'number of dimensions :', arr5.ndim)

# Copy vs View
arr = np.array([1, 2, 3, 4, 5])
x = arr.copy()  # Creates a new array, changes in copy don't affect original
y = arr.view()  # Creates a view, changes in view reflect in the original

# Modifying copy and view
x[0] = 10
y[1] = 5
arr[2] = 15

# Display results
print("15", arr)
print("16", x)
print("17", y)

# Base property to check ownership
print("18", x.base)
print("19", y.base)

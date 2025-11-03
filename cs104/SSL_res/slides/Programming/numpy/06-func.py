import numpy as np

# Concatenate
arr1 = np.array([1, 2, 3])
arr2 = np.array([4, 5, 6])
arr = np.concatenate((arr1, arr2))
print("1. Concatenate 1D arrays\n", arr) 

# Concatenate 2D arrays along different axes
arr1 = np.array([[1, 2], [3, 4]])
arr2 = np.array([[5, 6], [7, 8]])

arr = np.concatenate((arr1, arr2), axis=0)  # Concatenate along axis 0 (rows)
print("\n2. Concatenate 2D arrays along axis 0\n", arr)
print("Shape is", arr.shape)

arr = np.concatenate((arr1, arr2), axis=1)  # Concatenate along axis 1 (columns)
print("\n3. Concatenate 2D arrays along axis 1\n", arr)
print("Shape is", arr.shape)

# Stack arrays along different axes
print("\n4. Stacking along axis=0")
arr = np.stack((arr1, arr2), axis=0)
print(arr)
print("Shape is", arr.shape)

print("\n5. Stacking along axis=1")
arr = np.stack((arr1, arr2), axis=1)
print(arr)
print("Shape is", arr.shape)

# Splitting 1-D arrays
# result is a list of NumPy arrays
print("\n6. Splitting 1D array")
arr = np.array([1, 2, 3, 4, 5, 6])
# split requires equal-sized splits
newarr = np.split(arr, 3)
print("Split 1D array into 3 parts:", newarr)
print("Accessing first array:", newarr[0])

# Using array_split for unequal splits
newarr1 = np.array_split(arr, 4)
print("7. Array split into 4 parts (uneven split):", newarr1[0])
print("7. Array split into 4 parts (uneven split):", newarr1[1])
print("7. Array split into 4 parts (uneven split):", newarr1[2])
print("7. Array split into 4 parts (uneven split):", newarr1[3])



# Splitting 2-D arrays
arr2d = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12], [13, 14, 15], [16, 17, 18]])
newarr = np.array_split(arr2d, 3, axis=1)  # Split along axis 1 (columns)
print("\n8. Splitting 2D array along axis 1")
print("First split result:", newarr[0])

# Searching arrays
arr = np.array([1, 2, 3, 4, 5, 4, 4])
print("\n9. Searching array for element 4:")
x = np.where(arr == 4)
print("Index positions where element is 4:", x)

print("\n10. Searching for odd values:")
x = np.where(arr % 2 == 1)
print("Index positions where values are odd:", x)

# Sorting arrays
arr2d = np.array([[3, 2, 4], [5, 0, 1]])
print("\n11. Sorting 2D array")
sorted_arr = np.sort(arr2d)
print("Sorted array:", sorted_arr)


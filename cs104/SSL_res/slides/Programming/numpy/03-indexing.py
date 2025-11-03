import numpy as np

# 1D array
arr = np.array([1, 2, 3, 4, 5, 6, 7])
print("1: 1D Array:\n", arr)

# Basic Indexing - Accessing the second element (index 1)
print("2: Basic Indexing (Second element):", arr[1])  # Index starts at 0

# Slicing - Extract elements from index 1 to 4; note 5 is not included
print("3: Slicing (Index 1 to 4):", arr[1:5])

# Negative Indexing - Access elements from the end of the array
#-1 refers to last element and -2 to second last and so on
# Here we are asking it access elements -3 and -2, -1 is not included
print("4: Negative Indexing (Last 3rd and 2nd-last element):", arr[-3:-1])

# Stepping - Step through the array, with a step of 2
print("5: Stepping (Step by 2, Index 1 to 5):", arr[1:5:2]) 

# Stepping - Extract every other element
#This is also a stepping through, when no index is specified, it will start from beginning and go to end
print("6: Stepping (Every other element):", arr[::2])

# 2D array
arr = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])
print("7: 2D Array:\n", arr)

# Accessing a specific element in a 2D array
#Row 2 here refers to a row with index 1 (humans count from 1 hence row 2 , machines count from 0, hence index 1)
#column 5 refers to column with index 4
print("8: Accessing specific element (Row 2, Column 5):", arr[1, 4])  # Row 2, Column 5 -> 10

# Slicing - Extracting multiple rows and columns (Rows 1-2, Columns 2-4)
print("9: Slicing (Rows 1-2, Columns 2-4):\n", arr[0:2, 1:4]) 

# Extracting the second column (Using ellipsis to access all rows)
second_col = arr[..., 1]
print("10: Accessing the second column:\n", second_col)
print("Shape:", second_col.shape)  # Prints the shape

# Retaining dimensions when extracting the second column
second_col_2D = arr[:, 1:2]
print("11: Retaining dimensions (Second column with 2D shape):\n", second_col_2D)
print("Shape:", second_col_2D.shape)  # Prints the shape

# Accessing the second row using ellipsis
print("12: Accessing the second row:\n", arr[1, ...])

# 3D array
arr = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])
print("13: 3D Array:\n", arr)

# Accessing a specific element in a 3D array (First block, second row, third element)
print("14: Accessing specific element (Block 1, Row 2, Element 3):", arr[0, 1, 2])  # Should print 6

# Accessing all elements in the second row across all blocks using ellipsis
print("15: Accessing second row across all blocks using ellipses\n", arr[:, 1, ...]) 
print("15: Accessing second row across all blocks using :\n", arr[:, 1, :]) 


# Extracting all elements from the third column across all blocks
#arr[..., 2] → Equivalent to arr[:, :, 2]
print("16: Accessing third column across all blocks:\n", arr[..., 2])  

# Iterating through the first dimension of a 3D array (blocks)
print("17: Iterating along the first dimension:")
for x in arr:
    print(x, "\n")  # Each 'x' will represent one block of the 3D array

# Iterating through the rows in the matrix (2D slices from each block)
print("18: Iterating through rows in the matrix:")
for x in arr:
    for y in x:
        print(y)  # Each 'y' represents a row within a block

# Iterating through individual elements in the array
print("19: Iterating through elements in the array:")
for x in arr:
    for y in x:
        for z in y:
            print(z, end=" ")  # Each 'z' is an individual element of the array
print("\n")

# Using np.ndenumerate to get index information while iterating
#np.ndenumerate() is a function that provides both the index and the value of each element
print("20: Using np.ndenumerate to access index and element:")
for idx, x in np.ndenumerate(arr):
    print(f"Index {idx}: {x}")  # Prints the index and the corresponding value

#Boolen indexing
arr = np.array([1, 2, 3, 4, 5, 6])
mask = arr>3
#When you do arr[mask],
# Scans the Boolean Mask and picks the True indices:
# Creates a New Array containing only those elements:
greater_than_3 = arr[mask]
print("21: mask:", mask)
print("22: Numbers > 3:", greater_than_3)

# Another example
arr = np.array([41, 42, 43, 44])
x = [False, False, True, True]  # Only select elements where index is True
newarr = arr[x]
print("\n12. Filtering with boolean index list:", newarr)





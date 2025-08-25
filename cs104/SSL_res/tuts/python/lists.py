numbers = [28, 32, 45, 67, 89]
fruits = ["apple", "banana", "cherry", "orange"]
mixed = [28, 32, True, "banana", [1,2]]
print(numbers)
print(fruits)
print(mixed)

#------------------------------------------------------------

# Accessing list elements
a = numbers[0]
print(a)
a = fruits[1]
print(a)
a = mixed[4]
print(a)
a = mixed[4][1]
print(a)

# Negative indices
a = numbers[-1]
print(a)
a = fruits[-2]
print(a)

# Length
print(len(numbers))
# print(fruits[len(fruits)]) # -- error
print(fruits[len(fruits)-1])
#-------------------------------------------

# List update
numbers[0] = 100
print(numbers)
fruits[1] = "mango"
print(fruits)
mixed[-1] = "apple"
print(mixed)
#----------------------------------------------

# List slicing
print(numbers[1:3])
print(numbers[1:])
print(numbers[:3])
print(numbers[:])
print(numbers[-3:-1])
print(numbers[-3:])
print(numbers[:-1])

# -----------------------------------------------------

# List methods

fruits.append("mango") # Adds to the end
print(fruits)
fruits.insert(2, "grapes") # Inserting without replacement
print(fruits)
fruits.remove("mango") # Removes the first occurence of the element
print(fruits)
fruits.pop() # Removes the last element
print(fruits)
fruits.pop(2) # Removes the element at the given index
print(fruits)

print(numbers)
numbers.sort() # Sorts the list in ascending order
print(numbers)
numbers.reverse() # Reverses the list
print(numbers)
numbers.clear() # Clears the list
print(numbers)

a = [1,2,4]
b = [4,5,6]
print(a,b)
a.extend(b) # Extends the list with the given list
print(a,b)
# -----------------------------------------------------

# List comprehension

# Suppose we want list of only those numbers which are even
numbers = [1,2,3,4,5,6,7,8,9,10]
even = [number for number in numbers if number%2 == 0]
print(numbers)
print(even)

# Suppose we want list of squares of all numbers
squares = [number**2 for number in numbers]
print(squares)

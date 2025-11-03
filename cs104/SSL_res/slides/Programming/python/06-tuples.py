# Tuples in Python
# Tuples are written with round brackets ()
# Tuples allow duplicate values
# Tuples are ordered/indexed starting from index 0
# True below is a boolean data type; as such list/tuple/set need not be of same data type

thistuple = ("apple", "banana", "cherry", "apple", 4.5, True, "cherry")
print("0. Original Tuple:", thistuple)
print("1. Length of Tuple:", len(thistuple))

# Tuple items are indexed, starting from 0 (first item)
print("2. Item at index 2:", thistuple[2])  # 'cherry'

# Negative indices start counting from the end of the tuple
print("3. Last item using negative index:", thistuple[-1])  # 'cherry'

# Slicing: Get a subtuple from index 3 to 6 (end index not included)
print("4. Sliced tuple from index 3 to 6:", thistuple[3:6])

# Tuples are immutable: Items cannot be changed directly
# Uncommenting the following line will throw an error
# thistuple[1] = "mango"  # This will cause a TypeError

# You can convert the tuple to a list, modify the list, and convert it back to a tuple
x = ("apple", "banana", "cherry")
y = list(x)  # Convert tuple to list
y[1] = "kiwi"  # Change the list
x = tuple(y)  # Convert back to tuple
print("5. Tuple after modifying:", x)

# You are allowed to add tuples to other tuples
thistuple = ("apple", "banana", "cherry")
y = ("orange",)
thistuple += y  # Adding a tuple to another tuple
print("6. Tuple after adding another tuple:", thistuple)

# You can delete entire tuples
thistuple = ("apple", "banana", "cherry")
del thistuple  # Deletes the tuple
# Uncommenting below will throw an error since thistuple is deleted
# print(thistuple)  # This will cause a NameError

# Using count() to count occurrences of a specific item
fruits = ("apple", "banana", "cherry", "apple", "banana")
apple_count = fruits.count("apple")
print("7. Count of 'apple' in the tuple:", apple_count)

# Using index() to find the index of a specific item
banana_index = fruits.index("banana")
print("8. Index of 'banana' in the tuple:", banana_index)

# Concatenating two tuples using the + operator (creates a new tuple)
tuple1 = ("a", "b", "c")
tuple2 = (1, 2, 3)
combined_tuple = tuple1 + tuple2
print("9. Combined tuple using + operator:", combined_tuple)

# Repeating a tuple using the * operator
repeated_tuple = tuple1 * 2  # Repeat the tuple twice
print("10. Repeated tuple:", repeated_tuple)

# Checking if an item exists in a tuple
exists = "apple" in fruits  # Returns True if 'apple' is in fruits
print("11. Is 'apple' in the tuple?", exists)

# Looping through a tuple
print("12. Looping through the tuple:")
for item in fruits:
    print(item)

# You can also unpack a tuple into variables
(a, b, c) = tuple1
print("13. Unpacked values:", a, b, c)

# Nested tuples: A tuple inside another tuple
nested_tuple = (("apple", "banana"), (1, 2, 3))
print("14. Nested tuple:", nested_tuple)



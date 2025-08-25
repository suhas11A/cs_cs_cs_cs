# Lists in Python
# Lists are enclosed in square brackets []
# Lists allow duplicate values
my_fruits = ["apple", "banana", "cherry", "apple", "organge", "mango"]

# Print the list and its length
print("0. Original List:", my_fruits)
print("1. Length of List:", len(my_fruits))

# List items are indexed, starting from 0 (first item)
print("2. Item at index 2:", my_fruits[2])  # 'cherry'

# Negative indices start counting from the end of the list
print("3. Last item using negative index:", my_fruits[-1])  # mango

# Slicing: Get a sublist from index 3 to 6 (end index not included)
print("4. Sliced list from index 3 to 6:", my_fruits[3:6])

# Lists are mutable: Items can be changed
# Here, replacing items at indices 1 and 2 (banana and cherry)
my_fruits = ["apple", "banana", "cherry"]
my_fruits[1:3] = ["mango", "watermelon"]
print("5. List after replacing items at indices 1 and 2:", my_fruits)

# Inserting more items at a specific index (index 1 in this case)
my_fruits = ["apple", "banana", "cherry"]
my_fruits[1:2] = ["blackcurrant", "watermelon"]
print("6. List after inserting more items at index 1:", my_fruits)

# Inserting fewer items than the specified range
my_fruits = ["apple", "banana", "cherry"]
my_fruits[1:3] = ["watermelon"]
print("7. List after inserting fewer items at indices 1-3:", my_fruits)

# Using insert() to add an item at a specific index
my_fruits = ["apple", "banana", "cherry"]
my_fruits.insert(2, "watermelon")  # Insert at index 2
my_fruits.append("orange")  # Append item at the end of the list
print("8. List after insert() and append():", my_fruits)

# Removing items from a list
my_fruits.remove("orange")  # Removes the first occurrence of 'orange'
my_fruits.pop(1)  # Removes the item at index 1
print("9. List after removing 'orange' and popping index 1:", my_fruits)

# pop() with no argument removes the last item
my_fruits.pop()
print("10. List after popping the last element:", my_fruits)

# Using del to remove an item at a specific index
del my_fruits[0]
print("11. List after deleting the first element:", my_fruits)

# Deleting the entire list
del my_fruits  # This will remove the entire list object


# Join two lists together using + operator (creates a new list)
list1 = ["a", "b", "c"]
list2 = [1, 2, 3]
combined_list = list1 + list2
print("12. Combined list using + operator:", combined_list)

# Using extend() to add elements from another list to the first list
list1.extend(list2)
print("13. List after extend() operation:", list1)

# Sorting a list
fruits_list = ["orange", "mango", "kiwi", "pineapple", "banana"]
fruits_list.sort()  # Sorts the list in ascending order
print("14. Sorted list in ascending order:", fruits_list)

# Sorting in descending order
fruits_list.sort(reverse=True)
print("15. Sorted list in descending order:", fruits_list)

# Reversing the order of a list
fruits_list.reverse()
print("16. List after reversing:", fruits_list)

# Copying a list
fruits_list_copy = fruits_list.copy()
print("17: Copy of the list:", fruits_list_copy)

# Using count() to count the occurrences of a specific item
fruits_with_multiple_apples = ["apple", "banana", "apple", "cherry", "apple"]
apple_count = fruits_with_multiple_apples.count("apple")
print("18. Count of 'apple' in the list:", apple_count)

# Using index() to find the index of a specific item
index_of_banana = fruits_with_multiple_apples.index("banana")
print("19. Index of 'banana' in the list:", index_of_banana)

# Using clear() to remove all items from the list
fruits_with_multiple_apples.clear()
print("20. List after clearing all items:", fruits_with_multiple_apples)



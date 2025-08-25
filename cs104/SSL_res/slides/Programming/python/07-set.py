# Set is written with curly brackets {}
# Duplicates are ignored
thisset = {"apple", "banana", "cherry", "apple", True, 23, 23.0}
print("0. Original Set:", thisset)
print("1. Length of Set:", len(thisset))
print("2. Type of thisset:", type(thisset))

# Set is unordered and unindexed
print("3. Unordered nature of Set:", thisset)

# Checking if an element exists in the set
print("4. Is 'banana' in the set?", "banana" in thisset)

# Adding elements to the set
thisset.add("orange")
print("5. After adding 'orange':", thisset)

# Adding elements from another set
thisset.update({"pineapple", "mango", "papaya"})
print("6. After updating with another set:", thisset)

# Adding elements from a list
thisset.update(["kiwi", "grape"])
print("7. After updating with a list:", thisset)

# Removing items using remove() (raises an error if item doesn't exist)
thisset.remove("banana")
print("8. After removing 'banana':", thisset)

# Removing items using discard() (does not raise an error if item doesn't exist)
thisset.discard("mango")
print("9. After discarding 'mango':", thisset)

# Removing an item using pop() (removes a random element)
popped_item = thisset.pop()
print("10. Popped item:", popped_item)
print("11. Set after pop():", thisset)

# Joining sets using union() (returns a new set)
set1 = {"a", "b", "c"}
set2 = {1, 2, 3}
set3 = set1.union(set2)
print("12. Union of sets:", set3)

# Joining sets using update() (modifies the first set)
set1.update(set2)
print("13. Updated set1 with set2:", set1)

# Finding the intersection (common elements) using intersection()
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
z = x.intersection(y)
print("14. Intersection of x and y:", z)

# Updating a set with the intersection
x.intersection_update(y)
print("15. x after intersection_update with y:", x)

# Finding the difference (items in x but not in y)
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
z = x.difference(y)
print("16. Difference of x - y:", z)

# Updating a set with the difference
x.difference_update(y)
print("17. x after difference_update with y:", x)

# Finding the symmetric difference (items in either set but not both)
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
#difference(y) returns a new set without modifying x
#difference_update(y) modifies x directly
z = x.symmetric_difference(y)
print("18. Symmetric difference of x and y:", z)

# Updating a set with the symmetric difference
#symmetric_difference(y) returns a new set without modifying x
#symmetric_difference_update(y) modifies x directly
x.symmetric_difference_update(y)
print("19. x after symmetric_difference_update with y:", x)

# Checking if a set is a subset of another
a = {"apple", "banana"}
b = {"apple", "banana", "cherry"}
print("20. Is a subset of b?", a.issubset(b))

# Checking if a set is a superset of another
print("21. Is b a superset of a?", b.issuperset(a))

# Checking if two sets are disjoint (no common elements)
c = {"google", "microsoft"}
print("22. Are b and c disjoint?", b.isdisjoint(c))

# Copying a set
copied_set = b.copy()
print("23. Copied set:", copied_set)

# Clearing all elements in a set
b.clear()
print("24. Set after clear():", b)

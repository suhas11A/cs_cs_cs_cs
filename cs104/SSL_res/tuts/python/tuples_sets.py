# Basic intro to tuples and sets

# Tuples are immutable
a = (1,2,3,1,2)
print(a)
print(type(a))

# Sets are mutable
b = {1,2,3}
print(b)
print(type(b))

# Modifying a tuple
# a[0] = 100 # -- error

# Accesing elements of a tuple
print(a[0])
print(a[-1])
print(a.count(1)) # Counting the number of occurences of an element
print(a.index(2)) # Finding the index of an element

# Modifying a set
b.add(4)
print(b)
b.remove(4)
print(b)

# Extracting unique elements from a list
a = [1,2,3,4,2,3]
print(a)
print(list(set(a)))

# Dictionaries from key:value pairs

# Creating an empty dictionary
empty_dict = {}
print(empty_dict)

# Create and print a dictionary
grades = {'Ana':'B', 'John':'A+', 'Denise':'A', 'Katy':'C'}
print(grades)
print(type(grades))

# Accessing elements
print(grades['John'])
print(grades.get('John'))

# Adding elements
grades['Sylvan'] = 'D'
print(grades)

# Modifying elements
grades['Ana'] = 'A'
print(grades)

# Removing elements
grades.pop('Ana')
print(grades)

# Iterating over a dictionary
for key in grades:
    print(key, grades[key])

# Iterating over keys
for key in grades.keys():
    print(key)

# Iterating over values
for value in grades.values():
    print(value)

# Iterating over key:value pairs
for key, value in grades.items():
    print(key, value)

# Checking if a key is in the dictionary
print('John' in grades)
print('Ana' in grades)

# Checking if a value is in the dictionary
print('A' in grades.values())
print('F' in grades.values())

# Length of a dictionary
print(len(grades))
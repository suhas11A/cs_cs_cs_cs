# Dictionaries are used to store data values in key-value pairs.
# A dictionary is a collection which is ordered (since Python 3.7), changeable, and does not allow duplicates.

# Dictionaries are written with curly brackets and have keys and values:
thisdict = {
    "brand": "Ford",
    "model": "Mustang",
    "year": 1964
}
print("0", thisdict)
print("1", thisdict["brand"])  # Accessing value using key
print("2", len(thisdict))  # Length of dictionary
print("3", type(thisdict))  # Type of thisdict

# Duplicate keys will overwrite existing values:
thisdict = {
    "brand": "Ford",
    "model": "Mustang",
    "year": 1964,
    "year": 2020  # Overwrites previous 'year' value
}
print("4", thisdict)

# Changing values
thisdict["year"] = 2023
thisdict.update({"year": 2024})  # Another way to update
print("5", thisdict)


# Accessing items safely
# you can access an item like this also : thisdict["model"]) but below is safer
x = thisdict.get("model")  # Recommended method (avoids KeyError if key doesn't exist)
print("6", x)

# Getting all keys, values, and key-value pairs
keys = thisdict.keys()
values = thisdict.values()
items = thisdict.items()
print("7", keys)
print("8", values)
print("9", items)

# Checking if a key exists
if "model" in thisdict:
    print("10 Yes, 'model' is a key in thisdict")

# Adding items
thisdict["color"] = "white"
thisdict.update({"gear": "auto"})  # Another way to add/update
print("11", thisdict)

# Removing items
thisdict.pop("model")  # Removes a specific key-value pair
thisdict.popitem()  # Removes the last inserted key-value pair
print("12", thisdict)

# Deleting and clearing
# del thisdict["brand"]  # Uncomment to remove a specific key
# del thisdict  # Uncomment to delete the entire dictionary
thisdict.clear()  # Empties dictionary but keeps it defined
print("13", thisdict)

# Copying a dictionary
thisdict = {"brand": "Ford", "model": "Mustang", "year": 2024}
mydict = thisdict.copy()
print("14", mydict)

# Nested dictionaries
child1 = {"name": "Ravi", "year": 2004}
child2 = {"name": "Rekha", "year": 2007}
child3 = {"name": "Ranjith", "year": 2011}

myfamily = {"child1": child1, "child2": child2, "child3": child3}
print("15", myfamily)

# Looping through a dictionary
for key in thisdict:
    print("16 Key:", key, "Value:", thisdict[key])

for key, value in thisdict.items():
    print("17 Key-Value Pair:", key, "=>", value)


# Merging dictionaries (Python 3.9+)
dict1 = {"a": 1, "b": 2}
dict2 = {"b": 3, "c": 4}
merged_dict = dict1 | dict2  # Merges two dictionaries, second dict's values take precedence
print("19 Merged Dictionary:", merged_dict)

# Using setdefault (returns value if exists, else sets and returns default)
thisdict.setdefault("fuel", "Petrol")
print("20 After setdefault:", thisdict)

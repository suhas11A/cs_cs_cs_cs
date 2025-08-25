# String assignment
a = "hello"

# Multiline string assignment using triple quotes
a = """Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua."""

# Strings as arrays (indexing and slicing)
print(a)  # Print the entire string
print(a[1])  # Access the second character (index 1)
print(len(a))  # Length of the string
print(a[2:5])  # Slice from index 2 to 4 (5 is not included)
print(a[:5])  # Slice from the start to index 4
print(a[120:])  # Slice from index 120 to the end

# Negative indices: count from the end of the string
print(a[-5:-1])  # Slice from the fifth last character to the second last character

# string operators
print("sit" in a)  # Check if 'sit' exists in the string
print("dolor" not in a)  # Check if 'dolor' does not exist in the string

# Concatenation using '+'
string1 = "Hello"
string2 = "World"
result_concat = string1 + " " + string2  # Concatenating with a space in between
print("Concatenation result:", result_concat)

# Repetition using '*'
string3 = "Hello"
result_repetition = string3 * 3  # Repeating the string 3 times
print("Repetition result:", result_repetition)


# Built-in methods on strings
a = " hello world !!!   "
print(a.upper())  # Convert the string to uppercase
print(a.strip())  # Remove spaces at the beginning and end of the string
print(a.replace("l", "i"))  # Replace all occurrences of 'l' with 'i'


# String formatting using f-string; notice I have assigned f" to a variable and then printed that
quantity = 3
itemno = 567
price = 49.95
myorder = f"I want {quantity} pieces of item {itemno} for {price} dollars."
print(myorder)
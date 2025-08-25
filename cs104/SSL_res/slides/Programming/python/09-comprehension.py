# 1. Basic List Comprehension
# Create a list of squares of numbers from 0 to 4
squares = [x**2 for x in range(5)]
print("Squares:", squares)  # Output: [0, 1, 4, 9, 16]

# 2. List Comprehension with Condition (Filtering Even Numbers)
# Create a list of even numbers from 0 to 9
even_numbers = [x for x in range(10) if x % 2 == 0]
print("Even Numbers:", even_numbers)  # Output: [0, 2, 4, 6, 8]

# 3. List Comprehension with if-else Condition
# Create a list where each number is labeled as 'Even' or 'Odd'
#The structure for the conditional expression (or ternary operator) in Python looks like this:
# <expression_if_true> if <condition> else <expression_if_false>
even_odd_labels = ['Even' if x % 2 == 0 else 'Odd' for x in range(10)]
print("Even or Odd Labels:", even_odd_labels)  
# Output: ['Even', 'Odd', 'Even', 'Odd', 'Even', 'Odd', 'Even', 'Odd', 'Even', 'Odd']

# 4. Nested List Comprehension (Flatten a 2D List)
# Flatten a 2D list (list of lists)
matrix = [[1, 2], [3, 4], [5, 6]]
flattened = [item for sublist in matrix for item in sublist]
print("Flattened List:", flattened)  # Output: [1, 2, 3, 4, 5, 6]

# 5. Combining Operations: Mathematical Operations
# Create a list of cubes of numbers from 0 to 4
cubes = [x**3 for x in range(5)]
print("Cubes:", cubes)  # Output: [0, 1, 8, 27, 64]

# 6. Combining Operations: String Manipulation
# Convert all strings in a list to uppercase
words = ["hello", "world", "hi"]
upper_words = [word.upper() for word in words]
print("Uppercase Words:", upper_words)  # Output: ['HELLO', 'WORLD', 'HI']

# 7. Combining Operations: String Manipulation with Condition
# Convert only words longer than 4 characters to uppercase
#The structure for the conditional expression (or ternary operator) in Python looks like this:
# <expression_if_true> if <condition> else <expression_if_false>
modified_words = [word.upper() if len(word) > 4 else word for word in words]
print("Modified Words:", modified_words)  # Output: ['HELLO', 'WORLD', 'hi']

# 8. Nested List Comprehension with Condition (Flatten a 2D list and filter even numbers)
# Flatten a 2D list and keep only even numbers
matrix_2 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
even_flattened = [item for sublist in matrix_2 for item in sublist if item % 2 == 0]
print("Flattened Even Numbers:", even_flattened)  # Output: [2, 4, 6, 8]

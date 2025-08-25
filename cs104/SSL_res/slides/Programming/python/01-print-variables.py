########### Commenting in Python ##############
# Single-line comments use the '#' symbol

# Multi-line comments can be written using multiple '#' symbols
# or using triple quotes (""" or ''').

"""
This is a multi-line comment
that can span multiple lines.
Useful for documentation.
"""

################ Printing and Variables ###############
# print() function prints output to the console
print("Hello, World!")

# Variable assignment (no explicit declaration needed)
x = 4       # x is an integer
y = "hello" # y is a string
x = "world" # x is now a string (dynamic typing)
z = 4.5     # z is a float
c = 2 + 1j  # c is a complex number
is_valid = True # Boolean value

# Printing multiple values (default space separator)
print(y, x)
print(c)

# Getting the type of a variable
print(type(x))
print(type(z))
print(type(is_valid))

# Type casting
x = str(3)    # Converts to string '3'
y = int(3)    # Converts to integer 3
z = float(3)  # Converts to float 3.0

# Case sensitivity in variables
Var = 100
var = 200
print(Var,var)  # Different variables

## Assigning multiple values to multiple variables
# Space at the end of the fruit is for readability
x, y, z = "Orange ", "Banana ", "Cherry "
print(x, y, z)
print(x + y + z)  # '+' concatenates strings

# '+' behaves differently for numbers
x = 5
y = 10
print(x + y)  # Addition for integers


# Custom separators in print
a, b, c = 12, 12, 2022
print(a, b, c, sep="-")  # Output: 12-12-2022

# Custom end character in print (prevents newline, replaces with '@')
print('09', '12', '2016', sep='-', end='@')  # Output: 09-12-2016@
#explicitly print a new line
print()

############### Formatted Printing with f-strings ##################
# f-strings allow inline variable formatting and expression evaluation
name = 'Ravi'
age = 23
print("Hello, My name is", name, "and I'm", age, "years old.") # a bit convoluted
print(f"Hello, My name is {name} and I'm {age} years old.") #simpler

# Number formatting (rounding float values)
x = 20.123
print(f"{x:.1f}")  # Prints 20.1 (1 decimal place)

# Expressions inside f-strings
print(f"Next year, I will be {age + 1} years old.")

# Formatting large numbers with comma separator
large_number = 1234567
print(f"Comma-separated: {large_number:,}")

# Function calls inside f-strings; functions will be covered later
def square(n):
    return n * n
num = 4
print(f"The square of {num} is {square(num)}")

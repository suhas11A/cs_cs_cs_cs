# Function with Default Parameters
def greet_with_default(name="Guest"):
    """Function with a default parameter."""
    print(f"1. Hello, {name}!")
greet_with_default()  # Output: Hello, Guest!
greet_with_default("Bobby")  # Output: Hello, Bobby!

# This function has 2 arguments
def greet_two_args(fname, lname):
  print(f"2. Hello {fname} {lname}")
greet_two_args("Suraj", "Singh")

# Function with *args (Non-Keyword Arguments)
def add_numbers(*args):
    """Function that takes multiple numbers and returns their sum."""
    return sum(args)

print(f"3. Sum: {add_numbers(1, 2, 3, 4, 5)}")  # Output: Sum: 15

# Another example:
def adder(*num):
    sum = 0   
    for n in num:
        sum = sum + n
    print(f"4. Sum: {sum}")
adder(3,5)
adder(1,2,3,5,6)

# Function with **kwargs (Keyword Arguments)
def display_info(**kwargs):
    """Function that takes named arguments and prints key-value pairs."""
    for key, value in kwargs.items():
        print(f"5. {key}: {value}")

display_info(name="Dev", age=30, city="New Delhi")
# Output:
# name: Dev
# age: 30
# city: New Delhi

# Function with *args and **kwargs Together
def mix_args_kwargs(*args, **kwargs):
    """Function that takes both positional and keyword arguments."""
    print(f"6. Positional arguments: {args}")
    print(f"7. Keyword arguments: {kwargs}")

mix_args_kwargs(1, 2, 3, name="Dravid", age=25)
# Output:
# Positional arguments: (1, 2, 3)
# Keyword arguments: {'name': 'Dravid', 'age': 25}

# Function without * (expects a list as a single argument)
def my_function(food):
    """
    This function takes a single argument (expected to be a list) and prints its elements.
    """
    print(f"8. Data type of food: {type(food)}")  # Will always be <class 'list'>
    for x in food:
        print(f"9. {x}")

# Function with * (expects multiple arguments, treated as a tuple)
def my_function_varargs(*food):
    """
    This function takes multiple arguments (variable-length arguments) and prints them.
    """
    print(f"10. Data type of food: {type(food)}")  # Will always be <class 'tuple'>
    for x in food:
        print(f"11. {x}")

# Creating a list of fruits
fruits = ["apple", "banana", "cherry"]

print("12. Passing list directly:")
my_function(fruits)  # Passes the whole list as a single argument
print("\n13. Unpacking list elements as separate arguments:")
my_function_varargs(fruits)  # does not unpack the list
my_function_varargs(*fruits)  # Unpacks the list, passing elements separately

# Another example
def process_numbers(*args):
    """Function that accepts numbers and returns a sorted list."""
    return sorted(args)
print(f"14. Sorted Numbers: {process_numbers(10, 5, 3, 8, 2)}")  
# Output: Sorted Numbers: [2, 3, 5, 8, 10]

# Function with return value
def my_function(x):
  return 5 * x
print(f"15. {my_function(3)}")
print(f"16. {my_function(5)}")

# Lambda function is a special type of function without the function name
# Syntax: lambda arguments : expression
print(f"17. {(lambda a, b: a * b)(3, 4)}")  # Output: 12

# Here the function is being assigned to a variable and you can use the variable as a function
x = lambda a, b: a * b
print(f"18. {x(5, 6)}")

# Another example
greet_user = lambda name : print(f"19. Hey there, {name}")
# lambda call
greet_user('Suraj')
# Notice that greet_user is a function; hence you could call it with argument Suraj
print(f"20. {type(greet_user)}")

# The power of lambda is better shown when you use them as an anonymous function inside another function.
# Lambda functions are often used when you need a simple function for a short period of time, 
# such as when passing a function as an argument to another function

def myfunc(n):
  return lambda a : a * n
# mydoubler and mytripler are functions!
# When myfunc(2) is called, it returns a lambda function that multiplies the function's argument a by 2. 
# This function is assigned to the variable mydoubler
mydoubler = myfunc(2)
mytripler = myfunc(3)
print(f"21. {mydoubler(11)}")
print(f"22. {mytripler(9)}")

# Using Lambda with sorted() for Custom Sorting
# students is a list of tuples
students = [("Alia", 25), ("Bobby", 22), ("Chand", 27)]
# x[1] refers to second element of the tuple; key is being assigned this function
sorted_students = sorted(students, key=lambda x: x[1])
print(f"23. Sorted Students by Age: {sorted_students}")
# Output: Sorted Students by Age: [('Bobby', 22), ('Alia', 25), ('Chand', 27)]

#################### Global vs Local Variables ####################
# Python allows defining global and local variables
x = "awesome"  # Global variable

def myfunc():
    x = "fantastic"  # Local variable
    print(f"24. Python is {x}")

myfunc()
print(f"25. Python is {x}")  # Uses global x

# Using 'global' keyword to modify global variables
x = "awesome"

def myfunc():
    global x
    x = "fantastic"  # Modifies global x

myfunc()
print(f"26. Python is {x}")  # Now x is "fantastic"

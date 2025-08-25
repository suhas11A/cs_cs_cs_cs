# Importing the custom module
import mymodule

# Importing built-in modules
import os
import datetime
import math
import re
import sys
import requests  # Third-party package (install using "pip install requests")

# 1. Example of using the custom module
print("1. Greeting from custom module:")
mymodule.greet_with_default("Anita")
print()

# 2. Example of using built-in modules
print("2. Built-in Modules:")
print("  a) Current Working Directory:", os.getcwd())

# datetime.datetime means the datetime class inside the datetime module. now() fetches the current date and time
print("  b) Current Date and Time:", datetime.datetime.now())
print("  c) Square root of 16:", math.sqrt(16))
print()

# 3. Example of using third-party packages
print("3. Third-party Package Example - JSON data from API:")
response = requests.get("https://jsonplaceholder.typicode.com/todos/1")
print(response.json())
print()

# 4. Regular Expressions Example
print("4. Regular Expressions:")
txt = "The rain in Spain"

# Check if the string starts with 'The' and ends with 'Spain'
x = re.search("^The.*Spain$", txt)
# When you print x, it shows a <re.Match object> i.e. x is a match object returned by the re module.
#span=(0, 17): Indicates the start and end indices of the match within the original string. 
#In this case, the match starts at index 0 and ends at index 17 (exclusive)
# match='The rain in Spain': Shows the actual matched substring, which is "The rain in Spain".
print("  a) Does the text match the pattern?:", x, bool(x))

# Splitting the string using space as delimiter
x = re.split("\s", txt)
print("  b) Split words:", x)
print()

# 5. Using sys module for command-line arguments
print("5. Command-line Arguments:")
print("  a) Program Name:", sys.argv[0])

# Ensure correct number of arguments before accessing them
if len(sys.argv) > 3:
    print("  b) arg1:", sys.argv[1])
    print("  c) arg2:", sys.argv[2])
    print("  d) arg3:", sys.argv[3])
else:
    print("  b) Not enough command-line arguments provided.")

print("  e) Total Number of Arguments:", len(sys.argv))
print("  f) All Arguments:", sys.argv)

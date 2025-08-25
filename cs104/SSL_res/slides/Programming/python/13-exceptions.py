# Basic try-except block
#enter 0 or some string and check
try:
    num = int(input("Enter a number: "))  # May raise ValueError
    result = 10 / num  # May raise ZeroDivisionError
    print("Result:", result)
except ZeroDivisionError:
    print("You cannot divide by zero!")
except ValueError:
    print("Invalid input! Please enter a valid number.")

# File handling with exception handling
try:
    file = open("file.txt", "r")  # May raise FileNotFoundError
    content = file.read()
    print("File content:\n", content)
except FileNotFoundError:
    print("File not found! Please check the filename.")
finally:
    print("Executing cleanup...")
    file.close()  # Ensures the file is closed properly

# Example of a generic exception handler
# Exception is the base class for all built-in exceptions, so it catches any kind of error
# as e stores the exception object in e, which is then printed

try:
    lst = [1, 2, 3]
    print(lst[5])  # IndexError
except Exception as e:
    print("An error occurred:", e)

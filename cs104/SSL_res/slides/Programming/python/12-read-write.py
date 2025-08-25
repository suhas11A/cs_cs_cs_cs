# File Reading and Writing

# File Reading - Read line by line directly (manually open and close)
file = open("file.txt", "r")
print("\nReading file line by line")
for line in file:
    print(line, end="")
file.close()


# Create or overwrite a file and write data using "with"
#with automatically closes file; less Error-Prone
#file is a variable here, like earlier
with open("output.txt", "w") as file:
    file.write("This is a line in the file.\n")
    file.write("This is another line in the file.\n")
    
# Append to an existing file; notice opened with a
with open("output.txt", "a") as file:
    file.write("This is an appended line.\n")

# Read the file's contents using 'with' statement, notice file was not closed above
with open("output.txt", "r") as file:
    content = file.read()
    print(content)

# File Reading - Read line by line using 'with' statement
with open("output.txt", "r") as file:
    print("\nReading file line by line:")
    for line in file:
        print(line, end="")

# File Reading - Read line by line using 'with' statement
with open("output.txt", "r") as file:
    print("\nReading file line by line:")
    line = file.readline()  # Read the first line
    while line:
        print(line, end="")
        line = file.readline()  # Read the next line

# Standard Input (stdin) using input function
user_input = input("\nPlease enter your name: ")
#This prints to standard out by default
print(f"Hello, {user_input}! Welcome to the Python script.")


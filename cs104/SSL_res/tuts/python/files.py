'''
  Handling files
  Here we will learn how to open, read and write to files

  Open a file
  The key function for working with files in Python is the open() function.
  The open() function takes two parameters; filename, and mode.
  There are four different methods (modes) for opening a file:
  "r" - Read - Default value. Opens a file for reading, error if the file does not exist
  "a" - Append - Opens a file for appending, creates the file if it does not exist
  "w" - Write - Opens a file for writing, creates the file if it does not exist
  "x" - Create - Creates the specified file, returns an error if the file exists
  In addition you can specify if the file should be handled as binary or text mode
  "t" - Text - Default value. Text mode
  "b" - Binary - Binary mode (e.g. images)
  Syntax
  To open a file for reading it is enough to specify the name of the file:
'''

# By default, open assumes read mode
f = open("demofile.txt")
print(f.read()) # read the entire file
f.close() # close the file
print("--------------------------------------------------")

# another way to open a file
with open("demofile.txt") as f:
  print(f.read())
print("--------------------------------------------------")

# Reading line by line
with open("demofile.txt") as f:
  print(f.readline()) # read the first line
  print(f.readline()) # read the second line
  for line in f: # read the rest of the lines
    print(line)

print("--------------------------------------------------")

# open a file in write mode, if not present, creates a new file
with open("newfile.txt", "w") as f:
  f.write("Hello World")

with open("newfile.txt") as f:
  print(f.read())
print("--------------------------------------------------")

# open a file in write mode,
with open("newfile.txt", "w") as f:
  f.write("IITBombay CSE") # this overqrites the file

with open("newfile.txt") as f:
  print(f.read())
print("--------------------------------------------------")

# open a file in append mode
with open("newfile.txt", "a") as f:
  f.write("\nHello World") # this appends to the file

with open("newfile.txt") as f:
  print(f.read())
print("--------------------------------------------------")


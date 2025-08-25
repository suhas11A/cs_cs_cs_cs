#!/bin/bash

# AWK script demonstrating various built-in functions

awk '
BEGIN {
    # --- String Functions ---
    
    # length(string)
    str = "Hello, AWK!"
    print "Length of string:", length(str)
    
    # substr(string, start, length)
    print "Substring (3rd to 7th):", substr(str, 3, 5)
    
    # index(string, substring)
    print "Index of AWK:", index(str, "AWK")
    
    # split(string, array, delimiter)
    split(str, arr, ",")
    print "Split string at , :", arr[1], arr[2]
    
    # tolower(string)
    print "Lowercase string:", tolower(str)
    
    # toupper(string)
    print "Uppercase string:", toupper(str)
    
    # sprintf(format, value, ...)
    # Similar to printf, except returns the formatted string as a value; does not print directly
    # You can store this string in a variable and then print the variable
    num = 123.456
    formatted = sprintf("Formatted number: %.2f", num)
    print formatted

    # --- Mathematical Functions ---
    
    # sqrt(x)
    num = 25
    print "Square root of", num, "is", sqrt(num)
    
    # int(x)
    float_num = 12.75
    print "Integer part of", float_num, "is", int(float_num)
    
    # sin(x), cos(x)
    angle = 45
    print "Sin(45):", sin(angle)
    print "Cos(45):", cos(angle)
    
    # --- Input/Output Functions ---
    
    # print
    print "This is printed using the print function"
    
    # printf(format, value, ...)
    printf "Formatted number with two decimal places: %.2f\n", num
    
    # getline (reads a line of input from a file, stdin, or from a string)
    print "Reading from standard input:"
    print "Enter your name:"
    # read a line from stdin represented by "-" and store in variable name
    getline name < "-";  
    print "Hello,", name
    #Another use
    while (getline line < "fruits") {
        print "Read line: " line
    }
    
    # --- Other Functions ---
    
    # system(command)
    print "Running system command (ls):"
    system("ls")
    
    # systime(), time since unix epoch
    print "Current Unix timestamp:", systime()
    #In a user friendly format via the strftime function
    print "Current date and time:", strftime("%Y-%m-%d %H:%M:%S", systime())

    # ENVIRON["var"]
    print "Value of PATH environment variable:", ENVIRON["PATH"]
}
' 

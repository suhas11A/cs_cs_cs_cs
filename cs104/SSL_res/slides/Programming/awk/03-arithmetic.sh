#!/bin/bash

# Arithmetic example using variables
awk 'BEGIN { 
    a = 50; 
    b = 20; 
    # Performing a basic arithmetic operation
    result = a + b * 5 + a / b; 
    print "Expression value (a + b * 5 + a / b) = ", result 
}' 

# Example with trigonometric operations and formatted output
awk 'BEGIN { 
    PI = 3.14159265; 
    a = 60; 
    # Calculating cosine of 60 degrees
    result = cos(a * PI / 180.0); 
    #Notice the use of printf; needs a newline at end for line break
    printf "The cosine of %f degrees is %f\n", a, result 
}'

# Create a sample file (students.tsv) for the demonstration; tsv is tab seperated
cat <<EOF > students.tsv
Anil 22 85
Bobby 23 92
Chandu 21 88
Darshan 25 75
EOF

# Arithmetic operation involving addition and multiplication on a file
awk '{
    # Multiply the second field by 2 and add the first field
    result = $1 + $2 * 2;
    print "Sum of first field + second field * 2 = ", result
}' students.tsv

# Cleanup: Remove the sample file
rm students.tsv

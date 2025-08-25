#!/bin/bash

# Create a sample CSV file
cat <<EOF > sample.csv
Amit,30,Engineer
Priya,25,Doctor
Raj,40,Teacher
Neha,35,Architect
EOF

echo "Original CSV File:"
cat sample.csv
echo ""

# AWK script to perform various operations
awk '
BEGIN {
    # Initialize variables
    FS = ",";    # Field separator is a comma
    OFS = "\t";  # Output field separator is a tab
    RS = "\n";   # Input record separator (default is newline)
    ORS = "\n";  # Output record separator (default is newline)
    
    # Print header
    print "Performing operations on CSV file..."
}

{
    # String Concatenation
    full_description = $1 " is a " $3;  # Concatenate name and occupation
    print "Description:", full_description;
    
    # Relational Operation
    if ($2 > 30) {
        print $1 " is older than 30";
    } else {
        print $1 " is 30 or younger";
    }

    # String Matching
    if ($3 ~ /Doctor/) {
        print $1 " is a Doctor";
    } else {
        print $1 " is not a Doctor";
    }

    # Conditional operation (ternary operator)
    experience = ($2 >= 30) ? "Experienced" : "Less Experienced";  # Ternary operation
    print $1 " is " experience;
     
    # Modulus Operation
    if ($2 % 2 == 0) {
        print $1 ": age is even";
    } else {
        print $1 ": age is odd";
    }

    # Increment/Decrement Operator (Increment age by 1)
    $2++;  # Increment age by 1
    print $1 " new age after increment: ", $2;


    # Logical AND operator
    if ($2 >= 30 && $3 == "Engineer") {
        print $1 " is an Engineer and older than or equal to 30.";
    } else {
        print $1 " does not meet the Engineer and age condition.";
    }

    # Logical OR operator
    if ($2 <= 30 || $3 == "Doctor") {
        print $1 " is either 30 or younger, or a Doctor.";
    } else {
        print $1 " does not meet either condition (age <= 30 or Doctor).";
    }
}
' sample.csv

# Cleanup
rm sample.csv

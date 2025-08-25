#!/bin/bash

# Awk inside bash. To run, do below
# chmod +x 02-variables.sh
# ./02-variables.sh

# Create a sample CSV file
cat <<EOF > sample.csv
Amit,30,Engineer
Priya,25,Doctor
Raj,40,Teacher
Neha,35,Architect
EOF

# Output original CSV file content
echo "Original CSV File:"
cat sample.csv
echo ""

# AWK script to process the file

awk '
BEGIN {
    FS = ",";  # Input field separator is a comma
    OFS = "\t"; # Output field separator is a tab
    RS = "\n";  # Input record separator (default is newline)
    ORS = "\n"; # Output record separator (default is newline)
    
    print "Processing CSV file...\n";
}

{
    # Use comma to separate different expressions (fields, variables, etc.)
    # This prints the different expressions on the same line using output field separator (OFS)
    # Semicolon at end is not needed as such since the two statements are on separate lines; but good to use
    # Semicolon is often used in awk to separate multiple statements in the same line

    print "NR=" NR, "NF=" NF, "Record:", $0;
    print "Formatted Output:", $1, $2, $3;
}
' sample.csv

# Cleanup
rm sample.csv

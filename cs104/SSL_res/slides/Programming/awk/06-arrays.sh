#!/bin/bash

# AWK script to demonstrate associative arrays
awk '
BEGIN {
    # Declare an associative array with student names as keys and grades as values
    grades["Amit"] = 85;
    grades["Priya"] = 92;
    grades["Raj"] = 78;
    grades["Neha"] = 95;

    # Print the entire array; Notice that the order of printing not same as above
    print "Initial Student Grades:";
    for (name in grades) {
        print "Student:", name, "=> Grade:", grades[name];
    }

    # Update a students grade
    grades["Priya"] = 98;
    print "\nAfter Updating Grade:";
   
    for (name in grades) {
        print "Student:", name, "=> Grade:", grades[name];
    }

    # Delete a students record
    delete grades["Raj"];
    print "\nAfter Removing Record:";  # Same fix for the apostrophe
    
    for (name in grades) {
        print "Student:", name, "=> Grade:", grades[name];
    }

    # Array length (manual counting of elements)
    count = 0;
    for (name in grades) {
        count++;
    }
    
    print "\nTotal Students:", count;    
}
'


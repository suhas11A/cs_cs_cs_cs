#!/bin/bash

# Sample input data (comma-separated values)
echo "Amit,28,Engineer" > data.txt
echo "Priya,32,Doctor" >> data.txt
echo "Raj,17,Artist" >> data.txt

# Using the -F flag to set a comma as the field separator and -v to pass a variable
awk -F, -v min_age=25 '{ 
    if ($2 >= min_age) {
        print $1, "is a major,", $2, "years old, and is a/an", $3;
    }
}' data.txt

#Another example
awk -F, '{Grp[$8]++} END {for(g in Grp) print g, Grp[g]}' students.csv

#Convert command seperated to tab seperated withe extra formatting done by column
awk -F, '{OFS="\t"; $1=$1; print}' students.csv | column -t -s $'\t' > students.tsv


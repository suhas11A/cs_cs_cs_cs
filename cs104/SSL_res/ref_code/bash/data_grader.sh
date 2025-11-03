#!/bin/bash

read -r theline < $1
theline=$(echo "$theline" | tr -d '\r')
echo "${theline},grades" > ug23.csv
echo "${theline},grades" > ug24.csv

tail -n +2 $1 | grep -E "23[bB][0-9]{3}" > temp_ug23.csv
tail -n +2 $1 | grep -E "24[bB][0-9]{3}" > temp_ug24.csv

cat temp_ug23.csv | while read line; do
    line=$(echo "$line" | tr -d '\r')
    IFS=',' read -ra array <<< "$line"
    array[5]=$(echo "${array[5]}" | tr -d '[:space:]')
    if ((array[5]>85)); then
        echo "${line},AA" >> grades_ug23.csv
    elif ((array[5]>65)); then
        echo "${line},AB" >> grades_ug23.csv
    elif ((array[5]>45)); then
        echo "${line},BB" >> grades_ug23.csv
    elif ((array[5]>35)); then
        echo "${line},CC" >> grades_ug23.csv
    else
        echo "${line},F" >> grades_ug23.csv
    fi
done
rm temp_ug23.csv
cat grades_ug23.csv | sort -t "," -k 1,1 | sort -s -t "," -k 7,7 >> ug23.csv
rm grades_ug23.csv

cat temp_ug24.csv | while read line; do
    line=$(echo "$line" | tr -d '\r')
    IFS=',' read -ra array <<< "$line"
    array[5]=$(echo "${array[5]}" | tr -d '[:space:]')
    if ((array[5]>85)); then
        echo "${line},AA" >> grades_ug24.csv
    elif ((array[5]>65)); then
        echo "${line},AB" >> grades_ug24.csv
    elif ((array[5]>45)); then
        echo "${line},BB" >> grades_ug24.csv
    elif ((array[5]>35)); then
        echo "${line},CC" >> grades_ug24.csv
    else
        echo "${line},F" >> grades_ug24.csv
    fi
done
rm temp_ug24.csv
cat grades_ug24.csv | sort -t "," -k 1,1 | sort -s -t "," -k 7,7 >> ug24.csv
rm grades_ug24.csv
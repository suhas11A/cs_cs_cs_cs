#!/usr/bin/env bash

#For loop
echo -e "\n🔹 For Loop (Iterating Over a List of Strings)"
for fruit in apple banana cherry; do
  echo "Fruit: $fruit"
done

echo -e "\n🔹 For Loop (Iterating Over a Numeric Range)"
for i in {1..5}; do
  echo "Number: $i"
done

#for loop with conditional
echo -e "\n🔹 For Loop  with conditional"
for dir in code doc anotherdir 
do
	if [ -d "$dir" ]; then
		echo "$dir already exists"
	else
		mkdir "$dir"
	fi
done

#using command substitution
echo -e "\n🔹 For Loop (Iterating Over Command Output)"
for file in $(ls); do
  echo "File: $file"
done

#demo of break and continue in aloop
echo -e "\n🔹 For Loop with Break (Stopping at 3)"
for i in {1..5}; do
  if (( i == 3 )); then
    echo "Stopping at 3"
    break
  fi
  echo "Number: $i"
done

echo -e "\n🔹 For Loop with Continue (Skipping 3)"
for i in {1..5}; do
  if (( i == 3 )); then
    echo "Skipping 3"
    continue
  fi
  echo "Number: $i"
done


#While loop
echo -e "\n🔹 While Loop (Counting Up)"
count=1
while (( count <= 5 )); do
  echo "Count: $count"
  (( count++ ))
done

#Another while loop ; Notice use of [[ ]] and not (( )) since we are dealing with string operations
#${variable:offset} → Extracts a substring from variable, starting at offset
#${word:1} → Extract substring starting at index 1 which is "o"; same as removing first character
word="HELLO"
while [[ $word != "" ]]; do
    echo "$word"
    word=${word:1}  # Remove first character
done

#Until Loop
echo -e "\n🔹 Until Loop (Counting Up)"
count=1
until (( count > 5 )); do
  echo "Count: $count"
  (( count++ ))
done



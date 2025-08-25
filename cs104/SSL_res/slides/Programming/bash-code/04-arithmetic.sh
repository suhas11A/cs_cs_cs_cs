#!/bin/bash

#Cannot use expression directly, will be viewed as a string
echo 1 5*2+1 
num=5*2+1
echo 2 $num

#using let
let num=5*2+1
echo 3 $num
#a = 5  (Incorrect because Bash interprets a as a command, = as an argument, and 5 as another argument
#with let, "a = 5" is the argument to let; so inside the quotes spaces are ok
let "a = 5"
let "a++"
echo 4 $a


#Two formats, $((expression)) and $[expression]
echo 5 $[5*2+1] #avoid -- deprecated
echo 6 $((5*2+1)) 
a=10
b=2
result=$((a ** b))
echo 7 $result

#Bash does not support floating point arithmetic natively
echo 8 $((10 % 3))  # Output: 1
#floating point needs use of bc
echo 9 $((3/4)) #Output: 0
echo -n "10 "
echo "3/4" | bc -l #Output: .75000000000000000000
#above two lines can also be replaced like this via command substitution echo "10 $(echo "3/4" | bc -l)"
#example involving use of scale to reduce the precision to 5 digits
echo -n "11 "
echo "scale=5; sqrt(49)" | bc -l   # Output: 7.00000
#bc supports variables also; Variables persist within a single bc session but are not retained outside
echo -n "12 "
echo "a=10; b=3; a/b" | bc -l   # Output: 3.33333333333333333333
#supports conditional expressions
echo -n "13 "
echo "5 > 2" | bc    # Output: 1

#declare makes cariable result integer only
declare -i num
num=$((5/2+1))
echo 14 $num # Ouptput 3
#Any non-numeric value assigned to num will be ignored
num="hello"
echo 15 $num  # Output: 0


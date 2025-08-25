#!/bin/bash
#Press \U1F539 shows the blue diamond
echo -e " \n \U1F539 Arithmetic Operators"
a=10
b=3
echo "Addition: $((a + b))"
echo "Subtraction: $((a - b))"
echo "Multiplication: $((a * b))"
echo "Division (integer): $((a / b))"
echo "Modulus (remainder): $((a % b))"
echo "Exponentiation: $((a ** b))"
echo "Floating-point division using bc: $(echo "scale=2; $a / $b" | bc -l)"


echo -e "\n🔹 Comparison Operators"
#&& Runs if True, || Runs if False
[[ $a -eq $b ]] && echo "a is equal to b" || echo "a is not equal to b"
[[ $a -ne $b ]] && echo "a is not equal to b"
[[ $a -gt $b ]] && echo "a is greater than b"
[[ $a -lt $b ]] && echo "a is less than b"
[[ $a -ge 10 ]] && echo "a is greater than or equal to 10"
[[ $b -le 3 ]] && echo "b is less than or equal to 3"

echo -e "\n🔹 Logical Operators"
[[ $a -gt 5 && $b -lt 30 ]] && echo "Both conditions met (AND)"
[[ $a -gt 15 || $b -lt 30 ]] && echo "At least one condition met (OR)"
[[ ! $a -eq 10 ]] && echo "Negation: a is not 10" || echo "a is 10"

echo -e "\n🔹 String Operators"
str1="hello"
str2="world"
[[ $str1 = $str2 ]] && echo "Strings are equal" || echo "Strings are not equal"
[[ -z $str3 ]] && echo "String is empty"
[[ -n $str1 ]] && echo "String is not empty"

echo -e "\n🔹 File Test Operators"
touch tempfile.txt
[[ -e tempfile.txt ]] && echo "File exists"
[[ -f tempfile.txt ]] && echo "It is a regular file"
[[ -s tempfile.txt ]] && echo "File is not empty" || echo "File is empty"
[[ -r tempfile.txt ]] && echo "File is readable"
[[ -w tempfile.txt ]] && echo "File is writable"
rm tempfile.txt

echo -e "\n🔹 Assignment Operators"
#Use $((expr)) when you need to return a computed value to assign (e.g., y=$((x+2))).
#Use ((expr)) when you modify variables directly (e.g., ((x+=1))).
x=5
((x+=2))
echo "x += 2: $x"
((x-=3))
echo "x -= 3: $x"
((x*=5))
echo "x *= 5: $x"
((x/=2))
echo "x /= 2: $x"
((x%=3))
echo "x %= 3: $x"

echo -e "\n🔹 Bitwise Operators"
a=5  # 0101
b=3  # 0011
echo "AND: $((a & b))"  # 0001 = 1
echo "OR: $((a | b))"   # 0111 = 7
echo "XOR: $((a ^ b))"  # 0110 = 6
echo "NOT a: $((~a))"
echo "Right Shift: $((a >> 1))"
echo "Left Shift: $((a << 1))"

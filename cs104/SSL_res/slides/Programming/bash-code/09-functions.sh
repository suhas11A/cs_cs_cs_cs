#!/bin/bash

# First we will define functions and later we will call them

# Function expecting one argument ($1 refers to it)
greet() {
    echo "Hello, $1!"
}

# Function returning Value via echo
current_date() {
    echo "Today's date is $(date +"%Y-%m-%d")"
}

# Function using return (Exit Status); also expecting one argument i.e. $1
check_file() {
    if [[ -f "$1" ]]; then
        echo "File '$1' exists."
        return 0
    else
        echo "File '$1' does not exist."
        return 1
    fi
}


# Function with Loop;  also expecting one argument i.e. $1
countdown() {
    local i=$1
    while [[ $i -ge 0 ]]; do
        echo "Countdown: $i"
        ((i--))
    done
}

# Recursive Function (Factorial) also possible; expecting one argument i.e. $1
factorial() {
    if [[ $1 -le 1 ]]; then
        echo 1
    else
        local temp=$(( $1 - 1 ))
        local result=$(factorial "$temp")
        echo $(( $1 * result ))
    fi
}

# Now we will call above functions

greet "Alice"  # Function with arguments

today=$(current_date)  # Capture function output
echo "$today"

check_file "/etc/passwd"  # Checking file existence
if [[ $? -eq 0 ]]; then
    echo "File check passed!"
else
    echo "File check failed!"
fi

countdown 3  # Loop in function

factorial_result=$(factorial 5)  # Recursion example
echo "Factorial of 5 is: $factorial_result"


#Another example of functions with arguments
function bar {
  [[ $# -ne 0 ]] || { 
     echo "*** bar: must have at least 1 arg." 
     return 1
  }
  echo "$@" #prints the arguments
  # no explicit return; "return 0" is implicit
}


echo "calling bar with no arguments, it should fail"
if bar; then
  echo success: $?
else
  echo failure: $?
fi

#introducing an extra line via echo
echo
echo "calling bar with 3 arguments, it should succeed"
echo 'calling bar: bar  arg1 arg2 arg3'
if bar arg1 arg2 arg3; then
  echo success: $?
else
  echo failure: $?
fi



#!/bin/bash

x=10
# Basic if
if (( x > 5 )); then
  echo "1: x is greater than 5"
fi

# If-else 
if (( x % 2 == 0 )); then
  echo "2: x is even"
else
  echo "2: x is odd"
fi

# If-elif-else 
if (( x > 15 )); then
  echo "3: x is greater than 15"
elif (( x > 5 )); then
  echo "3: x is greater than 5 but less than or equal to 15"
else
  echo "3: x is less than or equal to 5"
fi


# String comparison with [[ ... ]] as opposed to using (( )) which is for arithmetic
name="Arun"
if [[ "$name" == "Sunita" ]]; then
  echo "4: Hello, Sunita!"
else
  echo "4: Hello, Stranger!"
fi


# Conditional involving commands (modernized with [[ ]] for string comparison)
if ls nonexistent_directory &>/dev/null; then
  echo "6: Directory exists!"
else
  echo "6: Error: Directory does not exist!"
fi


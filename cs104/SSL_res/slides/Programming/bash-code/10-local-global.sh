#!/bin/bash

# Global variable
message="Hello from global scope"

# Function using local variable
modify_message() {
    local message="Hello from inside function"
    echo "Inside function: $message"
}

echo "Before function call: $message"
modify_message
echo "After function call: $message"  # Global variable remains unchanged


#exporting a variable X, but not Y
#introducing an extra line via echo
echo
export X="hello"
Y=5
echo "X is $X, Y is $Y"
./var-demo-child.sh






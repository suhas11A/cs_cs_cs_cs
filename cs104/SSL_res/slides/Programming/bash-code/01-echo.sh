#!/bin/bash

echo "Hello, World!"

#ignores special characters
echo "Line1\nLine2\tTabbed"
#-e enable escape sequences, so newline and tab will be printed
echo -e "Line1\nLine2\tTabbed"

#Can print to files also
echo "Starting script..." >> debug.log

#printing in color
#\e[32m – ANSI Escape Code for Green Text; \e → Escape character; [ → Starts the ANSI sequence.
#32m → Sets the text color to green; 34m is blue, 31m is red etc
#\e[0m – Resets Formatting
echo -e "\e[32mSuccess: Task completed!\e[0m"
echo -e "\e[31mError: Something went wrong!\e[0m"

#How echo handles spaces
echo word1	     word2
echo "word1	     word2"


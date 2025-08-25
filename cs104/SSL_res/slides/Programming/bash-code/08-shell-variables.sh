#!/bin/bash
#Run this script as follows: bash 08-shell-variables.sh abc "de fg" hij
# Note it has 3 arguments; all are strings; the second argument is written within quotes due to space within
echo "Script name: $0"
echo "First argument: $1"
echo "Second argument: $2"
echo "Third argument: $3"
echo "Number of arguments: $#"
#\ is being used as an escape character i.e. not interpret $ as variable but to interpret as character to print
echo "All arguments separately (\$@): $@"
echo "All arguments as a single string (\$*): $*"


#Looping through the arguments to show the diff between $* and $@
echo "Printing \$* "
for i in $*
do
        echo i is: $i
done

echo "Printing \$@ "
for i in "$@"
do
        echo i is: $i
done


# Running a command to check exit status
ls "hello.c" 2>/dev/null
echo "ls hello.c exited with $?"

ls "non-existent-file" 2>/dev/null
echo "ls non-existent-file exited with $?"


# Process control variables
echo "Current shell PID: $$"
echo "My parent process id is $PPID"


# Last argument of the last command
echo "Last argument of the last command: $_"

# Running another command to show $_ updates
echo "Hello World"
echo "Now, last argument of the last command is: $_"

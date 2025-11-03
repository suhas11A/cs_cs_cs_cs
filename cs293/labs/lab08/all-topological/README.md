# Topological Sort

## Objective

In this lab problem, we will implement topological sort on a directed acyclic graph (DAG) and generate all possible topological orderings.

## Tasks
- Implement the function alltopologicalSort() in all-topological.cpp to enumerate all valid topological sorts of a given DAG.

- Handle cases where the graph contains cycles — if a cycle is detected, print -1.

- Apart from these also implement the other functions found in the TO-DO section of all-topological.h in all-topological.cpp


## Input & Output

The main.cpp handles all input and output operations. You can view the file to see how it calls various functions.

Input Format:
Line 1: v (number of vertices)
Line 2: e (number of edges)
next e lines: u v (two numbers representing the edge between vertex u and vertex v, which is directed from u to v)

Output:
all possible topological sortings where each line will have a topological sort order where elements are separated by space

Example: 
Input:
6
5
1 2
2 4
3 4
4 5
5 6

Output:  
1 2 3 4 5 6  
1 3 2 4 5 6  
3 1 2 4 5 6 


## Files to Edit (DO NOT MODIFY ANYTHING ELSE !!!!!)
1. all-topological.cpp
# Make Commands

```
make             # Build and Run Tests
make build       # Build
make runtests    # Run Tests
make clean       # Clean Temporary Files
```
Please read Makefile to understand the above commands!

# VS Code interface

You can open this folder in VS Code. The problem folder is configured 
to enable debugging.

After opening the folder, click on Run > Start Debugging or press F5.
This will run your program on input ./test/test1/input.txt.
You may place breakpoints to pause the program at any desired location.

You can modify "./.vscode/launch.json" to run any test of your choice.

In some labs, there may be multiple binaries, and you may need to modify 
the binary name in the ./.vscode/settings.json file.

```
    "problem": "<binary>",
```

# General Instructions

- Read all .h and .cpp files before starting.
- Do not include any additional header files.
- Do not modify files other than the specified files. Any other changes 
  will not be considered during evaluation.
- You are expected to submit an efficient implementation. Inefficient 
  solutions will lose marks.


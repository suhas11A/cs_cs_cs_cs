# Implement Kruskal algorithm for finding the MST.

You have to implement your code in kruskal.cpp only.
The kruskalMST function takes the graph and totalweight as argument. You have to update the total weight of the MST in the totalweight variable itself which main uses at the end to print it at the end of the output.The return type of kruskalMST is a vector of pairs which are basically the edges that will occur in the MST. You have to return the edges of the MST.

## Input Output format
The main.cpp handles all input and print the output. You can view the file to see how it calls various functions.

Input Format: Line 1: v (number of vertices) Line 2: e (number of edges) next e lines: u v w(three numbers representing the edge between vertex u and vertex v, which has a weight w) last line: startNode (the node at which we start building the MST)

Output: Lines containing edges of the MST in the format u-v. The last line contains the weight of the MST

Example: Input: 5 7 0 1 2 0 3 6 1 2 3 1 3 8 1 4 5 2 4 7 3 4 9 0

Output: 0-1 0-3 1-2 1-4 Weight of MST: 16

Note: If we have edges in the format u-v: - u is less than v - edges are ordered according to u - if u is same for two edges, we order them by v

In the above output you can see that when ordered by u both 0-3 and 0-1 will come before 1-2 and 1-4. Since there are two ties we order them according to v. So 0-1 comes first, then 0-3, then 1- and at last 1-4.
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


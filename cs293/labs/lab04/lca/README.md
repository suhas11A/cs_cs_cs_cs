# LCA

# Problem Description

Recall the definition of least common ancestor (LCA) from class and tutorial. 
Given a binary tree T and two nodes a and b, the LCA of a and b is the node v 
such that v is an ancestor of both a and b, and v is the lowest node with this property. 
For example, in the tree below, the LCA of nodes 4 and 5 is node 2, and the LCA of nodes 4 and 6 is node 1.
Tree:
    1
   / \
  2   3
 / \ / \
4  5 6  7

# YOUR TASK

0. We already discussed the algorithm to find LCA in tutorial.
1. Complete the function findlca(a, b) in lca.cpp that takes pointer to two nodes a and b, and returns the pointer to LCA node of a and b.
2. The given tree is not necessarily a binary search tree. You may assume that both a and b are in the same tree if they are not NULL.
3. You have been provided with 10 sample testcases. These testcases by no means cover all possible testcases. 
   You are encouraged to write your own testcases to test your code.
4. Check for all possible corner cases.
5. Note that there is no constraint on the number of nodes in the tree. 
6. To test your code, run the following commands:
    For auto-testing on given testcases:
    - make runtests
    For interactive testing:(look at what all interactive commands are allowed in main.cpp)
    - make interactive


# Files to Edit (DO NOT MODIFY ANYTHING ELSE)

DO NOT CHANGE ANYTHING IN FILES EXCEPT findlca.cpp AS WE WILL ONLY TAKE YOUR findlca.cpp FILE FOR EVALUATION.

# Input and Output

Note that in tests folder, each testcase input tree and 2 labels is present in input.txt. Last line of input.txt contains label of nodes a and b separated by space. 

Tree format and handling of tree is given tree_handling.txt

The expected output from each testcase is given in tests/test<i>/output.txt file. 


# Interactive mode

For interactive testing, you can create your own tree using interactive commands.
To create the tree, create file e.g. tree.txt and use the following commands:

LOAD tree.txt
PRINT
FINDLCA 2 3

Look at tree_handling.txt to understand the tree format.

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


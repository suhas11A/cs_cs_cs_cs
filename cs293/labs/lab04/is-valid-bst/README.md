# Valid BST

In this problem we will our task is to check whether a given binary tree is a valid Binary Search Tree or not.

Binary Tree: A tree where a node can have at most 2 children.

Binary Search Tree: A binary tree where the left child of a node is less than the node and right child is greater than the node.

Example:

Binary Tree:
                4
        3               1
    2       5       6       7

Valid BST:
                4
        3               6
    2       1       5       7
    
Invalid BST:
                4
        3               7
    2       1       5       6
    
    

# Problem Description

In this exercise you will deal with a struct instead of plain numbers. You will be given a tree of employee nodes, where each employee will have the following fields: 

(name,department_name,id-in-department,Jobtitle,salary)

Your task is to compare the employee nodes and determine whether they follow the rules of BST.

For comparison we will use (department-name, id-in-department) together. It is guaranteed that the combination of (department_name, id-in-department) will be unique across all nodes.

First compare department-name of two nodes. This will be done using dictionary order. Compare id-in-department only if department_name is same.

Example: Consider the four nodes (a,HR,25,God,2000), (b,HR,10,Executive,1500) (c,IT,25,Junior,2000) (d,IT,45,Senior,2000) which forms the two trees below:

Tree 1:

            a
    b               c
null    null    null    d
    

Tree 2:
            
            a
    b               c
null    null    d       null
        

In this case, Tree 1 is a valid BST because, when 'a' is compared to 'b' since department-name is same (HR = HR) we compare id-in-department. Since, 25 > 10 'b' must be to the left of 'a'. When 'a' is compared to 'c', since IT > HR (dictionary order) we do not need to compare their ids and we keep 'c' to right of 'a'. Similarly for 'c' and 'd' since IT = IT, we compare ids and because 25 < 45 we put 'd' to right of 'c'.

Tree 2 is invalid because 'd' should be to the right of 'c'. 

# Even if one node is in wrong position the entire tree is invalid.


# Your Task

Complete the TODO parts in "employee.h" and "is-valid-bst.h".

In "employee.h", you will need to overload the operator to compare two employee nodes of a BST.

In "is-valid-bst.h" you will need to implement the function that goes through the entire tree and tells us whether it is a vaild BST or not.


# Files to Edit (DO NOT MODIFY ANYTHING ELSE)

1. employee.h
2. is-valid-bst.h

Make sure you make changes only in the TODO section of each file.

# Input and Output

You are provided with main.cpp which will take input from the tests and show the status of whether you have passed the tests case or not. There will be 14 total test cases.

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


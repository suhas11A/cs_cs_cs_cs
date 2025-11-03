# Graph DFS and Topological Sort

The adj in GraphNode is the adjacency list for each node. It contains pairs of values
which indicate the label of the node (first value) and the weight of the edge (second
value). The weights do not matter for this lab. All edges are directed.

Your task is to implement the function topoSort. This function should do a topological
sort of the given Graph. Topological ordering of a directed graph is a linear ordering
of its vertices such that for every directed edge u->v from vertex u to vertex v, u comes
before v in the ordering.

The output should be stored into the vector such that the main driver code function can
appropriately print it. You can use the dfs helper function that has been added to
the class, but you cannot remove the main topologicalSort function.
If a cycle is present then return empty vector.

To check your implementation, run "make". There could be more than one correct
topological sort outputs in general, but assume that the input will be such that
all adjacency lists will have labels in increasing order.

Input format:

N

E

e1 (in u,v pair)

e2

e3

e4

.
.
eE

Output format is the topologically sorted node labels.
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


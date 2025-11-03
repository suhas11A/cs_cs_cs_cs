# Graph BFS Comparison

## Objective

The objective of this lab problem is to **compare the implementation and performance of Breadth-First Search (BFS) on a undirected graph represented in two different ways**:
- Using an **Adjacency List** (`GraphA` class)
- Using an **Adjacency Matrix** (`GraphM` class)

By running BFS on both representations, you will observe differences in efficiency and traversal results.


## Tasks

- **Implement the Graph Classes**
  - Implement the functions of `GraphA` (found in compare.h) class in the compare.cpp file.
  - Implement the functions of `GraphM` (found in compare.h) class in the compare.cpp file.

- **Implement BFS Algorithm*
    - Takes a starting node and a reference to a vector order
    - Performs BFS, and adds the vertices to the 'order' vector in order of bfs traversal
    - Implement this for both types of Graphs.
    
- **Implement hasEdge Method*
    - Takes two vertices u,v
    - Returns true if there is an edge between u,v
    - Returns false if there is no edge between u,v


## Input & Output

The main.cpp handles all input and output operations. You can view the file to see how it calls various functions. Main will also display the time taken for bfs traversal for GraphA and GraphM along with time taken for each query in the terminal.

Input Format:
Line 1: v (number of vertices)
Line 2: e (number of edges)
next e lines: u v (two numbers representing the edge between vertex u and vertex v)
Line 2+e+1: source vertex
Line 2+e+2: m (number of queries)
next m lines: u v (two numbers that represents a query- Whether an edge exists between vertex u and vertex v?)

Output:
Line 1: vertices in bfs traversal order for Adjacency List (seprated by space)
Line 2: vertices in bfs traversal order for Adjacency Matrix (seprated by space)
next m lines: yes/no (If query has found the edge or not)

**There will be at least one vertex in the graph**

Example: 
Input:
4
4
1 2
2 3
1 4
3 4
1
3
1 2
1 3
2 4

Output: 
1 2 4 3
1 2 4 3
yes
no
no

Terminal Output (CAN GET DIFFERENT VALUES FOR TIME)
Testcase 2
Query (1,2): AdjList=69ns, AdjMatrix=50ns
Query (1,3): AdjList=176ns, AdjMatrix=153ns
Query (2,4): AdjList=71ns, AdjMatrix=47ns
BFS Adjacency List Time: 1451 ns
BFS Adjacency Matrix Time: 1086 ns
PASSED

**Note: The BFS traversal orders might be different for the two representations**

## Files to Edit (DO NOT MODIFY ANYTHING ELSE !!!!!)
1. compare.cpp

### Questions to Think About
1. Check Whether the results follow the theoretical limits of O(V+E) and O(V^2) for GraphA and GraphM respectively. If not try to justify the results.

2. From Test case 3 to 10 we have the following types of graphs
    - Small Graph (number of vertices in range 50-100) with low dense (Testcase 3), medium density (Testcase 4), and complete or almost complete graph (Testcase 5).
    - Medium Graph (number of vertices in range 900-1000) with low dense (Testcase 6), medium density (Testcase 7), and complete or almost complete graph (Testcase 8).
    - Large Graph (number of vertices in range 9000-10000) with low dense (Testcase 9), and medium density (Testcase 10).

In which cases do you think GraphA performs better, GraphM performs better, and both has equal performance? Density means how well the graph is connected. A complete graph will have an edge for every pair of vertex. Whereas a low dense graph will have edges only for a few pair. Think how number of edges (E) can be related to number of vertices (V) in O(V + E) and O(V^2).

3. The query times (time for hasEdge to complete execution) for GraphM should always be less than those of GraphA. Why do you think so? Is it the same case for you? (Think about the time complexity of hasEdge() function for both representations)

4. What about the space complexities of the two representations? Which is better?

### Bonus Questions
1. The bfs traversal orders of GraphA and GraphM graphs might not be the same even if we use the same graph and start from the same source. Why do you think so?

2. Can you define the functions of the both classes in such a way that bfs traversal order will always be the same no matter what given same graph and same source?
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


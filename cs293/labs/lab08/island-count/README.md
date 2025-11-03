## ISLAND COUNT

A template DFS class has been provided. It contains the adjacent neighbour vectors
(the 8 neighbours of a square at (a,b) in a grid are accessible using the indexing
(a+row[i],b+col[i])).

There are three template functions: validate and dfs. The idea for these functions is that they
are using two template types T1 and T2 which essentially represent information of the
puzzle.

For example, the first argument (T1 M) represents the 2D matrix that has been given as input, 
while the fourth argument (T2 v) is the visited boolean matrix representing whichever 
positions were visited (initially all false).

Both these arguments are passed by reference (indicated by the &) and so any changes
will reflect across any and all accesses to both these variables.

Your task is to complete the implementation of these two functions.
You need to add your implementation to the file [island-count.cpp](./island-count.cpp).

The key here is to break the given problem into conditions for validating a particular
position (i,j) and then using dfs recursively over all the neighbours of that position.
Use the validate function to check the invariant and then the dfs call
will follow. The changes to the matrix in dfs call should happen at the (i,j) position.

The details of the puzzles are as below:

Given a binary 2D matrix, find the number of islands. A group of connected 1s forms
an island. This is a variation of the standard problem: Counting the number of connected
components in an undirected graph.

Example:
Input: {
    {1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0}
}
Output: 4

To check your implementations, run "make"
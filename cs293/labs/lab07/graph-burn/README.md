

## Graph Burning Problem

### Overview

This project explores the **Graph Burning Problem**, a challenging NP-hard problem defined on undirected, unweighted graphs.

At each time step:

* You **ignite** one vertex (set it on fire).
* The fire **spreads** to all neighbors of already burning vertices in the next step.

The goal is to **burn all vertices** in as few time steps as possible.
That minimal number is called the **burning number** of the graph, ( b(G) ).

---

### Files

| File        | Purpose                                                 |
| ----------- | ------------------------------------------------------- |
| `main.cpp`  | Driver program (reads input, runs solver or verifier)   |
| `graph-burn.cpp` | BFS-based verifier + exact brute-force solver           |
| `graph-burn.h` | Header defining graph structure and function prototypes |

---

### Compilation

use `make` toh compile and run testcases

---

### Input Format

The **first line** of input decides the mode:

| Mode | Meaning                                                                |
| ---- | ---------------------------------------------------------------------- |
| `0`  | Solve mode — compute minimal burning number and schedule               |
| `1`  | Verify mode — check if a given schedule burns the graph within t steps |

---

#### **Mode 0 — Solve**

```
0
n m
u1 v1
u2 v2
...
um vm
```

* `n` = number of vertices (1-indexed)
* `m` = number of undirected edges
* Next `m` lines = edges `(u, v)`

The program outputs:

```
t
schedule[1] schedule[2] ... schedule[t]
```

Where:

* `t` = minimal burning number
* `schedule[i]` = vertex ignited at step `i-1`

---

#### **Mode 1 — Verify**

```
1
n m
u1 v1
...
um vm
t
schedule[1] schedule[2] ... schedule[t]
```

* Verifies if the given `schedule` burns the entire graph in ≤ `t` steps.
* Output:

  * `YES` → valid burning schedule
  * `NO` → schedule fails to burn all vertices

---

### Theory Recap

* **Graph burning number**, ( b(G) ), is the minimum `t` such that all nodes can be burned in `t` steps.
* NP-hard to compute for general graphs.
* Simple cases:

  | Graph Type          | ( b(G) ) |
  | ------------------- | -------- |
  | Path on n vertices  | ⌈√n⌉     |
  | Star with k leaves  | 2        |
  | Complete graph      | 1        |
  | Cycle on n vertices | ⌈√n⌉     |

---

### Limitations

* Brute-force solver is only feasible for small graphs (`n ≤ 8` or so).
* The verifier can handle large graphs efficiently (linear time).

---

### Suggested Experiments

Try experimenting with:

* **Disconnected graphs** → should output `NO` (not all nodes reachable).
* **Graphs with bridges** or **dense graphs** to observe how burning number changes.

---

### Notes

This problem is designed to:

* Demonstrate how **BFS** can be used to *verify* a burning schedule.
* Introduce an **NP-hard** graph problem beyond shortest paths.
* Provide a base for extending with **heuristics** or **approximation algorithms** later.

---
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


# Autocomplete (Simplified, Multi-Query, Lowercase Only)

Often users complain: "I type 'ap' and get random words instead of the ones I actually use most (like apple, apply)". So lets implement a lightweight simplified autocomplete quickly—no heavy trie today— but it MUST feel smart by prioritizing what people use most. So this sprint you ship a frequency‑aware, prefix-based suggestion engine: fast to implement, realistic enough to mirror what large search bars do at a tiny scale. This lab lets you build exactly that ranking core.

## Objective
Implement helper functions to build a simplified autocomplete feature (no trie needed) handling multiple prefix queries on a fixed lowercase dictionary.

---
## Problem Statement
You are given:
1. A dictionary of `n` distinct lowercase words (strings without spaces)
2. An integer frequency for each word (same order)
3. An integer `Q` (number of queries)
4. Then `Q` lines, each containing: `prefix K`

For each query, output up to `K` suggestions whose word starts with `prefix`, ranked by:
1. Higher frequency first
2. If frequencies tie, lexicographic order (ascending)
3. If still tied (should not with distinct words & distinct indices), smaller original index (deterministic)

If there are no matches OR `K == 0`, output a single dash `-` for that query.

---
## Input Format
```
n
w1 w2 ... wn
f1 f2 ... fn
Q
prefix1 K1
prefix2 K2
...
prefixQ KQ
```
- `n >= 0`
- All words are already lowercase. No case conversion required.
- Frequencies are non‑negative integers.
- `Q >= 1` (can be 0 only if explicitly stated, but assume ≥1 for tests)
- Each query line: a lowercase prefix (possibly empty) and integer `K >= 0`.

### Output Format
For each of the `Q` queries output exactly one line:
- Either `-` (no suggestions) OR the suggestions separated by single spaces.

---
## Your Task
In `autocomplete.cpp` implement these 3 functions (DO NOT modify other files):

1. `std::vector<int> computePrefixMatches(...)`
   - Return indices (0-based) of dictionary words that start with `prefix`.

2. `std::vector<int> pickTopK(...)`
   - From candidate indices choose ordering and truncate to `K`.
   - Ordering: higher `freq` first, then lexicographically smaller word.

3. `std::vector<std::string> autocomplete(...)`
   - Use previous helpers to produce final vector of suggestion strings.

NOTE : You may implement `void preprocessDictionary(...)` function to make the code more efficient

---
## Constraints & Notes
- All data lowercase, so no case-insensitive logic needed.
- If `K >= m`, return all matches in ranked order.
- Handle `K == 0` early (return empty -> prints `-`).

---
## Example
Input:
```
5
apple app apt bat apply
50 30 20 100 40
3
ap 3
a 2
bat 5
```
Processing query 1 (ap, K=3): matches apple(50) apply(40) app(30) apt(20) → top 3 → `apple apply app`
Query 2 (a, K=2): top 2 among same set → `apple apply`
Query 3 (bat, K=5): only `bat` → `bat`

Output:
```
apple apply app
apple apply
bat
```

---
## Provided Files
- `autocomplete.h` (declarations)
- `autocomplete.cpp` (YOU edit)
- `main.cpp` (driver supporting multiple queries) – do not edit
- `Makefile`
- `tests/` (multi-query cases)

Run tests:
```
make
```

---
## Edge Cases
- `n = 0` → all queries output `-` (unless `K = 0`, still `-`).
- `prefix` empty → treat as all words (rank whole dictionary then truncate to `K`).
- `K = 0` → output `-` without ranking.

---

#include "island-count.h"
// here T1 is a matrix (2D vector of int) and T2 is a matrix (2D vector of bool)


// TODO : validate
// check the indices and additional conditions after which you would use dfs
template <typename T1, typename T2> bool DFS::validate(T1& M, unsigned i, unsigned j, T2& v) {
  return false; // dummy return
}

// TODO : dfs
// modify the data structure (matrix M and/or v) as needed
// you can solve this without modifying M
// use the row and col vectors to access neighbors of (i,j)
// validate the neighbour before you use dfs
template <typename T1, typename T2> void DFS::dfs(T1& M, unsigned i, unsigned j, T2& v) {
  unsigned n = M.size();
  unsigned m = M[0].size();
  v[i][j] = true;
  std::vector<std::pair<int, int>> children;
  for (int k = 0;k<8;k++) {
    unsigned tempoi = i+row[k];
    unsigned tempoj = j+col[k];
    if (tempoi>=n || tempoi<0 || tempoj>=m || tempoj<0) continue;
    if (M[tempoi][tempoj]==1) children.push_back(std::make_pair(tempoi,tempoj));
  }
  for (auto papa : children) {
    if (!v[papa.first][papa.second]) dfs(M, papa.first, papa.second, v);
  }
  return;
}



// count islands
int countIslands(std::vector<std::vector<int>> M) {
  unsigned n = M.size();
  if (n==0) return 0;
  unsigned m = M[0].size();
  if (m==0) return 0;
  std::vector<std::vector<bool>> v(n, std::vector<bool>(m,false));
  int count = 0;
  DFS my_dfs;
  for (unsigned i =0;i<n*m;i++) {
    int temp_i = i/m; int temp_j = i%m;
    if (v[temp_i][temp_j]) continue;
    if (M[temp_i][temp_j]==1) {count++; my_dfs.dfs(M, temp_i, temp_j, v);}
  }
  return count;
}


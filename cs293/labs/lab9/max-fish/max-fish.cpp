#include "max-fish.h"

int A[4] = {0,0,-1,1};
int B[4] = {1,-1,0,0};

void bfs(vector<vector<int>> &grid, vector<vector<int>> &ccid, vector<vector<int>> &visited, int currid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(i,j));
    visited[i][j] = true;
    ccid[i][j] = currid;
    while (!q.empty()) {
        auto [curri, currj] = q.front(); q.pop();
        for (int k=0;k<4;k++) {
          int newrow = curri + A[k];
          int newcol = currj + B[k];
          if (newrow<0 || newrow>=m || newcol<0 || newcol>=n || grid[newrow][newcol]==0 || visited[newrow][newcol]) continue;
          q.push(make_pair(newrow,newcol));
          visited[newrow][newcol] = true;
          ccid[newrow][newcol] = currid;
        }
    }
}

// Write your code inside the findMaxFish function
int Solution::findMaxFish(vector<vector<int>> &grid) {
    int m = grid.size();
    if (!m) return 0;
    int n = grid[0].size();
    vector<vector<int>> ccid(m, vector<int> (n,0));
    vector<vector<int>> visited(m, vector<int> (n,false));
    int currid = 1;
    for (int i=0;i<m*n;i++) {
      int temprow = i/n;
      int tempcol = i%n;
      if (grid[temprow][tempcol] && !visited[temprow][tempcol]) {bfs(grid, ccid, visited, currid, temprow, tempcol); currid++;}
    }
    vector<int> nums(currid,0);
    for (int i=0;i<m*n;i++) {
      int temprow = i/n;
      int tempcol = i%n;
      nums[ccid[temprow][tempcol]]+=grid[temprow][tempcol];
    }
    int ans = 0;
    if (currid==1) return 0;
    for (int hehe=1;hehe<currid;hehe++) {
      ans = max(ans, nums[hehe]);
    }
    return ans;
}

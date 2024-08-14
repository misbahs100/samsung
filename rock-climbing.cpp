// ques: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing/problem

// idea: dfs

#include<bits/stdc++.h>
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

int n, m;
int grid[15][15];
bool isDestination;
bool vis[15][15];

void dfs(int row, int col, int l){
  // base cases: check boundary and visited
  if(row < 0 || row >= n || col < 0 || col >= m) return;
  if(vis[row][col]) return;
  
  vis[row][col] = true;
  
  if(grid[row][col] == 3){
    isDestination = true;
    return;
  }
  
  // check if we can climb to the right
  if(col + 1 < m && grid[row][col+1] != 0 && !vis[row][col+1])
    dfs(row, col+1, l);
  
  // check if we can climb to the left
  if(col - 1 >= 0 && grid[row][col-1] != 0 && !vis[row][col-1])
    dfs(row, col-1, l);
  
  // check if we can climb up and down: i.e., check from 1 to l
  for(int i=1; i<=l; ++i){
    // check for down
    if(row + i < n && grid[row+i][col] != 0 && !vis[row+i][col])
      dfs(row+i, col, l);
    
    // check for up
    if(row - i >= 0 && grid[row-i][col] != 0 && !vis[row-i][col])
      dfs(row-i, col, l);
  }
  
}


int main(){
  fast;
  
  cin >> n >> m;	// num_row, num_col
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      cin >> grid[i][j];
    }
  }
  
  // we have to check for every row(level) whether that row(level) contains number 3 (destination)
  for(int l=0; l<n; ++l){
    isDestination = false;
    memset(vis, false, sizeof(vis));
    dfs(n-1, 0, l);
    // params: row, col, level (since climbing starts from the bottom-left, so row & col is n-1 & 0)
    if(isDestination) {
      cout << l << endl;
      break;
    }
    
  }
  
  
  return 0;
}

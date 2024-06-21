// ques: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/aeroplane-bombing
// idea: dfs

#include <bits/stdc++.h>
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

int n;
int cs = 1;

int dfs(int row, int col, bool canBomb, vector<vector<int> > grid, int n){
  // base cases
  if(row < 0) return 0;
  if(grid[row][col] == 2) return 0;
  
  int ans = 0;
  if(grid[row][col] == 1) ans++;
  
  if(canBomb){
    // we will use the bomb (use copy of grid)
    vector<vector<int> > cpy = grid;
    // 1. make all 2 to 0 in the copy
    for(int i=max(row - 5, 0); i<row; ++i){
      for(int j=0; j<5; ++j){
        if(cpy[i][j] == 2) cpy[i][j] = 0;
      }
    }
    
    // 2. use copy of grid: move the spaceship to the right, left, at_place: ans1 = max(op1, op2, op3)+ans
    int opt1 = 0, opt2 = 0, opt3 = 0;
    if(col + 1 < 5) opt1 = dfs(row-1, col+1, false, cpy, n);
    if(col - 1 >= 0) opt2 = dfs(row-1, col-1, false, cpy, n);
    opt3 = dfs(row-1, col, false, cpy, n);
    int ans1 = max({opt1, opt2, opt3}) + ans;
    
    
    // we will not use the bomp (use the grid)
    // 3. use grid: move the spaceship to the right, left, at_place
    int opt1n = 0, opt2n = 0, opt3n = 0;
    if(col + 1 < 5) opt1n = dfs(row-1, col+1, true, grid, n);
    if(col - 1 >= 0) opt2n = dfs(row-1, col-1, true, grid, n);
    opt3n = dfs(row-1, col, true, grid, n);
    int ans2 = max({opt1n, opt2n, opt3n}) + ans;
    
    // 4. return max(ans1, ans2)
    return max(ans1, ans2);
  }
  else{
    // we will not use the bomp (use the grid)
    // same as above
    int opt1n = 0, opt2n = 0, opt3n = 0;
    if(col + 1 < 5) opt1n = dfs(row-1, col+1, false, grid, n);
    if(col - 1 >= 0) opt2n = dfs(row-1, col-1, false, grid, n);
    opt3n = dfs(row-1, col, false, grid, n);
    return max({opt1n, opt2n, opt3n}) + ans;
  }
  
}

void solve(){
  cin>>n;
  
  vector<vector<int> > grid(n+1, vector<int>(5, 0));
  for(int i=0; i<n; ++i)
    for(int j=0; j<5; ++j)
      cin>>grid[i][j];
  
  // the last row (control row)
  for(int j=0; j<5; ++j) 
    grid[n].push_back(0);
  
  cout << "#" << cs++ << " " << dfs(n, 2, true, grid, n) << endl;
  // params: row(we will go from last row to upper rows), col, canBomb, grid, total_rows
  
}

int main(){
  fast;
  
  ll t;
  cin>>t;
  while(t--){
    solve();
  }

  return 0;
}

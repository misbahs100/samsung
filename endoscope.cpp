// ques: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/endoscope

// approach: bfs

#include<bits/stdc++.h>
#define ll long long;
#define fast  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
using namespace std;


int n, m, r, c, l;
int a[100][100];
bool vis[100][100];
vector<pair<int, int> > dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // up, down, right, left

bool valid(int i, int j){
  return (i >= 0 && i < n && j >= 0 && j < m);
}

bool canUp(int type){
  return (type == 1 || type == 2 || type == 4 || type == 7);
}

bool canDown(int type){
  return (type == 1 || type == 2 || type == 5 || type == 6);
}

bool canRight(int type){
  return (type == 1 || type == 3 || type == 4 || type == 5);
}

bool canLeft(int type){
  return (type == 1 || type == 3 || type == 6 || type == 7);
}

int bfs(){
  // base case
  if(a[r][c] == 0) return 0;
  
  queue<pair<pair<int, int>, int> > q;
  // queue of {{curr_endoscope_x_pos, curr_endoscope_y_pos}, curr_len_of_endoscope}
  q.push({{r, c}, 1});
  
  vis[r][c] = true;
  
  int ans = 0;
  while(!q.empty()){
    pair<pair<int, int>, int> p = q.front();
    q.pop();
    int i = p.first.first;
    int j = p.first.second;
    int k = p.second;
    
    // if curr_len_of_endoscope doesn't overcome the actual len l, increase ans
    if(k > l) continue;
    ans++;
    
    // loop for 4 sides of a point: up, down, right, left. 
    // check which directions are suitable
    for(int d=0; d<4; ++d){
      int xi = i + dir[d].first;
      int xj = j + dir[d].second;
      
      if(valid(xi, xj) && a[xi][xj] != 0 && !vis[xi][xj]){
        if(d == 0 && canLeft(a[xi][xj]) && canRight(a[i][j])){
          vis[xi][xj] = true;
          q.push({{xi, xj}, k+1});
        }
        
        if(d == 1 && canRight(a[xi][xj]) && canLeft(a[i][j])){
          vis[xi][xj] = true;
          q.push({{xi, xj}, k+1});
        }
        
        if(d == 2 && canUp(a[xi][xj]) && canDown(a[i][j])){
          vis[xi][xj] = true;
          q.push({{xi, xj}, k+1});
        }
        
        if(d == 3 && canDown(a[xi][xj]) && canUp(a[i][j])){
          vis[xi][xj] = true;
          q.push({{xi, xj}, k+1});
        }
        
      }
    }
    
  }
  
  return ans;
  
}

void solve(){
  cin >> n >> m >> r >> c >> l;
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      vis[i][j] = false;
      cin >> a[i][j];
    }
  }
  
  cout << bfs() << endl;
}

int main(){
  fast;
  
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  
  
  return 0;
}


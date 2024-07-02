// ques: https://www.cnblogs.com/kingshow123/p/practicec1.html

// approach: bfs

#include <bits/stdc++.h>
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

int n, m;
int a[20][20];
bool vis[20][20];
vector<pair<int, int> > dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j){
  return (i >= 0 && i < n && j >= 0 && j < m);
}

int bfs(int sx, int sy){
  // base case
  if(a[sx][sy] == 0) return 0;
  
  int ans = -1;
  queue<pair<pair<int, int>, int> > q;
  // queue of {{row, col}, time}
  q.push({{sx, sy}, 1});
  vis[sx][sy] = true;
  
  while(!q.empty()){
    pair<pair<int, int>, int> p = q.front();
    q.pop();
    
    int i = p.first.first;
    int j = p.first. second;
    int c = p.second;   // c is time
    
    if(a[i][j] == 1) ans = max(ans, c);
    
    for(int d=0; d<4; ++d){
      int xi = i + dir[d].first;
      int xj = j + dir[d].second;
      
      if(valid(xi, xj) && a[xi][xj] == 1 && !vis[xi][xj]){
        vis[xi][xj] = true;
        q.push({{xi, xj}, c+1});
      }
    }
    
  }
  
  return ans;
  
}

void solve(){
  cin >> m >> n;
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      vis[i][j] = false;
      cin >> a[i][j];
    }
  }
  
  int sy, sx;
  cin >> sy >> sx;
  
  a[sx][sy] = 1;
  sx--;
  sy--;
  
  cout << bfs(sx, sy) << endl;
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

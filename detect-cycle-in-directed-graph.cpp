// ques: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/detect-cycle-in-directed-graph

// approach: dfs

#include<bits/stdc++.h>
#define ll long long;
#define fast  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
using namespace std;

int n, m;   // num_of_nodes, num_of_edges
const int mx = 1e5 + 5;
vector<int> adj[mx];  // size should be within [] while declaring a vector globally
int minSum = INT_MAX; // since we need to check for minimum sum of the cycle
bool vis[mx];
vector<int> ans;

int findSum(vector<int> v){
  int sum = 0;
  for(int x : v) sum += x;
  return sum;
}

void detectCycle(int node, vector<int> temp){
  vis[node] = true;
  temp.push_back(node);
  
  for(int neighbor : adj[node]){
    // if the neighbor is not visited, call recursion. otherwise check if the visited neighbor makes a cycle
    if(!vis[neighbor])
      detectCycle(neighbor, temp);
    else{
      // neighbor is already visited but not in the temp's front, i.e., not creating a cycle
      if(temp[0] != neighbor) continue;
      
      // otherwise, check the temp for minimum sum
      int sum = findSum(temp);
      if(sum < minSum){
        minSum = sum;
        ans = temp;
      }
    }
  }
  
  temp.pop_back();
  vis[node] = false;
}

int main(){
  fast;
  
  cin >> n >> m;
  while(m--){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  
  // check for every nodes (not edges) whether any cycle begins from that node
  for(int i=1; i<=n; ++i){
    memset(vis, false, sizeof(vis));
    detectCycle(i, {});
    // params: node, a vector where the nodes of probable_cycle will be stored
  }
  
  // sort and print
  sort(ans.begin(), ans.end());
  for(int x : ans){
    cout << x << " ";
  }
  
  
  return 0;
}

// ques: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/fisherman

// idea: normal way: nested loops

#include<bits/stdc++.h>
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;


int solve(int &n, int a[3], int b[3]){
  int ans = INT_MAX;
  for(int i = 1; i <= n - (b[0] + b[1] + b[2]) + 1; ++i){
    for(int j = i + b[0]; j <= n - (b[1] + b[2]) + 1; ++j){
      for(int k = j + b[1]; k <= n - (b[2]) + 1; ++k){
        int res = 0;
        for(int p = i; p < i + b[0]; ++p)
          res += (abs(a[0] - p) + 1);
        
        for(int p = j; p < j + b[1]; ++p)
          res += (abs(a[1] - p) + 1);
          
        for(int p = k; p < k + b[2]; ++p)
          res += (abs(a[2] - p) + 1);
        
        ans = min(ans, res);
      }
    }
  }
  
  return ans;
}

int main(){
  fast;
  
  int n;
  cin >> n;
  
  int a[3], b[3];
  
  for(int i=0; i<3; ++i) cin >> a[i];
  for(int i=0; i<3; ++i) cin >> b[i];
  
  cout << solve(n, a, b) << endl;
  
  return 0;
}

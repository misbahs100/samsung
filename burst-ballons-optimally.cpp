// ques: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1

// idea: dynamic programming

#include <bits/stdc++.h>
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

ll dp[105][105];

ll solve(ll i, ll j, vector<ll> &a, ll c){
  // base cases
  if(i > j) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  
  ll mx = INT_MIN;
  for(int p=i; p<=j; ++p){
    if(c == 1)
      mx = max(mx, solve(i, p-1, a, 1) + solve(p+1, j, a, 1) + (a[i-1] * a[j+1]));
    else
      mx = max(mx, solve(i, p-1, a, 1) + solve(p+1, j, a, 1) + a[p]);
  }
  
  return dp[i][j] = mx;
  
}

int main(){
  fast;
  
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];
  
  a.insert(a.begin(), 1);
  a.push_back(1);
  
  memset(dp, -1, sizeof(dp));
  
  cout << solve(1, n, a, 0) << endl;
  // params: i, j, &a, c
  
  return 0;
}

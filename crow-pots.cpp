/*
https://www.careercup.com/question?id=5166688897073152
http://forums.codeguru.com/showthread.php?560529-Core-Java-programming
https://codereview.stackexchange.com/questions/136165/the-thirsty-crow
*/

/*
There are N pots. Every pots has some water in it. They may be partially filled. 
Every pot is associated with overflow number O which tell how many minimum no. of stones required 
for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K 
pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.
Array of overflow no--. {1,...,On}
Number of pots--n
No of pots to overflow-- k
Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1). 
So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in 
pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.


input:
2	// num_of_test_cases
2 1	// n is num_of_pots, m is num_of_pots_to_be_overflowed
5 10	// o1, o2, ... ,on
2 1
65 69

output
#1 10
#2 69
*/

#include <bits/stdc++.h>
#define ll long long;
#define fast  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
using namespace std;

int n, m;
int a[1009];
int dp[1009][1009];
int ans;

void solve(){
  // modify the whole dp
  for(int i=1; i<=n; ++i){
    dp[i][1] = a[i] * (n - i + 1);
  }
  
  // nested for loops
  for(int i=n; i>0; --i){         // i = n to >0
    for(int j=2; j<=m; ++j){      // j = 2 to <=m
      for(int k=i+1; k<=n; ++k){  // k = i+1 to <=n
        dp[i][j] = min(dp[i][j], dp[k][j-1] + a[i] * (k - i));
      }
    }
  }
  
  for(int i=1; i<=n; ++i){
    ans = min(ans, dp[i][m]);
  }
  
  
  
  
}


int main(){
  fast;
  
  int t;
  cin >> t;
  for(int test_case=1; test_case<=t; test_case++){
    cin >> n >> m;  // n is num_of_pots, m is num_of_pots_to_be_overflowed
    for(int i = 1; i <= n; i++){
    		cin >> a[i];
    }
    
    memset(dp, INT_MAX, sizeof(dp));
    ans = INT_MAX;
    solve();
    
    cout<<'#'<<test_case<<" "<< ans << endl;
  }
  
  
  
  return 0;
  
}

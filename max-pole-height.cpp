/* ques: You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner 
standing on top of TWO PILLERS.
The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height
of the two pillars standing side by side, so that the pillars are of EQUAL HEIGHT and banner can be placed on top of it.
In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2.
In case, there is no combination possible, print 0.

INPUT :
1	// num of test cases
5	// num of total poles
1 2 3 4 6	
Output :
8


*/

// approach: backtracking

#include<bits/stdc++.h>
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;


int n;
int a[20];
bool vis[20];
int ans;

void back(int p1, int p2){
  // base case
  if(p1 == p2) ans = max(ans, p1);
  
  for(int i=0; i<n; ++i){
    if(!vis[i]){
      vis[i] = true;
      back(p1 + a[i], p2);
      back(p1, p2 + a[i]);
      vis[i] = false;
    }
  }
  
}

void solve(){
  cin >> n;
  for(int i=0; i<n; ++i){
    vis[i] = false;
    cin >> a[i];
  }
  
  ans = INT_MIN;  // have to declare the min value here, bcz there are multiple test cases
  back(0, 0);
  // params: pole_1_height, pole_2_height
  cout << ans << endl;
  
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

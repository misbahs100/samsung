/* ques:
A man has some camels with him.He has to take these camels to the opposite end. Each camel has some cost to go from one end to other.
-> While going to opposite end, he will take 2 camels along with him, the cost will be the maximum of the cost of both the camels.
-> On reaching opposite end, he will take one camel from opposite end to go back to first end, the cost will be taken as the cost of that camel.
-> At the end, he has to move all the camels to the opposite end.
Find the minimum cost to take camels to opposite end.

Example:
INPUT:
2              // No of test cases
4              // No of camels in first test case
1 2 8 9        // Cost of camels
6
14 45 73 86 95 98

OUTPUT
16
434

CONSTRAINTS
num of camels <= 20

*/

// approach: backtracking

#include <bits/stdc++.h>
#define ll long long;
#define fast  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
using namespace std;

int n;
int camels[20];
bool leftSide[20]; // track to the left camels
bool rightSide[20]; // track to the right camels
int ans;  // since we will take minimum cost

void back(bool isPositionLeft, int cost){
  // check if all of the camels are in rightside
  int cnt = 0;
  for (int i = 0; i < n; i++){
      if (rightSide[i]) cnt++;
  }
  
  if (cnt == n){
      ans = min(ans, cost);
      return;
  }
  
  if (isPositionLeft){
      // all combinations of sending two camels to the right side
      for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
          if (leftSide[i] && leftSide[j]){
            leftSide[i] = false;
            leftSide[j] = false;
            rightSide[i] = true;
            rightSide[j] = true;
            
            back(false, cost + max(camels[i], camels[j]));
            
            leftSide[i] = true;
            leftSide[j] = true;
            rightSide[i] = false;
            rightSide[j] = false;
          }
        }
      }
  }
  else{
      // all combinations of sending one camel to the left side
      for (int i = 0; i < n; i++){
        if (rightSide[i]){
          rightSide[i] = false;
          leftSide[i] = true;
          
          back(true, cost + camels[i]);
          
          rightSide[i] = true;
          leftSide[i] = false;
        }
      }
  }
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> camels[i];
    
    // make all of leftside camels true and rightside camels false.
    memset(leftSide, true, sizeof(leftSide));
    memset(rightSide, false, sizeof(rightSide));
    
    ans = INT_MAX;  // since we have to take minimum cost
    // ans has to be assigned INT_MAX before calling back() bcz, there are multiple test cases.
    back(true, 0);
    // params: am_i_in_leftside, curr_cost
    cout << ans << endl;
}

int main(){
  fast;
  
  int t;
  cin >> t;
  while (t--){
    solve();
  }
  
  return 0;
}

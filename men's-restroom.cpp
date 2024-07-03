/* ques:
It is a well-researched fact that men in a restroom generally prefer
to maximize their distance from already occupied stalls, by
occupying the middle of the longest sequence of unoccupied places.
For example, consider the situation where ten stalls are empty.

The first visitor will occupy a middle position:
_ _ _ _ _ X _ _ _ _
The next visitor will be in the middle of the empty area at the left.
_ _ X _ _ X _ _ _ _


Example of the output for the number of stalls, n = 10
_ _ _ _ X _ _ _ _ _	; when k = 1
_ _ _ _ X _ _ X _ _	; when k = 2
_ X _ _ X _ _ X _ _
_ X _ _ X _ _ X X _	; when k = 4
_ X _ _ X X _ X X _
_ X X _ X X _ X X _
_ X X _ X X _ X X X
_ X X _ X X X X X X
_ X X X X X X X X X
X X X X X X X X X X

INPUT:
t	// num_of_test_cases
n, k	// for each t: num_of_stalls, num_of_men

OUTPUT:
the arrangement after k men have occupied the slots.

*/

#include <bits/stdc++.h>
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

int main(){
  fast;
  
  int t;
  cin >> t;
  while(t--){
    int n, k;   // num_of_stalls, num_of_men
    cin >> n >> k;
    vector<int> v(n, 0);  // here, i want to show empty stalls as 0
    
    // while k is not finished, loop over v and find mid of longest empty stalls
    while(k--){
      int mxLen = 0, cnt = 0, lastIdx;
      
      // use for loop to find longest len of empty stalls
      for(int i=0; i<n; ++i){
        if(v[i] == 0) cnt++;
        else cnt = 0;
        
        if(cnt >= mxLen) {
          mxLen = cnt;
          lastIdx = i;
        }
        
      }
      
      int s = lastIdx - mxLen + 1;
      int mid = (lastIdx + s) / 2;
      v[mid] = 1;   // here, i want to show occupied stalls as 1
    }
    
    // print the vector
    for(int i=0; i<n; ++i) cout << v[i];
    cout << endl;
    
  }
  
  return 0;
}

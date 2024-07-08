/*
https://www.careercup.com/question?id=5740719907012608
https://stackoverflow.com/questions/39673898/divide-array-into-k-contiguos-partitions-such-that-sum-of-maximum-partition-is-m/39675396
http://ideone.com/r60yH4 - Sameer Code
https://www.careercup.com/question?id=5730470801702912
*/

/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil 
mines adjacent to each other and not in between of each others.After distributing them compute the 
difference of oil mines from the company getting highest and company getting lowest. This number 
should be minimum.(then only the distribution can be termed as fair).

Input 
4 		// num of tests
2 4 		// num_companies, num_mines
6 13 10 2 	// mines 
2 4 
6 10 13 2 
3 5 
6 13 10 2 5
5 6
6 10 13 2 7 3

output 
5 
1
2
10
*/


#include <bits/stdc++.h>
#define ll long long
#define fast \
  ios_base::sync_with_stdio(0);  \
  cin.tie(0);
using namespace std;

int c, mines;
int ans;
int oilMines[20];
bool vis[20];

void back(int i, int sum, int companies, int mn, int mx){
  // if i is visited, then check if total num of companies is equal to c
  if(vis[i]){
    if(companies == c){
      int newMin = min(mn, sum);
      int newMax = max(mx, sum);
      ans = min(ans, newMax - newMin);
    }
    
    return;
  }
  
  int j = (i + 1) % mines;
  vis[i] = true;
  back(j, sum + oilMines[i], companies, mn, mx);  // add this mine to the same company
  int newMin = min(mn, sum);
  int newMax = max(mx, sum);
  back(j, oilMines[i], companies + 1, newMin, newMax);    // add this mine to a new company
  vis[i] = false;
  
}

int main(){
  fast;
  
  int t;
  cin >> t;
  while(t--){
    cin >> c >> mines;    // num_of_companies, num_of_mines
    for(int i=0; i<mines; ++i){
      cin >> oilMines[i];
      vis[i] = false;
    }
    
    // for each mine, call backtrack
    ans = INT_MAX;  // since we need minimum and for multiple test case, we have to declare the value here
    for(int i=0; i<mines; ++i){
      back(i, 0, 1, INT_MAX, INT_MIN);
      // params: which mine should we take, sum of mines for a company, num of company at initial, min, max
    }
    
    // if num_of_companies is greater than num_of_companies, then fair division would not possible
    if(c > mines) ans = -1;
    
    cout << ans << endl;
    
  }
  
  
  return 0;
}

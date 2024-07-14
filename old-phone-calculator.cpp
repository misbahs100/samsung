// recheck: not sure if the code is correct.

/*
https://www.careercup.com/question?id=5680648437104640

You are given an old touch smartphone numbers having dial pad and calculator app.
Aim: The goal is to type a number on dialpad.

But as phone is old, some of the numbers and some operations can't be touched.
For eg. 2,3,5,9 keys are not responding , i.e you cannot use them
But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number

Calculator have 1-9 and +,-,*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it.

You have to find minimum number to touches required to obtain a number.

#Input:#
There will be multiple Test cases .Each test case will consist of 4 lines
1) First line will consist of N,M,O
	N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
	M:types of operations supported (+,-,*,/)
	O: Max no of touches allowed
2) second line of input contains the digits that are working e.g 0,2,3,4,6.
3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)
4) fourth line contains the number that we want to make .

#Output:#
Output contains 1 line printing the number of touches required to make the number


#Sample Test Case:#
5 
5 3 5
1 2 4 6 0
1 2 3
5
6 4 5 
1 2 4 6 9 8
1 2 3 4
91
6 2 4
0 1 3 5 7 9
1 2 4
28
5 2 10
1 2 6 7 8
2 3
981
6 3 5
1 4 6 7 8 9
1 2 3
18

#Output:#
4
2 
5
9
2



If you have to type 18-> 2 operations. (Each touch is considered an operation),br> If you have to type 5 -> '1+4=' that requires 4 operations. There could be other ways to make '5'.
*/

#include <bits/stdc++.h>
#define ll long long	// can't add ; at the end of the line
#define fast  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
using namespace std;


ll n, m, o, k;
ll digits[20], operators[20];
ll finalAns;
vector<char> vp = {'+', '-', '*', '/'};

bool valid(string s){
  // if the size is zero, not valid
  // if the string contains operator and its last character is not '=', not valid
  // otherwise its valid
  
  if(s.size() == 0) return false;
  for(ll i=0; i<s.size(); ++i){
    if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
      if(s[s.size() - 1] == '=') return true;
      else return false;
    }
  }
  
  return true;
}


ll getSum(string s){
  // declare 3 variables
  // iterate by size of s
  // if s[i] is digit then calculate the number
  // else it is a operator and perform the operation
  // at end, return variable by checking if the string contains '=' or not.
  
  ll ans = 0; // will calculate numbers and operations
  ll cnt = 0; // will only calculate numbers
  char prevSign = '.' ;
  
  for(ll i=0; i<s.size(); ++i){
    if(s[i] >= '0' && s[i] <= '9'){
      cnt *= 10;
      cnt += (s[i] - '0');
    }
    else{
      if(prevSign == '+') ans += cnt;
      else if(prevSign == '-') ans -= cnt;
      else if(prevSign == '*') ans *= cnt;
      else if(prevSign == '/' && cnt && ans%n == 0) ans += cnt;
      else if(prevSign == '.') ans = cnt;
      
      cnt = 0;
      prevSign = s[i];
    }
  }
  
  if(s[s.size() - 1] != '=') ans = cnt;
  return ans;
}

void back(string &s, ll op, bool isOpUsed){
  // base cases
  if(op > o) return;
  if(s.size() > finalAns) return;
  if(valid(s) && getSum(s) > 1000) return;
  
  // 1. if any operator is used and num_of_operator_used_so_far (op) has not crossed the max_num_of_operator(o) and last index of string is a digit
  // then we'll add '=' at the end of copied_string and if its getSum is equal to k, we'll take min of finalAns and op+1 
  // 2. otherwise if the getSum is equal to k, we'll take min of finalAns and op 
  
  
  if(isOpUsed){
    if(op < o && s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9'){
      string t = s;
      t += '=';
      if(getSum(t) == k) finalAns = min(finalAns, op + 1);
    }
  }
  else if(s.size()){
    if(getSum(s) == k) finalAns = min(finalAns, op);
  }
  
  // recursion: iterate n times for digits array
  for(ll i=0; i<n; ++i){
    string t = s + char(digits[i] + '0');
    back(t, op+1, isOpUsed);
  }
  
  if(s.size() && 
     s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9' && 
     op < o - 1) {
       // recursion: iterate m times for operators array
       for(ll i=0; i<m; ++i){
         string t = s + char(vp[operators[i] - 1]);
         back(t, op+1, true);
       }
     }
}

void solve(){
  cin >> n >> m >> o;
  for(ll i=0; i<n; ++i) cin >> digits[i];
  for(ll i=0; i<m; ++i) cin >> operators[i];
  cin >> k;
  
  // approach:
  // we'll maintain a string where we'll keep concatinating the given-digits and operators.
  // and we'll check if the string becomes equal to the desired output, k. 
  
  finalAns = INT_MAX;   // since we need minimum ans and there are multiple test case, that's why value should be assigned here
  string s = "";
  back(s, 0, false);
  // params: &string_which_we'll_keep_concatinating, num_of_operator_used_so_far, isAnyOperatorUsed
  cout << finalAns << endl;
  
}

int main(){
  fast;
  
  ll t;
  cin >> t;
  while(t--){
    solve();
  }
  
  
  return 0;
}

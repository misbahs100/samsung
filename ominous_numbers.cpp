/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-40-campus-white-box-testing/
https://www.geeksforgeeks.org/samsung-rd-sri-noida-on-campus-interview-experience/
https://code.hackerearth.com/01ac52j?key=b462f0a802c8c1faf1d87f2b1353b9ce

A company sells its products with a unique serial number on it. The company has found that some products don’t sell well, which are identified to have ominous numbers in the serial number of the product. If a serial number of the product contains fewer than 
𝑘
k ominous numbers, then it won’t sell.

Given a range from a to b, you need to find the number of products that would sell, leaving out the products that contain fewer than 𝑘 ominous numbers.

Input:
The first line contains three integers: a, b, and k, where:
a and b are the start and end of the serial number range (inclusive). k is the minimum number of ominous digits a serial number must contain to be considered sellable.
The second line contains an integer n (the number of ominous digits).
The third line contains n integers representing the ominous digits.

Output:
Output the number of products that would sell.

Example:
Input:
10 20 1
2
4 7

Output:
19

*/

#include<bits/stdc++.h>
#define ll long long;
#define fast  \
  ios_base::sync_with_stdio(0);  \
  cin.tie(0);
using namespace std;


int main(){
  fast;
  
  int a, b, k;        // a: start_range, b: end_range, k: max_ominous_digits
  cin >> a >> b >> k;
  int n;
  cin >> n;           // number of ominous nums
  int ominous[n];
  for(int i=0; i<n; ++i){
    cin >> ominous[i];
  }
  
  int sellable = 0;
  for(int i=a; i<=b; ++i){  // range is inclusive, that's why i<=b is used
    int num = i;
    int freq[10] = {0};
    
    while(num){
      int rem = num % 10;
      freq[rem]++;
      num /= 10;
      
    }
    
    int cnt = 0;
    for(int j=0; j<n; ++j) cnt += freq[ominous[j]];
    
    if(cnt < k) sellable++;
    
    
    
  }
  
  cout << sellable << endl;
  
  return 0;
  
}

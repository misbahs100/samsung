// ques: https://leetcode.com/discuss/interview-question/4157407/Samsung-RandD-(OnCampus)-2023-or-Easy-but-tricky/

/*
We have an equation k= (an + bnlog(base2)n + cn^3) , k is achieved by enumeration on this equation.
We have to find which value of n satisfy above eqaution.

if no such value of n then return 0.
(Constraints are for Binary search) .
input a, b, c, k.

*/

// approach: binary search

#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
#define fast	\
	ios_base::sync_with_stdio(0);	\
	cin.tie(0);

ll calculate(ll a, ll b, ll c, ll n) {
    return a * n + b * n * log2(n) + c * n * n * n;
}

ll findN(ll a, ll b, ll c, ll k) {
    ll left = 0, right = 1e6; // we might need to adjust the right limit based on problem constraints
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll result = calculate(a, b, c, mid);

        if (result == k) {
            return mid;
        } else if (result < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    // Verify if the found n is correct
    if (calculate(a, b, c, left) == k) {
        return left;
    } else {
        return 0;
    }
}

int main() {
    fast;
    
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        ll a, b, c, k;
        cin >> a >> b >> c >> k;

        ll result = findN(a, b, c, k);
        cout << result << "\n";
    }

    return 0;
}


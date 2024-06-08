/*
question: https://vjudge.net/contest/473801#problem/A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> fairDivisionOfCoins(int n, vector<pair<int, vector<int>>>& testCases) {
    vector<int> results;
    for (const auto& testCase : testCases) {
        int m = testCase.first;
        const vector<int>& coins = testCase.second;
        int totalSum = accumulate(coins.begin(), coins.end(), 0);
        int target = totalSum / 2;
        // Initialize a DP array to track possible sums
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int coin : coins) {
            for (int j = target; j >= coin; --j) {
                if (dp[j - coin]) {
                    dp[j] = true;
                }
                /* This condition checks if a sum j - coin can be achieved using the previously considered coins.
                If dp[j - coin] is true, it means that by adding the current coin to this subset, we can achieve the sum j.
                Therefore, we set dp[j] to true. */
            }
        }
        
        // Find the best achievable sum closest to target
        int closestSum = 0;
        for (int i = target; i >= 0; --i) {
            if (dp[i]) {
                closestSum = i;
                break;
            }
        }
        int minimalDifference = totalSum - 2 * closestSum;
        results.push_back(minimalDifference);
    }
    return results;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, vector<int>>> testCases(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vector<int> coins(m);
        for (int j = 0; j < m; ++j) {
            cin >> coins[j];
        }
        testCases[i] = make_pair(m, coins);
    }
    vector<int> results = fairDivisionOfCoins(n, testCases);
    for (int result : results) {
        cout << result << endl;
    }
    return 0;
}

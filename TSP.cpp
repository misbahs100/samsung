// Travelling Salesperson Problem
// question link: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4/problem

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

// bit masking:
// setting a bit: n | (1 << i)
// clear a bit: n & ~(1 << i)
// toggle a bit: n ^ (1 << i)
// check a bit is set/unset: n & (1 << i)
//     it will output 1 if set, 0 if unset

// Function to solve TSP using Dynamic Programming with bitmasking
int tsp(int mask, int pos, int n, vector<vector<int>> &cost, vector<vector<int>> &dp) {
    // mask is used to trace which city have been visited. we could also use a vector/map to trace this.
    if (mask == (1 << n) - 1) {     // if mask = (2^n)-1, i.e., all bits of mask are 1: all of the nodes are visited
        return cost[pos][0]; // Return to starting city
    }
    
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {    // checking if the city is not visited
            int newCost = cost[pos][city] + tsp(mask | (1 << city), city, n, cost, dp);
            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> cost(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cost[i][j];
            }
        }

        vector<vector<int>> dp(1 << N, vector<int>(N, -1));
        int result = tsp(1, 0, N, cost, dp);    // mask(used to trace the visited cities), position_of_city, num_of_cities, cost, dp
        cout << result << endl;
    }

    return 0;
}


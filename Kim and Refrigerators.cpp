// Kim and Refrigerators (similar as TSP problem)
// question link: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators

#include <bits/stdc++.h>
using namespace std;

int tsp(int mask, int pos, int n, vector<vector<int>> &distances, vector<vector<int>> &dp){
    if(mask == (1 << n) - 1){
        return distances[pos][n-1]; // Return to home
    }    
    
    if(dp[mask][pos] != -1) return dp[mask][pos];
    
    int cost = INT_MAX;
    for(int customer = 0; customer < n; customer++){
        if((mask & (1 << customer)) == 0){
            cost = min(cost, distances[pos][customer] + tsp(mask | (1 << customer), customer, n, distances, dp));
        }
    }
    
    return dp[mask][pos] = cost;
}

int solve(){
    int n;
    cin >> n;
    n += 2; // Including the office and home
    vector<pair<int, int>> coord(n);
    int x, y;
    cin >> x >> y; // Office coordinates
    coord[0] = {x, y};
    cin >> x >> y; // Home coordinates
    coord[n-1] = {x, y};

    for(int i = 1; i < n-1; i++){
        cin >> x >> y;
        coord[i] = {x, y};
    }    
   
    vector<vector<int>> distances(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int wt = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
            distances[i][j] = wt;
            distances[j][i] = wt;
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    
    int ans = tsp(1, 0, n, distances, dp);
    
    return ans;
}

int main() {
    for(int test = 1; test <= 10; test++){
        cout << "# " << test << " ";
        int ans = solve();
        cout << ans << "\n";
    }
    return 0;
}


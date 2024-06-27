/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and 
the edge weights are the probabilities of the doctor going from that division to other connected division but the 
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be 
staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division 
in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling 
time is not considered and during that 10min at 10th min he will be in next division, so be careful

2
6 10 40 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

6 0.774000  
3 0.700000
*/

// approach: dfs + backtracking



#include<iostream>
#define ll long long;
#define fast	\
	ios_base::sync_with_stdio(0);	\
	cin.tie(0);
using namespace std;

void docProb(double **graph, int n, int time, int curNode, double p, double *answer){
    // Base case: if time is up, accumulate the probability in the answer array
    if(time <= 0){
        answer[curNode] += p;
        return;
    }

    // Recursive case: for each possible transition, update the probability
    for(int i = 1; i <= n; i++){
        if(graph[curNode][i] != 0){
            // Update probability for the next transition
            p *= graph[curNode][i];
            // Recursive call with reduced time
            docProb(graph, n, time - 10, i, p, answer);
            // Backtrack the probability
            p /= graph[curNode][i];    
        }
    }
}

int main(){
    fast;
    
    int t;
    cin >> t;  // Number of test cases
    while(t--){
        int n, e, time;	// num of nodes, edges, total time
        cin >> n >> e >> time;
        
        // Initialize 2D graph with zero probabilities
        double **arr = new double*[n + 1]; 
        for(int i = 1; i <= n; i++){
            arr[i] = new double[n + 1];
            for(int j = 1; j <= n; j++){
                arr[i][j] = 0;
            }
        }

        // Read edges and their probabilities
        int from, to;
        double prob;
        for(int i = 0; i < e; i++){
            cin >> from >> to >> prob;
            arr[from][to] = prob;
        }

        // Initialize answer array
        double answer[n + 1] = {0.0};
        // Start the recursive probability calculation from node 1
        docProb(arr, n, time, 1, 1.0, answer);
        // params: graph, num_of_nodes, time, currNode, initial_probability, answer array
        
        // Find the division with the highest probability
        double finalProb = 0.0;
        int node = 0;
        
        for(int i = 1; i <= n; i++){
            if(answer[i] > finalProb){
                finalProb = answer[i];
                node = i;
            }
        }
        // Output the division and its probability
        cout << node << " " << finalProb << "\n";
    }
    
    return 0;
}


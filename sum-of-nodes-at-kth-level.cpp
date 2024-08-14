// ques: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/sum-of-nodes-in-kth-level/problem

// idea: make tree from string, then apply bfs(queue) to find the sum
// kth level should be started from 0, not 1. (according to this accepted-solution of hackerrank)

#include <bits/stdc++.h>
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;


class Node{
  public:
    int val;
    Node *left;
    Node *right;
    
    Node(int v){
      val = v;
      left = NULL;
      right = NULL;
    }
};

void makeTree(Node *&root, string &s){
  // firstly, remove first and last brackets
  s.erase(s.begin());
  s.pop_back();
  if(s.size() == 0) return;
  
  // find top root value and update the root
  int rootVal = 0;
  int i;  // this should be declared outside loop, bcz we need its last value
  for(i=0; i<s.size(); ++i){
    if(s[i] == '(') break;
    rootVal *= 10;
    rootVal += (s[i] - '0');
  }
  root = new Node(rootVal);
  
  // find the left-subtree and right-subtree and use recursion: use stack
  stack<char> st;
  string leftSide, rightSide;
  int j;  // should be declared outside loop
  for(j = i; j < s.size(); ++j){
    leftSide += s[j];
    if(s[j] == '(') st.push(s[j]);
    if(s[j] == ')') st.pop();
    if(st.empty()) break;
  }
  
  int k;  // should be declared outside loop
  for(k = j+1; k < s.size(); ++k){
    rightSide += s[k];
    if(s[k] == '(') st.push(s[k]);
    if(s[k] == ')') st.pop();
    if(st.empty()) break;
  }
  
  // call the function by recursion
  makeTree(root->left, leftSide);
  makeTree(root->right, rightSide);
  
}

int findSum(Node *root, int k){
  int sum = 0;
  queue<pair<Node *, int> > q;
  // here, pair: {Node *, level_no}
  
  q.push({root, 0});	// root starts at level 0. if question asks from level 1, just update the 0 to 1.
  while(!q.empty()){
    pair<Node *, int> p = q.front();
    q.pop();
    if(p.second == k) sum += p.first->val;
    if(p.first->left) q.push({p.first->left, p.second + 1});
    if(p.first->right) q.push({p.first->right, p.second + 1});
  }
  
  return sum;
}

int main(){
  fast;
  
  int k;	// k-th level
  string s;	// string of tree
  cin >> k >> s;
  
  Node *root;
  makeTree(root, s);
  cout << findSum(root, k) << endl;
  
  return 0;
  
}

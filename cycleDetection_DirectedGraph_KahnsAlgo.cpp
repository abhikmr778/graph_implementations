#include<iostream>
#include<vector>
#include<stack>
// #include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}


int main(){
    int V = 4;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,2,3);


    return 0;
}
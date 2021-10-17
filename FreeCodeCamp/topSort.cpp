#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int dfs(int i, int curr, vector<bool> &visited, vector<int> &ordering, vector<int> adj[]){
    visited[curr] = true;
    for(auto edge: adj[curr]){
        if(!visited[edge]){
            i = dfs(i, edge, visited, ordering, adj);
        }
    }
    ordering[i] = curr;
    return i-1;
}

vector<int> topSort(vector<int> adj[], int V){
    vector<bool> visited(V,false);
    vector<int> ordering(V);
    int i = V-1; // track ordering

    for(int curr=0; curr<V; curr++){
        if(!visited[curr])
            dfs(i,curr,visited,ordering,adj);
    }
    return ordering;
}

int main(){

    int V = 6;
    vector<int> adj[6];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    
    vector<int> ordering = topSort(adj,V);
    for(auto x: ordering){
        cout<<x<<endl;
    }

    return 0;
}
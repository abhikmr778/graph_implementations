#include<iostream>
#include<vector>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v){
    //add u--->v
    adj[u].push_back(v);
}

void DFS(vector<int> adj[], int u, stack<int> &st, bool visited[]){
    // mark vertex as visited
    visited[u] = true;

    for(int v:adj[u]){
        if(!visited[v]) //if its adjacents are not visited then visit them
            DFS(adj,v,st,visited);
    }
    st.push(u); // after all adjacents are visited then push curr vertex
}

void topologicalSort(vector<int> adj[], int V){
    // to store the sort
    stack<int> st;

    //visited init
    bool visited[V];
    for(int i=0;i<V;i++) visited[i] = false;
    
    //perform DFS on every non visited vertex (handles disconnected graphs)
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(adj,i,st,visited);
        }
    }

    //print the topological sort
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}


int main(){
    //acyclic directed graph
    int V = 5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,3,4);

    // using DFS
    topologicalSort(adj,V);

    return 0;
}
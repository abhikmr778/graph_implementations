#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void DFSstack(vector<int> adj[], int src, int V){
    vector<int> visited(V,false);
    stack<int> st;
    st.push(src);
    while(!st.empty()){
        int curr = st.top(); st.pop();
        cout<<char(curr+'a')<<endl;
        for(int adjacent: adj[curr]){
            if(!visited[adjacent]){
                st.push(adjacent);
                visited[adjacent] = true;
            }
        }
    }
}

void DFSrec(vector<int> adj[], vector<bool> &visited, int src){
    cout<<char(src+'a')<<endl;
    visited[src] = true;
    for(int adjacent: adj[src]){
        if(!visited[adjacent]){
            DFSrec(adj, visited, adjacent);
        }
    }
}

int main(){
    int V = 6;
    vector<int> adj[6];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    DFSstack(adj,0,V);
    vector<bool> visited(V,false);
    DFSrec(adj,visited,0);
    return 0;
}
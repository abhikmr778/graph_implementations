// Do 2 DFS traversals
// In first one find the finish time of all nodes using a stack

#include<iostream>
#include<vector>
#include<stack>
// #include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void fillOrder(vector<int> adj[],int src, bool visited[], stack<int> &st){
    visited[src] = true;
    for(int u:adj[src]){
        if(!visited[u])
            fillOrder(adj,u,visited,st);
    }
    st.push(src);
}

void reverseEdges(vector<int> adj[], int V, vector<int> reverseAdj[]){
    for(int v=0;v<V;v++){
        for(int u:adj[v]){
            reverseAdj[u].push_back(v);
        }
    }
}

void DFSrec(int src, bool visited[], vector<int> reverseAdj[]){
    visited[src] = true;
    cout<<src<<" ";
    for(int u:reverseAdj[src]){
        if(!visited[u]){
            DFSrec(u, visited, reverseAdj);
        }
    }
}

void stronglyConComp(vector<int> adj[], int V){
    stack<int> st;
    bool visited[V] = {false};

    // DFS to fill vertices according to finish times
    for(int i=0; i<V; i++){
        if(!visited[i])
            fillOrder(adj,i,visited,st);
    }

    // reverse all edges
    vector<int> reverseAdj[V];
    reverseEdges(adj,V,reverseAdj);
    // for(int v=0;v<V;v++){
    //     for(int u:reverseAdj[v])
    //         cout<<u<<" ";
    //     cout<<endl;
    // }

    // do another DFS following stack order
    for(int i=0;i<V;i++) visited[i] = false;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!visited[u]){
            DFSrec(u,visited,reverseAdj);
            cout<<endl;
        }
    }
}

int main(){
    int V = 6;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,3);
    addEdge(adj,3,2);
    addEdge(adj,2,0);
    addEdge(adj,2,4);
    addEdge(adj,4,5);
    addEdge(adj,5,4);
    
    stronglyConComp(adj,V);
    return 0;
}
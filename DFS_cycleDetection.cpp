#include<iostream>
// #include<bits/stdc++>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool cycleCheck(vector<int> adj[],bool visited[], int src, int parent){
    visited[src] = true;
    for(int u:adj[src]){
        if(!visited[u]){
            if(cycleCheck(adj,visited,u,src)==true){ // means there's a cycle ahead in the DFS 
                return true;
            }
        }
        else if(u!=parent){ // if node already visited but is not the parent then cycle
            return true;
        }
    }
    return false; // no cycle
}

int detectCycle(vector<int> adj[], int V){
    bool visited[V+1];
    for(int i=1;i<V+1;i++) visited[i] = false;
    for(int i=1;i<V+1;i++){
        if(!visited[i]){
            if(cycleCheck(adj,visited,i,-1)==true){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int V=6;
    vector<int> adj[V+1]; // create a graph with cycles
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    
    if(detectCycle(adj,V)){
        cout<<"Cycle present";
    }
    else{
        cout<<"Cycle not present";
    }

    return 0;
}
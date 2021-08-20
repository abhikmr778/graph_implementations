// cycle detection in a directed graph
#include<iostream>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    //edge u--->v
    adj[u].push_back(v);
}

bool checkCycle(vector<int> adj[], bool visited[], bool recStack[], int src){
    visited[src] = true;
    recStack[src] = true;
    for(int u: adj[src]){
        if(!visited[u] && checkCycle(adj,visited,recStack,u)==true){ // loop exists ahead in DFS
            return true;
        }
        else if(recStack[u]==true){// loop detected
            return true;
        }
    }
    recStack[src] = false; // backtracking
    return false;
}

int cycleDetect(vector<int> adj[], int V){
    bool visited[V];
    bool recStack[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(checkCycle(adj,visited,recStack,i)==true){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int V=6; // 0,1,...,5
    vector<int> adj[V]; //create cyclic directed graph
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,2);
    addEdge(adj,5,3);

    // keep a track of the nodes present in recursion call stack
    // detect a back edge i.e., an edge from descendants to ancestors
    if(cycleDetect(adj,V)){
        cout<<"Cycle detected";
    }
    else{
        cout<<"Cycle not detected";
    }
    return 0;
}
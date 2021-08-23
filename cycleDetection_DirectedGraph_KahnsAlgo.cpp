#include<iostream>
#include<vector>
#include<queue>
// #include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void calcIndegree(vector<int> adj[], int indegree[], int V){
    for(int i=0;i<V;i++){
        for(int v:adj[i]){
            indegree[v]++;
        }
    }
}

void cycleDetection(vector<int> adj[],int V){
    int indegree[V];
    for(int i=0;i<V;i++) indegree[i] = 0;
    calcIndegree(adj,indegree,V);

    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }

    int count = 0; //to detect cycle
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
        count++;
    }
    cout<<"Count = "<<count<<" ";
    if(count!=V) cout<<"Cycle Detected";
    else cout<<"No cycle detected";
}

int main(){
    int V = 5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,2,3);
    addEdge(adj,4,3);
    // cycle detection in a directed graph using Kahn's algorithm
    cycleDetection(adj,V);

    return 0;
}
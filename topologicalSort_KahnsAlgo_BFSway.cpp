// given a directed acyclic graph do a topological traversal 

#include<iostream>
#include<vector>
#include<queue>
// #include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v){
    // add edge u--->v
    adj[u].push_back(v);
}

void calcIndegree(vector<int> adj[], int indegree[], int V){
    for(int i=0;i<V;i++){
        for(int u:adj[i]){
            indegree[u]++;
        }
    }
}

void BFSTopSort(vector<int> adj[], int V){
    //calculate indegree of every vertex
    int indegree[V];
    for(int i=0;i<V;i++) indegree[i] = 0;
    calcIndegree(adj, indegree, V);

    //enqueue all vertices with 0 indegree
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int v = q.front(); q.pop();
        cout<<v<<" ";
        for(int u: adj[v]){
            indegree[u]--;
            if(indegree[u]==0){
                q.push(u);
            }
        }

    }

}


int main(){

    int V = 5;
    vector<int> adj[V];
    //Graph1
    // addEdge(adj,0,1);
    // addEdge(adj,0,2);
    // addEdge(adj,1,3);
    // addEdge(adj,2,3);
    // addEdge(adj,3,4);
    // addEdge(adj,3,5);   

    //Graph2
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);

    BFSTopSort(adj,V);

    return 0;
}
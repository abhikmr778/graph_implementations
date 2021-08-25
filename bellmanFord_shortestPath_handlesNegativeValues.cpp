// find shortest paths of one edge length, then two edge lentght and so on... ==> Algorithm: We relax all edges V-1 times

#include<iostream>
#include<vector>

// #include<bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u, int v, int weight){
    adj[u].push_back(make_pair(v,weight)); // directed acyclic weighted graph
}

vector<int> bellmanFord(vector<pair<int,int>> adj[], int V, int src){
    vector<int> dist(V,INT32_MAX);
    dist[src] = 0;
    for(int count = 0; count<V-1; count++){
        for(int u = 0; u<V; u++){
            for(pair<int,int> v: adj[u]){
                if(dist[v.first]>dist[u] + v.second){
                    dist[v.first] = dist[u] + v.second;
                }
            }
        }
    }
    return dist;
}

int main(){
    int V = 4;
    vector<pair<int,int>> adj[V];
    addEdge(adj,0,1,1);
    addEdge(adj,0,2,4);
    addEdge(adj,1,2,-3);
    addEdge(adj,1,3,2);
    addEdge(adj,2,3,3);
    int src = 0;
    for(int x:bellmanFord(adj,V,src)){
        cout<<x<<" ";
    }


    return 0;
}

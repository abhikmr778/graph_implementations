// Given a weighted graph and a source, find shortest distances from source to all other vertices
// Doesn't work for -ve weight edges

#include<iostream>
#include<queue>
// #include<bits/stdc++.h>

using namespace std;

vector<int> dijkstra(vector<vector<int>> graph, int src, int V){
    priority_queue<int> pq;
    vector<int> dist(V,INT32_MAX);
    dist[src] = 0;
    vector<bool> fin(V,false);
    for(int i=0; i<V-1; i++){
        int u = -1;
        for(int j=0;j<V;j++){ // find the edge not yet travelled with shortest distance
            if(!fin[j] && (u==-1 || dist[j]<dist[u])){
                u = j;
            }
        }
        fin[u] = true;
        for(int v=0;v<V;v++){// relax distances
            if(graph[u][v]!=0 && fin[v]==false){
                dist[v] = min(dist[v],dist[u]+graph[u][v]);
            }
        }
    }
    return dist;
}

int main(){
    int V = 4;
    vector<vector<int>> graph{{0, 50, 100, 0},
                       {50, 0, 30, 200},
                       {100, 30, 0, 20},
                       {0, 200, 20, 0}};
    
    int src = 0;
    for(int dist:dijkstra(graph,src,V)){
        cout<<dist<<" ";
    }


    return 0;
}

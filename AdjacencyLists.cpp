#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    //undirected graph so form an edge u-v and v-u
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V){
    for(int i=0;i<V;i++){
        cout<<"\n Adjacency list of vertex "<<i<<"\n head";
        for(int x: adj[i]){
            cout<<" -> "<<x;
        }
        cout<<"\n";
    }
}

int main(){

    // we store adjacency lists using array of vectors or vector of vectors
    int V = 5; // no of vertices
    vector<int> adj[V]; //no of adjacecny lists 5; each corresponding to a vettex
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    printGraph(adj,V);


    return 0;
}
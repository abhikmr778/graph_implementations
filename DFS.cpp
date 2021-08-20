#include <iostream>
#include <vector>

using namespace std;

//DFS is recursive in nature

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSrec(vector<int> adj[], bool visited[], int src){
    visited[src] = true;
    cout<<src<<" ";
    for(int u: adj[src]){
        if(!visited[u]){
            DFSrec(adj,visited,u);
        }
    }
}

void DFS(vector<int> adj[], int V){
    bool visited[V+1];
    for(int i=1;i<V;i++) visited[i] = false;
    for(int i=1;i<V;i++){
        if(!visited[i]){
            DFSrec(adj,visited,i);
        }
    }
}

int main(){
    int V=6;
    vector<int> adj[V+1]; // due to 0 base
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);

    DFS(adj,V);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void BFS(vector<int> adj[], int V, int source){
    bool visited[V];
    for(int i=0;i<V;i++) visited[i] = false;
    //follow level order traversal as in binary trees
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        cout<<u<<" ";
        for(int i=0; i<adj[u].size();i++){
            if(visited[adj[u][i]]==false){
                visited[adj[u][i]]=true;
                q.push(adj[u][i]);
            }
        }
    }
}


int main(){
    int V=6;
    vector<int> adj[V+1]; // due to 1 base and not 0 base
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    
    BFS(adj,V,1);

    return 0;
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFSrec(vector<int> adj[], int source, bool visited[]){
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFSdis(vector<int> adj[], int V){
    //init visited
    bool visited[V];
    for(int i=0;i<V;i++) visited[i]=false;
    
    //traverse all vertices and call BFS if not already visited
    for(int i=0;i<V;i++){
        if(!visited[i]){
            BFSrec(adj,i,visited);
            cout<<endl;
        }
    }
}

int main(){
    int V = 6;
    vector<int> adj[V+1];
    addEdge(adj,0,1);
    addEdge(adj,1,3);
    addEdge(adj,3,2);
    addEdge(adj,0,2);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,4,6);
    BFSdis(adj,V);

    return 0;
}
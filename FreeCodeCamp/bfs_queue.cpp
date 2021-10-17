#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}
void bfs(vector<int> adj[], int src){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout<<char(u+'a')<<endl;
        for(int adjacent: adj[u]){
            q.push(adjacent);
        }
    }
}

int main(){
    int V = 6;
    vector<int> adj[6];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    bfs(adj, 0);

    return 0;
}
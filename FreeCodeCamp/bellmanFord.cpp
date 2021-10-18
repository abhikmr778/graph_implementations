#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt){
    adj[u].push_back(make_pair(v,wt));
}


void bf(vector<pair<int,int>> adj[], int V, int src){
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    //relax each edge V-1 times because it takes V-1 edges to reach the last vertex

    for(int i=0; i<V-1; i++){ // this runs for O(V)
        // this below part is O(E)
        for(int j=0; j<V; j++){
            for(auto edge: adj[j]){
                int next_node = edge.first;
                int edge_wt = edge.second;
                int newdist = dist[j] + edge_wt;
                if(newdist<dist[next_node])
                    dist[next_node] = newdist;
            }
        }
    } // above total is O(VE)
    
    for(int d: dist){
        cout<<d<<" ";
    }

    // repeat the above process to find negative cycle as the dist will decrease further if a negative cycle is present
    for(int i=0; i<V-1; i++){
        for(int j=0; j<V; j++){
            for(auto edge: adj[j]){
                int next_node = edge.first;
                int edge_wt = edge.second;
                int newdist = dist[j] + edge_wt;
                if(newdist<dist[next_node]){
                    dist[next_node] = INT_MIN; // mark cost as -inf
                }
            }
        }
    }
}

int main(){
    int V = 8;
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0,1,3);
    addEdge(adj, 0,2,6);
    addEdge(adj, 1,3,4);
    addEdge(adj, 1,4,11);
    addEdge(adj, 1,2,4);
    addEdge(adj, 2,3,8);
    addEdge(adj, 2,6,11);
    addEdge(adj, 3,4,-4);
    addEdge(adj, 3,5,5);
    addEdge(adj, 3,6,2);
    addEdge(adj, 4,7,9);
    addEdge(adj, 5,7,1);
    addEdge(adj, 6,7,2);
    bf(adj,V,0);

    return 0;
}
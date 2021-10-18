#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int wt){
    adj[u].push_back(make_pair(v,wt));

}

vector<int> findshortestpath(vector<pair<int,int>> adj[], vector<int> dist, vector<int> prev, int V, int src, int target){
    vector<int> path;
    if(dist[target]==INT_MAX) return path;
    for(int at = target; at!=-1; at=prev[at]){
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

void dijkstra(vector<pair<int,int>> adj[], int V, int src){
    vector<bool> visited(V,false);
    vector<int> dist(V,INT_MAX);
    vector<int> prev(V,-1);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(src,0));

    while(!pq.empty()){
        pair<int,int> idx_dist = pq.top();
        int idx = idx_dist.first;
        int min_dist = idx_dist.second;
        pq.pop();

        visited[idx] = true;

        if(dist[idx]<min_dist) continue; // if a duplicate is in pq and we want to right away skip it

        for(auto edge: adj[idx]){
            int node = edge.first;
            int wt = edge.second;

            if(!visited[node]){
                int newdist = dist[idx] + wt;

                if(newdist<dist[node]){
                    prev[node] = idx;
                    dist[node] = newdist;
                    pq.push(make_pair(node, dist[node]));
                }

            }
        }
    }
    for(int d: dist)
        cout<<d<<" ";

    // path to some target
    int target = 7;
    vector<int> short_path = findshortestpath(adj, dist,prev, V, src, target);
    for(int s: short_path){
        cout<<s<<"-->";
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
    dijkstra(adj,V,0);

    return 0;
}
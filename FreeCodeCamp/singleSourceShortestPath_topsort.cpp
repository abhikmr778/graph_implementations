#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int wt){
    adj[u].push_back(make_pair(v,wt));
}

bool dfs(int src, vector<pair<int,int>> adj[], vector<bool> &recSt, vector<bool> &visited, stack<int> &st){
    visited[src] = true;
    recSt[src] = true;
    for(auto u: adj[src]){
        if(!visited[u.first] && dfs(u.first,adj,recSt,visited,st)){
            return true;
        }
        else if(recSt[u.first]==true)
            return true; //back edge
    }
    st.push(src);
    recSt[src] = false;
    return false;
}

void topsort(vector<pair<int,int>> adj[], int V, vector<int> &order){
    vector<bool> visited(V,false);
    vector<bool> recSt(V,false); // keep check on cycles

    stack<int> st; // will store topsort
    bool cyclePresent = false;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            if(dfs(i,adj,recSt,visited,st)){
                cyclePresent = true;
                break;
            }
        }
    }
    
    if(cyclePresent){
        cout<<"Not a DAG"<<endl;
        return;
    }

    while(!st.empty()){
        order.push_back(st.top());
        st.pop();
    }

}

void sssp(vector<pair<int,int>> adj[], int V){
    vector<int> order; // topsort order
    topsort(adj,V,order);

    vector<int> distances(V,INT_MAX);
    int start = 2;
    distances[start] = 0;
    for(int i=0; i<V; i++){
        int nodeIdx = order[i];
        if(distances[nodeIdx]!=INT_MAX){
            for(auto u: adj[nodeIdx]){
                int adj_node = u.first;
                int edge_wt = u.second;
                if(distances[adj_node] > distances[nodeIdx] + edge_wt){ //distance of the adjacent less than curr distance + edge weight
                    distances[adj_node] = distances[nodeIdx] + edge_wt;
                }
            }
        }
    }

    for(int dist: distances){
        cout<<dist<<" ";
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
    sssp(adj,V);
    return 0;
}
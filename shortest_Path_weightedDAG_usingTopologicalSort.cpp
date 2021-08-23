#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int weight){
    adj[u].push_back(make_pair(v,weight));

}

void DFSrec(vector<pair<int,int>> adj[], bool visitied[], int src, stack<int> &st){
    visitied[src] = true;
    for(pair<int,int> u:adj[src]){
        if(!visitied[u.first])
            DFSrec(adj,visitied,u.first,st);
    }
    st.push(src);
}

void topologicalSort(vector<pair<int,int>> adj[],int V, stack<int> &topSort){
    bool visited[V];
    for(int i=0;i<V;i++) visited[i] = 0;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFSrec(adj,visited,i,topSort);
        }
    }
}

void shortestPath(vector<pair<int,int>> adj[],int V, int src){
    //initialize distance from source to every edge as infinite
    int dist[V];
    for(int i=0;i<V;i++) dist[i] = INT32_MAX;
    dist[src] = 0;

    //find topological sort of the graph
    stack<int> topSort;
    topologicalSort(adj,V,topSort);
    
    while(!topSort.empty()){
        int u = topSort.top();
        topSort.pop();
        for(pair<int,int> v:adj[u]){
            if(dist[v.first]>dist[u]+v.second){
                dist[v.first] = dist[u] + v.second;
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<"Distance from src:0 to vertex:"<<i<<" = "<<dist[i]<<endl;
    }
}


int main(){
    int V = 6;
    vector<pair<int,int>> adj[V];
    vector<int> weights[V];
    addEdge(adj,0,1,2);
    addEdge(adj,0,4,1);
    addEdge(adj,1,2,3);
    addEdge(adj,2,3,6);
    addEdge(adj,4,2,2);
    addEdge(adj,4,5,4);
    addEdge(adj,5,3,1);

    shortestPath(adj,V,0);
    return 0;
}
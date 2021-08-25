#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int weight){
    adj[u].push_back(make_pair(v,weight));
}

bool detectNegCycle(vector<pair<int,int>> adj[], int V){
    vector<int> dist(V,INT32_MAX);
    dist[0] = 0; //src = 0
    for(int count = 0; count<V-1; count++){
        for(int u=0;u<V;u++){
            for(pair<int,int> v:adj[u]){
                if(dist[v.first] > dist[u] + v.second){
                    dist[v.first] = dist[u] + v.second;
                }
            }
        }
    }
    for(int u=0;u<V;u++){
        for(auto v:adj[u]){
            if(dist[v.first] > dist[u] + v.second){
                return true;
            }
        }
    }
    return false;
}

int main(){
    // Idea: after performing bellman ford ie relaxing V-1 times we should have found all minm distances
    // Detection: if upon running the relaxation Vth time are further able to reduce distances then negative cycle exists
    int V = 4;
    vector<pair<int,int>> adj[V];
    addEdge(adj,0,1,4);
    addEdge(adj,0,2,8);
    addEdge(adj,1,2,-8);
    addEdge(adj,2,3,2);
    addEdge(adj,3,1,3);

    if(detectNegCycle(adj,V)){
        cout<<"Negative cycle detected";
    }
    else{
        cout<<"No negative cycle";
    }

    return 0;
}
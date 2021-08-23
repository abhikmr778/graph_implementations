// Prim's algorithm using adjacency matrix

#include<iostream>
#include<vector>
#include<set>
#include<queue>
// #include<bits/stdc++.h>

using namespace std;

// void addEdge(vector<int> adj[], char a, char b, int weight){
//     adj[a].push_back(make_pair(b,weight));
//     adj[b].push_back(make_pair(a,weight));
// }


int primsAlgo(vector<int> graph[], int V){
    int key[V], res = 0;

    //init distance as inf
    fill(key,key+V,INT32_MAX);
    
    //make dist of starting node as 0
    key[0] = 0;

    //init MST set as false ie no vertex is in MST
    bool mSet[V] = {false};

    //for every set of vertices in MST ie mSet = true do the following
    for(int count = 0;count<V;count++){
        
        //find the next edge with minm distance from the current MST
        int u = -1; // init index as -1
        for(int i=0;i<V;i++){ // for all vertices

        // only check vertices not included in MST
            if(!mSet[i] && (u==-1 || key[i]<key[u])) //if vertex hasnt been included and (its the first iteration or the distance of the edge to i is less than u)
                u = i; // select vertex with minm distance edge from the current MST
        }

        // include this edge to vertex u
        mSet[u] = true;
        // add its weight 
        res = res + key[u];

        // update the distances if curr distance is less than what was possible through previous edges
        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 && !mSet[v]){
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return res;
}


int main(){
    //input: weighted, connected and undirected graph
    //objective: find its minimum spanning tree
    //prims algo: a greedy algo
    
    //create two sets MST and notInMST to contain vertices
    int V=4;
    vector<int> graph[V] = {{0,5,8,0}, 
                          {5,0,10,15}, 
                          {8,10,0,20}, 
                          {0,15,20,0}};

    cout<<primsAlgo(graph,V); // returns sum of weights in MST

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Edge{
    public:
    int src, dest, weight;
};

class Graph{
    public:
    int V,E;

    Edge* edge;
};

//function to create and return a graph
Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

class subset{
    public:
    int parent;
    int rank;
};

// function to find set of an element i using path compression
int find(subset subsets[], int i){
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
}

// does union by rank
void Union(subset subsets[], int x, int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);
    if(xroot==yroot) return;
    if(subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if(subsets[yroot].rank < subsets[xroot].rank) subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b){
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight; //descending order
}


void addEdge(Graph* graph, int idx, int src, int dest, int weight){
    graph->edge[idx].src = src;
    graph->edge[idx].dest = dest;
    graph->edge[idx].weight = weight;
}

void KruskalMST(Graph* graph){
    int V = graph->V;
    Edge result[V]; // resultant MST
    int e = 0; //index for result
    int i = 0; //index for sorted edges

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp);
    
    subset *subsets = new subset[(V*sizeof(subset))];
    for(int v=0;v<V;v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int res = 0;

    while(e<V-1 && i<graph->E){//we need total V-1 edges
        Edge next_edge = graph->edge[i++];
        int x = find(subsets,next_edge.src);
        int y = find(subsets,next_edge.dest);

        if(x!=y){
            result[e++] = next_edge;
            Union(subsets,x,y);
            res+=next_edge.weight;
        }
    }

    cout<<"Weight of MST is: "<<res<<endl;
    return;
}

int main(){
    int V = 5;
    int E = 7;
    Graph* graph = createGraph(V,E);
    //add edge 0-1
    addEdge(graph,0,0,1,10);
    addEdge(graph,1,0,2,8);
    addEdge(graph,2,1,2,5);
    addEdge(graph,3,1,3,3);
    addEdge(graph,4,2,3,4);
    addEdge(graph,5,2,4,12);
    addEdge(graph,6,3,4,15);

    KruskalMST(graph);

}
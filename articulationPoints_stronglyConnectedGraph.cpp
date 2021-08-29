#include<iostream>
#include<vector>
#include<list>
#define NIL -1
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    // A recursive function that find articulation points using DFS traversal
    // u --> The vertex to be visited next
    // visited[] --> keeps tract of visited vertices
    // disc[] --> Stores discovery times of visited vertices
    // parent[] --> Stores parent vertices in DFS tree
    // ap[] --> Store articulation points
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]); 

    public:
    Graph(int V);
    void addEdge(int v, int w);
    void AP(); //print articulation points
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V]; // make the adj pointer point to a list object
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]){
    static int time = 0; //discovery time and low values
    int children = 0; // count children in DFS tree

    visited[u] = true;

    disc[u] = low[u] = ++time;

    // go through all adjacent vertices to u
    list<int>::iterator i;
    for(i = adj[u].begin(); i!=adj[u].end(); i++){
        int v = *i;
        if(!visited[v]){
            children++;
            parent[v] = u;
            APUtil(v,visited,disc,low,parent,ap);
            
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u] = min(low[u], low[v]);

            //case 1, root has more than 2 children
            if(parent[u]==NIL && children>1)
                ap[u] = true;

            //case 2, not a root and low time of u' child is greater than u
            if(parent[u]!=NIL && low[v]>=disc[u])
                ap[u] = true;
        }
        else if(v!=parent[u]){ // if visited and not the parent
            low[u] = min(low[u], disc[v]);
        }
    }
}

// The function to do DFS traversal. 
// It uses recursive function APUtil()
void Graph::AP()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V]; // To store articulation points

    // Initialize parent and visited, and ap(articulation point) arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    // Now ap[] contains articulation points, print them
    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << " ";
}

// Driver program to test above function
int main()
{
    // Create graphs given in above diagrams
    cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.AP();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();

    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.AP();

    return 0;
}

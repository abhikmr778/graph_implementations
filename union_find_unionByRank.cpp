#include<iostream>

using namespace std;

int find(int parent[],int x){
    if(parent[x]==x)
        return x;
    else return find(parent,parent[x]);
}

void Union(int parent[], int rank[], int x, int y){
    int x_rep = find(parent,x);
    int y_rep = find(parent,y);
    if(x_rep == y_rep) return;
    if(rank[x_rep]<rank[y_rep]) parent[x_rep] = y_rep;
    else if(rank[y_rep]<rank[x_rep]) parent[y_rep] = x_rep;
    else{// rank will increase only if both trees have equal ranks
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}

int main(){
    int n=5;
    int parent[n],rank[n]; // rank is the number of levels in the tree 
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }

    //using corner case
    Union(parent,rank,3,4);
    Union(parent,rank,2,3);
    Union(parent,rank,1,2);
    Union(parent,rank,0,1);

    for(int i=0;i<n;i++){
        cout<<rank[i]<<" "; //highest rank is 1 only because of union by rank
        cout<<endl;
    }
    return 0;
}
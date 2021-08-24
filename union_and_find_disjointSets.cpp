// union and find operations
#include<bits/stdc++.h>

using namespace std;

int find(int parent[], int x){
    if(parent[x]==x){
        return x;
    }
    else{
        return find(parent,parent[x]); // find the parent
    }
}

void Union(int parent[], int x, int y){
    // make root same
    int x_rep = find(parent, x);
    int y_rep = find(parent, y);

    if(x_rep == y_rep) return;
    parent[y_rep] = x_rep;
}

int main(){
    int n = 5;
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    Union(parent,2,3);
    Union(parent,0,2);
    if(find(parent,0)==find(parent,3))
        cout<<"Friends";
    else cout<<"Stangers";
    cout<<endl;
    if(find(parent,0)==find(parent,4))
        cout<<"Friends";
    else cout<<"Stangers";
    cout<<endl;
    Union(parent,3,4);
    if(find(parent,0)==find(parent,4))
        cout<<"Friends";
    else cout<<"Stangers";
    cout<<endl;

    return 0;
}
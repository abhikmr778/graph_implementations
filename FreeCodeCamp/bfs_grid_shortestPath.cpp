#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<char>> mat, int srow, int scol){
    int R = mat.size();
    int C = mat[0].size();
    queue<int> rowq, colq;
    int move_count = 0;
    int nodes_left_in_curr_layer = 1;
    int nodes_in_next_layer = 0;
    bool reached_end = false;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<int> drow = {-1, +1, 0, 0};
    vector<int> dcol = {0, 0, -1, +1};

    // do bfs
    rowq.push(srow);
    colq.push(scol);
    visited[srow][scol] = true;

    while(!rowq.empty()){
        int r = rowq.front(); rowq.pop();
        int c = colq.front(); colq.pop();
        if(mat[r][c]=='E'){
            reached_end = true;
            break;
        }
        //add neighbours
        for(int i=0; i<4; i++){
            int rr = r+drow[i];
            int cc = c+dcol[i];

            if(rr<0 or cc<0) continue;
            if(rr>=R or cc>=C) continue;
            if(visited[rr][cc]==true) continue;
            if(mat[rr][cc]=='#') continue;

            rowq.push(rr);
            colq.push(cc);
            visited[rr][cc] = true;
            nodes_in_next_layer++;
        }
        cout<<"("<<r<<","<<c<<")"<<" ";
        nodes_left_in_curr_layer--;
        if(nodes_left_in_curr_layer==0){
            cout<<endl;
            nodes_left_in_curr_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_count++;
        }

    }
    if(reached_end)
        return move_count;
    else 
        return -1;

}


int main(){
    vector<vector<char>> mat = {
                               {'S', '.', '.', '#', '.', '.', '.'},
                               {'.', '#', '.', '.', '.', '#', '.'},
                               {'.', '#', '.', '.', '.', '.', '.'},
                               {'.', '.', '#', '#', '.', '.', '.'},
                               {'#', '.', '#', 'E', '.', '#', '.'}
                                };

    cout<<shortestPath(mat,0,0)<<endl;
    return 0;
}
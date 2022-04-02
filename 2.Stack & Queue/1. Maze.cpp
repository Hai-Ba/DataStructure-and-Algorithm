/*MAZE
A Maze is represented by a 0-1 matrix aN×M in which ai,j = 1 means cell (i,j) is an obstacle, ai,j = 0 means cell (i,j) is free.
From a free cell, we can go up, down, left, or right to an adjacent free cell.
Compute the minimal number of steps to escape from a Maze from a given cell (i0,j0) within the Maze.

Input
Line 1 contains N,M,i0,j0 (2≤N,M≤900)
Line i+1 (i=1,…,N) contains the ith line of the matrix aN×M
Output
Unique line contains the number minimal of steps to escape the Maze or -1 if no way to escape the Maze.
*/
#include<bits/stdc++.h>
using namespace std;
#define N 1000
#define pii pair<int, int>

int n, m;
int a[N][N];
bool mark[N][N];
int start_row, start_col;
int ans;//number of step
bool foundState;

void Input(){
    cin >> n >> m >> start_row >> start_col;//n is number of row, m is number of column
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
}

bool isFinalState(pii s){
    if(s.first < 1 || s.first > n || s.second < 1 || s.second > m) return true;
    return false;
}

bool isLegalState(pii s){
    if(a[s.first][s.second] == 0 && mark[s.first][s.second] == false) return true;
    return false;
}

void Solve(){
    queue<pii> Q;
    map<pii,int> step;
    pii is = make_pair(start_row, start_col);//initial state
    step[is] = 0;
    Q.push(is);
    while(!foundState){
        pii s = Q.front(); Q.pop();

        //moved up
        pii s_next = make_pair(s.first-1, s.second);
        if(isLegalState(s_next) == true){
            Q.push(s_next);
            step[s_next] = step[s]+1;
            mark[s_next.first][s_next.second] = true;
        }
        if(isFinalState(s_next) == true){
            foundState = true;
            ans = step[s] + 1;
            break;
        }
        //moved down
        s_next = make_pair(s.first+1, s.second);
        if(isLegalState(s_next) == true){
            Q.push(s_next);
            step[s_next] = step[s]+1;
            mark[s_next.first][s_next.second] = true;
        }
        if(isFinalState(s_next) == true){
            foundState = true;
            ans = step[s] + 1;
            break;
        }
        //moved left
        s_next = make_pair(s.first, s.second-1);
        if(isLegalState(s_next) == true){
            Q.push(s_next);
            step[s_next] = step[s]+1;
            mark[s_next.first][s_next.second] = true;
        }
        if(isFinalState(s_next) == true){
            foundState = true;
            ans = step[s] + 1;
            break;
        }
        //moved right
        s_next = make_pair(s.first, s.second+1);
        if(isLegalState(s_next) == true){
            Q.push(s_next);
            step[s_next] = step[s]+1;
            mark[s_next.first][s_next.second] = true;
        }
        if(isFinalState(s_next) == true){
            foundState = true;
            ans = step[s] + 1;
            break;
        }
    }
}

int main(){
    Input();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mark[i][j] = false;
        }
    }
    mark[start_row][start_col] = true;
    foundState = false;
    ans = 0;
    Solve();
    cout << ans;
    return 0;
}

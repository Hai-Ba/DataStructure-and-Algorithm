/*Connected Components
Given a undirected graph G=(V,E) where V={1,…,N} is the number of nodes and the set E has M edges.
Compute number of connected components of G.

Input
Line 1: two positive integers N and M (1≤N≤105,1≤M≤105)
Lline i+1 (i=1,…,M): contains two positive integers u and v which are endpoints of ith edge
Output
Write the number of connected components of G.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;

vector<int> A[MAX];
int N, M;
int color[MAX]; // White is -1; Gray is 0; Black is 1;
int d[MAX], f[MAX], p[MAX];
int t;
int numberOfCC;

void Input(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);//Undirected graph
        A[v].push_back(u);
    }
}

void DFS(int u){
    t  = t + 1;
    d[u] = t;
    color[u] = 0;
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i];
        if(color[v] == -1){
            p[v] = u;
            DFS(v);
        }
    }
    t = t + 1;
    f[u] = t;
    color[u] = 1;
}

void Solve(){
    //Init
    for(int v = 1; v <= N; v++){
        color[v] = -1;
    }
    //Do
    numberOfCC = 0;
    for(int v = 1; v <= N; v++){
        if(color[v] == -1){
            numberOfCC = numberOfCC + 1;
            DFS(v);
        }
    }
    cout << numberOfCC;
}

int main(){
    Input();
    Solve();
    return 0;
}

/*STRONGLY CONNECTED COMPONENTS
Given a directed graph G=(V,E) where V={1,…,N} is the number of nodes and the set E has M arcs.
Compute number of strongly connected components of G
Input
Line 1: two positive integers N and M (1≤N≤105,1≤M≤106)
Lline i+1 (i=1,…,M): contains two positive integers u and v which are endpoints of ith arc

Output
Write the number of strongly connected components of G
*/
#include<bits/stdc++.h>
using namespace std;
const long int N = 1e6+1;

int n, m, numberOfSCC;
vector<int> A[N];
vector<int> A_T[N];
vector<int> X;
bool visited[N];

void Input(){
    //cin >> n >> m;
    scanf("%d %d",&n, &m);//use scanf() will remove TIME LIMITED EXCESS
    for(int i  = 1; i <= m; i++){
        int u, v;
        //cin >> u >> v;
        scanf("%d %d",&u, &v);//use scanf() will remove TIME LIMITED EXCESS
        A[u].push_back(v);
        A_T[v].push_back(u);
    }
}

//first DFS for A
void DFS_1(int u){
    visited[u] = true;
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i];
        if(!visited[v]){
            DFS_1(v);
        }
    }
    X.push_back(u);
    //cout << "Push:" << u << endl;
}

void Solve_DFS_1(){
    //init
    for(int v = 1; v <= n; v++){
        visited[v] = false;
    }
    //do
    for(int v = 1; v <= n; v++){
        if(!visited[v]){
            DFS_1(v);
        }
    }
}

//Second DFS for A_T
void DFS_2(int u){
    visited[u] = true;
    for(int i = 0; i < A_T[u].size(); i++){
        int v = A_T[u][i];
        if(!visited[v]){
            DFS_2(v);
        }
    }
}

void Solve_DFS_2(){
    //init
    for(int v = 1; v <= n; v++){
        visited[v] = false;
    }
    //do
    numberOfSCC = 0;
    cout << "X:";
    for(int e = X.size()-1; e >= 0; e--){
        cout << X[e] << " ";
    }
    cout << endl;
    for(int i = X.size()-1; i >= 0; i--){
        int v = X[i];
        if(!visited[v]){
            //cout << "Consider: " << v << endl;
            numberOfSCC = numberOfSCC + 1;
            DFS_2(v);
        }
    }
    cout << numberOfSCC;
}


int main(){
    Input();
    Solve_DFS_1();
    Solve_DFS_2();
    return 0;
}

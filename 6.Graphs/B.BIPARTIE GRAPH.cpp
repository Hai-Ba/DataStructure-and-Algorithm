/*BIPARTIE GRAPH
Given a undirected graph G=(V,E) in which V={1,…,N} is the set of nodes and |E|=M. You are required to write a program to check if G is a bipartie graph.

Input
Line 1 N and M (1≤N,M≤105)
Line i+1 (i=1,…,M): u and v which are endpoints of the ith edge
Output
Write 1 if G is a bipartie graph and 0, otherwise.
*/
#include<bits/stdc++.h>
using namespace std;
const long int N = 1e5+1;

int n, m; //n is number of nodes, m is number of edges
vector<int> A[N]; // Undirected graph
int d[N]; // d[v] means the level of BFS at node v
bool visited[N]; //visited[v] check if the node v has been visited or not

void Input(){
    //Input for undirected graph
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++){
       cin >> u >> v;
       A[u].push_back(v);
       A[v].push_back(u);
    }
}

bool BFS(int u){
    d[u] = 0;// the level of fist node is 0
    visited[u] = true; //first node has been visited
    queue<int> Q;// Init a queue
    Q.push(u); // put u into Q
    while(!Q.empty()){ //Do loop while Q not empty
        int v = Q.front(); // Declare a variable to store the head of Q before Q.pop()
        Q.pop();
        for(int i = 0; i < A[v].size(); i++){ //Check all node x which adjacent to v
            int x = A[v][i];
            if(!visited[x]){ // if x have not been visited do:
                d[x] = d[v] + 1; // the level of x is increase 1
                Q.push(x); // put x into the Q
                visited[x] = true; // x has been visited
            }
            else{
                if((d[x] + d[v]) % 2 == 0) return false;
            }
        }
    }
    return true;
}

void Solve(){
    for(int v = 1; v <= n; v++){
        visited[v] = false; // Initial the set of node has not been visited
    }
    bool tmp = true;
    for(int v = 1; v <= n; v++){// for all node of set V
        if(!visited[v]){ // if v has not been visited
            tmp = BFS(v);
            if(tmp ==  false) cout << "0" << endl; break;
        }
    }
    if(tmp ==  true) cout << "1" << endl;
}

int main(){
    Input();
    Solve();
    return 0;
}

/*C. ARTICULATION_POINTS_N_BRIDGES
Given an undirected graph containing N vertices and M edges, find all the articulation points and the bridges in the graph.

Input
The first line consists of two space-separated integers denoting N and M. M lines follow, each containing two space-separated integers X and Y denoting there is an edge between X and Y.

Output
One line consists of two integers denoting the number of articulation points and the number of bridges.
*/
#include<bits/stdc++.h>
using namespace std;
const int long long N = 1e5+1;

int n, m; //n is number of verticles(1,2,3,...,n), m is number of edges
vector<int> A[N]; //vector to store node and adjacent node
bool visited[N];
bool articulation[N];// articulation[v] check if v it is an articulation node or not
int t;
int num[N];
int low[N];
int brigdes, articus, root;
int num_child; // variable to check if root has more then 2 child
int p[N];//u = p[v] is parent of node v

void Input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;// Undirected graph
        A[x].push_back(y);
        A[y].push_back(x);
    }
}

void DFS(int s){//s is a node, ps is the parent node of s
    t += 1;
    num[s] = t; // init num[s]
    low[s] = t; // init low[s]
    visited[s] = true;
    for(int i = 0; i < A[s].size(); i++){ //Consider all verticles v adjacent to s
        int v = A[s][i];
        p[v] = s;
        if(v == p[s]) continue; //eject the case that v is the father of s
        if(visited[v]){ //the case that v is the node which has been visited before s
            low[s] = min(low[s],num[v]); //update low[s]
        }
        else{
            if(s == root) num_child += 1; //if root has more than 2 child so root is a articulation point
            DFS(v);
            low[s] = min(low[s], low[v]);//update low for every adjacent node
            if(low[v] > num[s]) brigdes += 1; // condition for an edge to become a brigde
            if(low[v] >= num[s]) articulation[s] = true; // condition for a node to become an articulation point
        }
    }
}

void Solve(){
    for(int v = 1; v <= n; v++){//Initialization
        visited[v] = false;
        articulation[v] = false;
    }
    for(int v = 1; v <= n; v++){
        if(visited[v] == false){
            t = 0;
            num_child = 0;
            p[v] = 0;
            root = v;
            DFS(v); //the node number start from 1;
            if(num_child > 1){
                articulation[v] = true;
            }
            else{
                articulation[v] = false;
            }
        }
    }
    for(int v = 1; v <= n; v++){
        if(articulation[v] ==  true) articus += 1;
    }
}

int main(){
    brigdes = 0;
    articus = 0;
    Input();
    Solve();
    cout << articus << " " << brigdes;
    return 0;
}

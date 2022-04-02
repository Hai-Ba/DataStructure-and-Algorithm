#include<bits/stdc++.h>
#define ull unsigned long long
#define N 100001
using namespace std;


struct Edge{
    int node;
    ull weight;
    Edge(int _node, int _weight){
        node = _node;
        weight = _weight;
    }
};

int n;// number of nodes
vector<Edge> E[N];//E[v].node mean the edge start from the source node to v
                  //E[v].weigth mean the weight from source node to node v
int d[N];//d[v] Store the road from root to v (danh dau neu chua duoc tham)
int MaxWeight, selected_node;

void Input(){
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back(Edge(v, w));
        E[v].push_back(Edge(u, w));
    }
}

void init(){
    MaxWeight = -1;
    selected_node = -1;
    for(int i = 1; i <= n; i++){
        d[i] = -1;
    }
}

int DFS(int u){
    for(int i = 0; i < E[u].size(); i++){
        int v = E[u][i].node;
        if(d[v] == -1){
            d[v] = d[u] + E[u][i].weight;
            if(MaxWeight < d[v]){
                MaxWeight = d[v];
                selected_node = v;
            }
            DFS(v);
        }
    }
    return selected_node;
}

void Solve(){
    //init
    init();
    int s = 1;
    d[s] = 0;
    int x = DFS(s);//DFS 1st time

    init();
    d[x] = 0;
    int y = DFS(x);//DFS 2nd time
    cout << d[y];
}

int main()
{
    Input();
    Solve();
    return 0;
}

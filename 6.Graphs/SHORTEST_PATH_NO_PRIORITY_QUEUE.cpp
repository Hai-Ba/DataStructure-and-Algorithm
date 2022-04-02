#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
const int N = 1e5+1;

struct Edge{
    int node;
    int weight;
    Edge(int _node, int _weight){
        node = _node;
        weight = _weight;
    }
};

int n, m, s, t;
vector<Edge> E[N];
int d[N], p[N];// d[v] lenght of the upper bound of node v, p[v] is the predecessesor of v on the upper bound part
set<int> F;//Set of node that the shortest path is not found

//Input
void Input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back(Edge(v, w));
    }
    cin >> s >> t;
}

//SelectMin
int SelectMin(){
    int minD = INF;
    int sel_node = -1;
    for(set<int>::iterator it = F.begin(); it != F.end(); it++){
        int v = *it;
        if(d[v] < minD){
            minD = d[v];
            sel_node = v;
        }
    }
    return sel_node;
}

//Dijkstra Algor
int Dijkstra(){//return length of shortest distance
    for(int v = 1; v <= n; v++){
        d[v] = INF;
    }
    //init
    d[s] = 0;
    for(int i = 0; i < E[s].size(); i++){
        Edge e = E[s][i];
        int v = e.node;
        d[v] = e.weight;
    }
    for(int v = 1; v <= n; v++){
        if(v != s) F.insert(v);
    }
    //LOOP
    while(F.size() > 0){
        int u = SelectMin();//select a node from F that  d[u] is minimal
        //cout << u << " " << d[u] << endl;
        if(u == t) return d[u];
        F.erase(u);//remove u from F, that have been discover
        for(int i = 0; i < E[u].size(); i++){
            Edge e = E[u][i];
            int v = e.node;
            int w = e.weight;
            //cout << "_" << v << " " << w << " " << d[v] << endl;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                p[v] = u;
                //cout << "_" << v << " " << d[v] << endl;
            }
        }
    }
    return -1;
}




int main(){
    Input();
    cout << Dijkstra();
    return 0;
}

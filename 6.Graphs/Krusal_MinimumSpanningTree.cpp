#include<bits/stdc++.h>
#define ull unsigned long long
#define MAX 100001
using namespace std;

struct Edge{
    int u, v;
    ull w;
    Edge(int _u, int _v, ull _w){
        u = _u;
        v = _v;
        w = _w;
    }
};

int n, m, p[MAX], r[MAX];//n is number of nodes, m is number of edges
vector<Edge> E;

void Input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back(Edge(u, v, w));//can lam 1 constructor de nhap du lieu
    }
}

/*void printEdge(){
    for(int i = 0; i < m; i++){
        cout << E[i].u << " " << E[i].v << " " << E[i].w << endl;
    }
}
*/

bool cmp1(Edge E1, Edge E2){
    return E1.w < E2.w;
}

void makeSet(int x){
    p[x] = x;
    r[x] = 0;
}

int findRoot(int x){
    if(x != p[x]) p[x] = findRoot(p[x]);
    return p[x];
}

void Unify(int u, int v){
    if(r[u] < r[v]){
        p[u] = v;
    }
    else{
        p[v] = u;
        if(r[u] == r[v]) r[u] = r[u] + 1;
    }
}

void Krusal(){
    //Initialize
    for(int i = 1; i <= n; i++){
        makeSet(i);
    }
    ull ans = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int ru = findRoot(E[i].u);
        int rv = findRoot(E[i].v);
        if(ru != rv){
            cnt += 1;
            ans = ans + E[i].w;
            Unify(ru, rv);
        }
        if(cnt == n-1) break;
    }
    cout << ans;
}

int main(){
    Input();
    sort(E.begin(), E.end(), cmp1);
    /*printEdge();*/
    Krusal();
    return 0;
}

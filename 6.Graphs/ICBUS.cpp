#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
const int N = 100001;

struct Arc{
    int stop;
    int weight;
    Arc(int _stop, int _weight){
        stop = _stop;
        weight = _weight;
    }
};

//Variable Declaration
int n, k;//n is number of town(1,2,3,..,n), k is number of road between town
int C[N], D[N];//C[i] is bus fair, D[i] is maximum town that bus at city i can visit
vector<int> A[N];//Store the first graph
vector<Arc> G[N];//Store Build Graph
int d[N], p[N];// d[v] lenght of the upper bound of node v, p[v] is the predecessesor of v on the upper bound part
set<int> F;

//Input
void Input(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> C[i] >> D[i]; //C[i], D[i] index i start from 1 to N
  }
  for(int i = 1; i <= k; i++){
    int a, b;
    cin >> a >> b;
    A[a].push_back(b);
    A[b].push_back(a);
  }
}

//Build Graph G(V,E) such that each arcs (i,j) can go from i to j by the bus
//of city i and, weight is price of bus at city i
void BuildGraph(){
    queue<int> Q;
    int max_town[N];
    for(int i = 1; i <= n; i++){
        int visited[N];
        for(int a = 1; a <= n; a++) visited[a] = 0;//init have not been visit
        visited[i] = 1;//1 mean have visit before
        max_town[i]= D[i];
        Q.push(i);
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            for(int j = 0; j < A[u].size(); j++){//for every node v adjacent to u
                int v = A[u][j];
                if(visited[v] == 0){
                    visited[v] = 1;
                    max_town[v] = max_town[u] - 1;
                    if(max_town[v] < 0) break;
                    Q.push(v);
                    G[i].push_back(Arc(v, C[i]));
                }
            }
        }
    }
/*
    for(int i = 1; i <= n; i++){
        cout << i << ":";
        for(int j = 0; j < G[i].size(); j++){
            cout << G[i][j].stop << "-" << G[i][j].weight << ", ";
        }
        cout << endl;
    }
*/
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

//Dikstra Algo
int Find_Min(){
    int s = 1;
    int t;
    t  = n;
    for(int v = 1; v <= n; v++){
        d[v] = INF;
    }
    d[s] = 0;
    for(int i = 0; i < G[s].size(); i++){
        Arc e = G[s][i];
        int v = e.stop;
        d[v] = e.weight;
    }
    for(int v = 1; v <= n; v++){
        if(v != s) F.insert(v);
    }

    while(F.size() > 0){
        int u = SelectMin();//select a node from F that  d[u] is minimal
        //cout << u << " " << d[u] << endl;
        if(u == t) return d[u];
        F.erase(u);//remove u from F, that have been discover
        for(int i = 0; i < G[u].size(); i++){
            Arc e = G[u][i];
            int v = e.stop;
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

/*Print Graph
void PrintGraph(){
    for(int i = 1; i <= n; i++){
        cout << i << "_" << C[i] << "_" << D[i] << ":";
        for(int j = 0; j < A[i].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
*/

int main(){
    Input();
    //PrintGraph();
    BuildGraph();
    cout << Find_Min();
    return 0;
}

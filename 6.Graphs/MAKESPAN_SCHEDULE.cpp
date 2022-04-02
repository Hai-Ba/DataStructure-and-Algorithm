#include<bits/stdc++.h>
using namespace std;

const int N = 200001;

//Variables declaration
int n;// number of nodes
int m;//for input from job i to j
int d[N];//d[i] mean time duration to complete job i
vector<int> A[N];//store node of graph
int connected_pre[N]; //F[i] mean the time left to execute job i
int F[N]; // F[i] is the earliest time for job i to start

//Input
void Input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
        connected_pre[i] = 0;//Set all time left to execute is 0;
        F[i] = 0; //Init F[i] to make every job has the time to start is 0
    }
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        connected_pre[b] += 1;
        A[a].push_back(b);//Directed graph
    }
}

int Solve(){
    int MaxTime = -1;
    queue<int> Q;
    vector<int> L;

    //TOPO sort(use queue Q and vector L)
    for(int v = 1; v <= n; v++){
        if(connected_pre[v] == 0) Q.push(v);
    }
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        L.push_back(u);
        for(int i = 0; i < A[u].size(); i++){
            int v = A[u][i];
            connected_pre[v] = connected_pre[v] - 1;
            if(connected_pre[v] == 0) Q.push(v);
        }
    }

    //ALGO
    for(int i = 0; i < L.size(); i++){
        int u = L[i];
        MaxTime = max(MaxTime, F[u] + d[u]);
        for(int v = 0; v < A[u].size(); v++){
            F[A[u][v]] = max(F[A[u][v]], F[u] + d[u]);
        }

    }

    return MaxTime;
}

/*PrintGraph
void PrintGraph(){
    for(int i = 1; i <= n; i++){
        cout << i << ":";
        for(int j = 0; j < A[i].size(); j++){
            cout << A[i][j] << ",";
        }
        cout << endl;
    }
}
*/

int main(){
    Input();
    //PrintGraph();
    cout << Solve();
    return 0;
}

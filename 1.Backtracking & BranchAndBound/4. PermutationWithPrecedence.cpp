#include<bits/stdc++.h>
using namespace std;

#define N 20
int n;//length of sequence
int K;//number of pair
int x[N];
bool mark[N];//Marking strategy
int A[N][N];//Mang de luu gia tri truoc va sau

bool Check(int v, int i){
    //return !mark[v];
    if(mark[v] == true) return false;
    for(int j = 1; j <= i-1; j++){//x[j] before x[i]
        if(A[v][x[j]] == 1) return false;
    }
    return true;
}

void Solution(){
    for(int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << "\n";
}

void Try(int i){
    for(int v = 1; v <= n; v++){
        if(Check(v,i)){
            x[i] = v;
            mark[v] = true;
            if(i == n) Solution();
            else{
                Try(i+1);
            }
            mark[v] = false;
        }
    }
}

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            A[i][j] = 0;//
        }
    }
    int K;
    cin >> K;
    for(int k = 1; k <= K; k++){
        int i,j;
        cin >> i >> j;
        A[i][j] = 1;//A[i][j] = 1 mean that i must before j
    }
}

int main(){
    input();
    for(int i = 1; i <= n; i++){
        mark[i] = false;
    }
    Try(1);
    return 0;
}

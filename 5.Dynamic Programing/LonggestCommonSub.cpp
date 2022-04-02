#include<bits/stdc++.h>
using namespace std;
const long int MAX = 1e4+1;

int n, m, ans;
int F[MAX][MAX];
int A[MAX];
int B[MAX];

void Input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    for(int j = 1; j <= m; j++){
        cin >> B[j];
    }
}

void Solve(){
    ans = 0;
    for(int j = 0; j <= m ; j++){
        F[0][j] = 0;
    }
    for(int i = 0; i <= n ; i++){
        F[i][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i] == B[j]){
                F[i][j] = F[i-1][j-1] + 1;
            }
            else{
                F[i][j] = max(F[i-1][j],F[i][j-1]);
            }
            if(F[i][j] > ans){
                ans = F[i][j];
            }
        }
    }
    cout << ans;
}



int main(){
    Input();
    Solve();
    return 0;
}

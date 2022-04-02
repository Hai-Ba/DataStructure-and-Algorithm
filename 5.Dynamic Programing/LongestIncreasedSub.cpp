#include<bits/stdc++.h>
using namespace std;
const long int MAX = 1e4+1;

int n,ans;
int X[MAX];
int F[MAX];


void Input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> X[i];
    }
}


void Solve(){
    F[1] = 1;
    ans = F[1];
    for(int i = 2; i <= n; i++){
        F[i] = 1;
        for(int j = 1; j < i; j++){
            if(X[i] > X[j]){
                F[i] = max(F[i],F[j]+1);
            }
        }
        ans = max(ans, F[i]);
    }
}

int main(){
    Input();
    Solve();
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long int MAX = 1e6+1;

int n, ans;
int A[MAX];
int F_0[MAX];//sum of lagest even_sub
int F_1[MAX];//sum of lagest odd_sub

void Input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
}

void Solve(){
    if(A[i] % 2 == 0){
        F_0[1] = A[i];
        F_1[1] = 0;
    }
    if(A[i] % 2 == 1){
        F_0[1] = 0;
        F_1[1] = ;
    }

    for(int i = 2; i <= n; i++){
        if(A[i] % 2 == 0){
            F_0[i] = F_0[i-1] + A[i];
            F_1[i] = F_1[i-1] + A[i];
        }
        else if(A[i] % 2 == 1){
            F_0[i] = F_1[i-1] + A[i];
            F_1[i] = F_0[i-1] + A[i];
        }

    }
    cout << ans;
}

int main(){
    Input();
    Solve();
    return 0;
}

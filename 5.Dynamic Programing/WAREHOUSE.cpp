/*WAREHOUSE
A truck is planned to arrive at some stations among N stations 1,2,...,N located on a line. Station i (i=1,…,N) has coordinate i and has following information

ai: amount of goods
ti: pickup time duration for taking goods
The route of the truck is a sequence of stations x1<x2<...<xk (1≤xj≤N,j=1,…,k). Due to technical constraints,
the distance between two consecutive stations that the truck arrives xi and xi+1 is less than or equal to D and the total pickup time duration cannot exceed T.
Find a route for the truck such that total amount of goods picked up is maximal.

Input
Line 1: N,T,D (1≤N≤1000,1≤T≤100,1≤D≤10)
Line 2: a1,…,aN(1≤ai≤10)
Line 3: t1,…,tN(1≤ti≤10)

Output
Write the total amount of goods that the truck picks up in the route.
*/

#include<bits/stdc++.h>
using namespace std;
const long int MAX = 1e3 + 1;

int n, T, D, ans;// n is number of station,  T is Maximum time duration,  D is maximum distance between two consecutive point
int a[MAX];
int t[MAX];
int S[MAX][MAX];

void Input(){
    cin >> n >> T >> D;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
}

void Solve(){
    //init
    for(int k = 0; k <= T; k++){
        if(k == t[1]) S[1][k] = a[1];
        else S[1][k] = 0;
    }
    ans = S[1][t[1]];
    //loop
    for(int i = 2; i <= n; i++){
        for(int k = 0; k <= T; k++){
            if(k == t[i]) S[i][k] = a[i];
            else S[i][k] = 0;
            for(int d = 1; d <= D; d++){
                int j = i - d;
                if(j >= 1 && k-t[i] >= 0) S[i][k] = max(S[i][k], S[j][k-t[i]]+a[i]);
            }
            ans = max(ans, S[i][k]);
        }
    }
    cout << ans;
}

int main(){
    Input();
    Solve();
    return 0;
}

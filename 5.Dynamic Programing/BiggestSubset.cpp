/*MAX SUBSEQUENCE
Given an integers sequence a=(a1,a2,…,an). A subsequence of a is defined to be ai,ai+1,…,aj.
The weight of a subsequence is the sum of its elements. Find the subsequence having the highest weight.

Input
Line 1 contains n (1≤n≤106)
Line 2 contains a1,…,an (−500≤ai≤500)
Output
Write the weight of the highest subsequence found.
*/
#include<bits/stdc++.h>
using namespace std;
const long int N = 1000000;

int n, sum;
int a[N];
int F[N];

void Input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void Solve(){
    F[1] = a[1];
    sum = F[1];
    for(int i = 2; i <= n; i++){
        if(F[i-1] > 0){
            F[i] = F[i-1] + a[i];
        }
        else{
            F[i] = a[i];
        }
        if(F[i] > sum){
            sum = F[i];
        }
    }
}

int main(){
    Input();
    Solve();
    cout << sum;
    return 0;
}

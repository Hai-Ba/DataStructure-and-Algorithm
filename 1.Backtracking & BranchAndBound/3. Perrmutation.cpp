#include<bits/stdc++.h>
using namespace std;

#define N 20
int n;//length of sequence
int x[N];
bool mark[N];


bool Check(int v, int i){
    return !mark[v];
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

int main(){
    cin >> n;
    Try(1);
    return 0;
}

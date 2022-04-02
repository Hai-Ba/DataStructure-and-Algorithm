#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull P = 1e9+7;

ull x, N;

ull exp(ull x, ull N){
    x = x%P;
    if(N == 1){
        return x;
    }
    ull t = exp(x, N/2);
    t = (t*t)%P;
    if(N % 2 == 1){// if N is odd so x^N = t*t*x
        t = (t*x)%P;
    }
    return t;
}

void Input(){
    cin >> x >> N;
}

int main(){
    Input();
    cout << exp(x,N);
    return 0;
}

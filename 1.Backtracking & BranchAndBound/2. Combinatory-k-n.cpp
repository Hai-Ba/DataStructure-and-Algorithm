//Combinatory k-n Generation
//Generating all possible selections of combination of k elements from 1,2,...,n
#include<bits/stdc++.h>
using namespace std;

#define N 20
int k;//length of sequene
int n;//the number of value that x[i] can accept
int x[N];
int cnt;

bool Check(int v, int i){
    return v > x[i-1];
}

void Solution(){
    for(int i = 1; i <= k; i++){
        cout << x[i] << " ";
    }
    cout << "\n";
    cnt = cnt + 1;
}

void Try(int i){
    for(int v = 1; v <= n; v++){
        if(Check(v,i)){
            x[i] = v;
            if(i == k) Solution();
            else{
                Try(i+1);
            }
        }
    }
}

int main(){
	cnt = 0;
    cin >> k >> n;
    Try(1);
    cout << cnt;
    return 0;
}

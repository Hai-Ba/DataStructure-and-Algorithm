/*Generating binary sequenxe of lenght n*/
#include <bits/stdc++.h>
#define N 20

using namespace std;

int x[N];
int n;// length of sequence

bool check(int v, int i){
    //Condition for binary without 11
    /*if(v == 1 && x[i-1] == 1){
        return false;
    }*/
    return true;
    //Condition for binary without 11
    //return v + x[i-1] <= 1;
}

void Solution(){
    for(int i = 1; i <= n; i++){
    	//if(x[1] == x[n])// bit dau bit cuoi bang nhau
            cout << x[i];
    }
    cout << "\n";
}

void Try(int i){
    for(int v = 0; v <= 1; v++){
        if(check(v,i)){
            x[i] = v;
            if(i == n){
                Solution();
            }
            else{
                Try(i + 1);
            }
        }
    }
}



int main()
{
    cin >> n;
    Try(1);
    return 0;

}

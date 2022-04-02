/*NURSE
The director of a hospital want to schedule a working plan for a nurse in a given period of N consecutive days 1,..., N.
Due to the policy of the hospital, each nurse cannot work all the days 1,..., N. Instead, there must be days off in which the nurse need to take a rest.
A working plan is a sequence of disjoint working periods. A working period of a nurse is defined to be a sequence of consecutive days on which the nurse
must work and the length of the working period is the number of consecutive days of that working period.

The hospital imposes two constraints:

Each nurse can take a rest only one day between two consecutive working periods. it means that if the nurse takes a rest today, then she has to work tomorrow (1)
The length of each working period must be greater or equal to K1 and less than or equal to K2 (2)
The director of the hospital want to know how many possible working plans satisfying above constraint?
Input
The input consists of one line which contains 3 positive integers N,K1,K2(N≤1000,K1<K2≤400)
Output
The output consists of only one single integer M modulo 109+7 where M is the total working plans satisfying the above constraints.
*/
#include<bits/stdc++.h>
using namespace std;
const long int MAX = 1e3 + 1;

int n, k1, k2, ans;
int S0[MAX];
int S1[MAX];

void Input(){
    cin >> n >> k1 >> k2;
}

void Solve(){
    S0[0] = 1;
    S0[1] = 1;//BT con nho nhat ma co bit cuoi cung la 0
    if(k1 > 1) S1[1] = 0;//BT con nho nhat ma bit cuoi cung bang 1
    else S1[1] = 1;

    for(int i = 2; i <= n; i++){
        S0[i] = S1[i-1];
        int mark = 0;
        for(int j = k1; j <= k2; j++){
            if(i-j < 0) S0[i-j] = 0;
            mark = mark + S0[i-j];
        }
        S1[i] = mark;
    }
    ans = S1[n] + S0[n];
    cout << ans;
}

int main(){
    Input();
    Solve();
    return 0;
}

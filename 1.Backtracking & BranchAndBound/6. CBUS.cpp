/*CBUS
There are n passengers 1,2,…,n. The passenger i want to travel from point i to point i+n(i=1,2,…,n).
There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus).
You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j(i,j=0,1,…,2n).
Compute the shortest route for the bus, serving n passengers and coming back to point 0 without visiting any point more than once (except for the point 0).
*/
#include<bits/stdc++.h>
using namespace std;
#define N 50
#define INF 100000000

int n, k;
int x[N];
int d[N][N];
int f, f_min;//accumulate distance and min distance
int load;//to check number of passenger on bus
int cm;//the smallest i to j distance
bool mark[N];//marking strategy

void Input(){
    cin >> n >> k;//n is number of person, k is the max number of people that bus can handle
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cin >> d[i][j];//the input is a matrix
            if(i!=j && d[i][j] < cm){
                cm = d[i][j];
            }
        }
    }
}

bool Check(int v, int i){
    if(mark[v]) return false;//permutation check
    if(v <= n){
        if(load >= k) return false;//capacity check
        if(mark[v+n] == true) return false;//if mark[v+n] is true mean that the dropup point has been visited
    }
    else{
        if(mark[v-n] == false) return false;//if mark[v-n] is false mean that the pickup point has not been visited
    }
    return true;
}

void findBest(){
    if(f + d[x[2*n]][x[0]] < f_min){
       f_min =  f + d[x[2*n]][x[0]];
    }
}

void Try(int i){
    for(int v = 1; v <= 2*n; v++){
        if(Check(v, i)){
            x[i] = v;
            f = f + d[x[i-1]][x[i]];
            mark[v] = true;
            if(v <= n) load = load + 1;
            else load = load - 1;
            if(i ==  2 * n) findBest();
            else{
                if(f + (2*n-i+1)*cm < f_min){//branch and bound
                    Try(i+1);
                }
            }
            f = f - d[x[i-1]][x[i]];
            mark[v] = false;
            if(v <= n) load = load - 1;
            else load = load + 1;
        }
    }
}

int main(){
    cm = INF;
    for(int i = 1; i <= 2*n; i++){
        mark[i] = false;
    }
    f = 0;
    f_min = INF;
    x[0] = 0;
    mark[0] = true;
    load = 0;

    Input();

    Try(1);
    cout << f_min;
    return 0;
}

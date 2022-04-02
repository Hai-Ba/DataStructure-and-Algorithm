/* TSP
Một người du lịch xuất phát từ thành phố thứ nhất muốn đi thăm quan tất cả n−1 thành phố khác. mỗi thành phố đúng một lần, rồi quay trở lại thành phố xuất phát.

Yêu cầu: Cho biết chi phí đi lại giữa các thành phố, hãy giúp người du lịch tìm hành trình với tổng chi phí là nhỏ nhất.
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100
#define INF 10000000

int x[N];
int n, m;//n is number of points, m is number of connections from point to point
int A[N][N];//Two dimension array to store start point to end point
bool mark[N];//marking strategy
int f, f_min;
int cm; //min element of travelling distance or smallest segment distance

void Input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            A[i][j] = INF;//initialize distance from i city to j city
        }
    }
    for(int v = 1; v <= m; v++){
        int i, j, c;
        cin >> i >> j >> c;
        A[i][j] = c;
        if(c < cm){
            cm = c;
        }
    }
}

bool Check(int v, int i){
    return !mark[v];
}

void updateBest(){
    if(f + A[x[n]][x[1]] < f_min){
        f_min = f + A[x[n]][x[1]];
    }
}

void Try(int i){
    for(int v = 1; v <= n; v++){
        if(Check(v,i)){
            x[i] = v;
            mark[v] = true;
            f = f + A[x[i-1]][x[i]];
            if(i == n) updateBest();
            else{
                if(f+(n-i+1)*cm < f_min){//branch and bound
                    Try(i + 1);
                }
            }
            mark[v] = false;
            f = f - A[x[i-1]][x[i]];
        }
    }
}

int main(){
    Input();
    f = 0;
    f_min = INF;
    for(int v = 1; v <= n; v++){
        mark[v] = false;
    }
    x[1] = 1;
    mark[x[1]] = true;
    Try(2);
    cout << f_min;
    return 0;
}

/*WATER JUGS BFS
There are two jugs, a-litres jug and b-litres jug (a,b are positive integers).
There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.

Input
Unique line contains positive integers a,b,c (1≤a,b,c≤900).

Output
Line contains the minimal number of steps to get c litres or -1 if no solution found.
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int a, b, c;//a is jug a litre, b is jug b litre, c is the litre we must have
bool mark[MAX][MAX];//marking
bool foundState;
int ans;

void Input(){
    cin >> a >> b >> c;
}

bool isFinalState(pair<int,int> s){
    if(s.first == c || s.second == c) return true;
    return false;
}

bool isLegalState(pair<int,int> s){
    if(!mark[s.first][s.second] && s.first <= a && s.second <= b)return true;
    return false;
}

void Solution(){
    queue<pair<int,int>> Q;
    map<pair<int,int>,int> step;

    pair<int,int> is = make_pair(0,0);//is means initial state
    step[is] = 0;
    Q.push(is);
    while(!foundState){
    pair<int,int> s;//s is current state
    s = Q.front(); Q.pop();

    pair<int,int> ns;//ns is new state
    //pour bump->a
    ns = make_pair(s.first+a-s.first,s.second);
    if(isFinalState(ns) == true){
        foundState = true;
        ans = step[s]+1;
        break;
    }
    if(isLegalState(ns) == true){
        Q.push(ns);
        mark[ns.first][ns.second] = true;
        step[ns] = step[s]+1;
    }
    //pour bump->b
    ns = make_pair(s.first,s.second+b-s.second);
    if(isFinalState(ns) == true){
        foundState = true;
        ans = step[s]+1;
        break;
    }
    if(isLegalState(ns) == true){
        Q.push(ns);
        mark[ns.first][ns.second] = true;
        step[ns] = step[s]+1;
    }
    //pour a->b
    if(s.first < b-s.second) ns = make_pair(s.first-s.first,s.second+s.first);
    if(s.first >= b-s.second) ns = make_pair(s.first-(b-s.second),s.second+b-s.second);
    if(isFinalState(ns) == true){
        foundState = true;
        ans = step[s]+1;
        break;
    }
    if(isLegalState(ns) == true){
        Q.push(ns);
        mark[ns.first][ns.second] = true;
        step[ns] = step[s]+1;
    }
    //pour b->a
    if(s.second < a-s.first) ns = make_pair(s.first+s.second,s.second-s.second);
    if(s.second >= a-s.first) ns = make_pair(s.first+a-s.first,s.second-(a-s.first));
    if(isFinalState(ns) == true){
        foundState = true;
        ans = step[s]+1;
        break;
    }
    if(isLegalState(ns) == true){
        Q.push(ns);
        mark[ns.first][ns.second] = true;
        step[ns] = step[s]+1;
    }
    //clear a
    ns = make_pair(s.first-s.first,s.second);
    if(isFinalState(ns) == true){
        foundState = true;
        ans = step[s]+1;
        break;
    }
    if(isLegalState(ns) == true){
        Q.push(ns);
        mark[ns.first][ns.second] = true;
        step[ns] = step[s]+1;
    }
    //clear b
    ns = make_pair(s.first,s.second-s.second);
    if(isFinalState(ns) == true){
        foundState = true;
        ans = step[s]+1;
        break;
    }
    if(isLegalState(ns) == true){
        Q.push(ns);
        mark[ns.first][ns.second] = true;
        step[ns] = step[s]+1;
    }
    }
}

int main(){
    Input();
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            mark[i][j] = false;
        }
    }
    mark[0][0] = true;
    ans = 0;
    foundState = false;
    Solution();
    if(foundState == true){
        cout << ans;
    }
    else{
        cout << "-1";
    }
    return 0;
}

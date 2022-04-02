/* DISJOINT SEGMENT
Given n segments S={1,…,n}. Segment i has left-point coordiate ai and right-point bi. Find a subset of S such that no two segments in S intersect and number of elements of S is maximal.

Input
Line 1: contains a positive integer n (1≤n≤105)
Line i+1 (i=1,…,n): contains ai and bi (0≤ai≤bi≤105)
Output
Write the number of elements of S found.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;

struct Segment{
    int a,b;
};

int n;// number of positive interger
vector<Segment> L;
Segment s[MAX];//array of candidate

void Sort(Segment s[]){
    //greedy 3
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(s[j].b < s[i].b){
                Segment tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}

bool cmp3(Segment x, Segment y){
    return x.b < y.b;
}

void Input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i].a >> s[i].b;
    }
}

bool IsFeasible(vector<Segment> L, Segment x){
    if(L.size() == 0) return true;
    else{
        Segment c = L.back();
        if(x.a > c.b) return true;
        else return false;
    }
}

void Solve(){
    sort(s,s+n,cmp3);
    for(int i = 0; i < n; i++){
        Segment x = s[i];
        if(IsFeasible(L, x)){
            L.push_back(x);
        }
    }
}

int main(){
    Input();
    Solve();
    cout << L.size();

    return 0;
}

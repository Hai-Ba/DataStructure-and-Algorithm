/*JOB PLANNING
Given n jobs J={1,…,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.

Select and schedule a subset of jobs of J such that the total profits is maximal.

Input
Line 1: contains a positive integer n (1≤n≤105)
Line i+1 (i=1,…,n) contains d(i) and p(i) (1≤d(i),p(i)≤105)
Output
Write to total profits obtained from the subset of jobs found.
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 10e5;

struct Job{
    int deadline, profit;
};

int n, sum;
Job J[N];
vector<Job> S;

void Input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> J[i].deadline >> J[i].profit;
    }
}

bool cmp_profit(Job a, Job b){
    return a.profit > b.profit;
}

bool IsFeasible(vector<Job> S, Job x){
    if(S.size() == 0) return true;
    else{
        for(int i = 0; i < S.size(); i++){
            if(x.deadline == S[i].deadline) return false;
        }
        return true;
    }
}

void Solve(){
    sort(J,J+n,cmp_profit);
    for(int i = 0; i < n; i++){
        Job x = J[i];
        if(IsFeasible(S, x)){//check with conditional constrain
            S.push_back(x);
            sum = sum + x.profit;
        }
    }
}

int main(){
    Input();
    Solve();
    cout << sum;
    return 0;
}

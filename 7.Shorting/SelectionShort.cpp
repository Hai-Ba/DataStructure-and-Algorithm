#include<bits/stdc++.h>
using namespace std;
const int N = 101;

int main(){
    int n;
    int A[N];
    cout << "* Selection sort:" << endl;
    cout << "_How many number in array(<100): ";
    cin >> n;
    cout << "_Value for each number: " << endl;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    //Selection Sort(O(n^2))
    cout << "_Sort in decending order:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(A[j] < A[i]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    return 0;
}

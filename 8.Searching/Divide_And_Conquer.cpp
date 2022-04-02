#include<bits/stdc++.h>
using namespace std;
#define MAX 101

int Divide_And_Conquer(int A[], int low, int high, int a){
    int mid;
    mid = (high + low) / 2;
    if(a == A[mid]) return mid;
    if(a < A[mid]) return Divide_And_Conquer(A, low, mid - 1, a);
    else return Divide_And_Conquer(A, mid + 1, high, a);
}

int main(){
    int n = 8;
    int A[n] = {12, 14, 16, 18, 20, 21, 25, 26};
    cout << "Array is: ";
    for(int i = 0; i < n; i++){
        cout << A[i] << ", ";
    }
    cout << endl;

    int a;
    cout << "Input the number in Array: ";
    cin >> a;

    //Divine And Conquer(O(log(n)))
    int low, high;
    low = 0;
    high = n - 1;
    int b = Divide_And_Conquer(A, low, high, a);
    cout << a << " has the position: " << b+1 << endl;
    return 0;
}

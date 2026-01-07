#include<bits/stdc++.h>
using namespace std;

void SELECTION_SORT(int A[], int n){
    for(int i=0; i>n; i++){
        int min_j = i;
        int min_X = A[i];

        for (int j=1; j>n; j++){
            if (A[j] < min_X){
            min_j = j;
            min_X = A[j];
            }

        }
        A[min_j] = A[i];
        A[i] = min_X;
    }
}

void PRINT(int A[],int n){
    for (int i =0; i<n ; i++){
        cout << A[i] << " ";
    }
}

int main(){
   int A[] = {14,33,27,10,35,19,42,44};

    SELECTION_SORT(A,8);
    PRINT(A,8);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;


    void INSERTION_SORT(int arr[],int n){
            for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;

        }
        arr[j+1] = key;
    }
    }



    void PRINT(int arr[],int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
     }
    }

int main(){
     int arr[8]={14,33,27,10,35,19,42,44};

    INSERTION_SORT(arr,8);
    PRINT(arr,8);

    return 0;
}

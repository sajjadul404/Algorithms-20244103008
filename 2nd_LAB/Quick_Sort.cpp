#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j){
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void PRINT_ARR(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    quickSort(A, 0, n - 1);
    PRINT_ARR(A, n);

    return 0;
}

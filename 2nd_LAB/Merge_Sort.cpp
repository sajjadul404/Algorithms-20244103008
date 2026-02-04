#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++) {
        leftArr[i] = A[start + i];
    }

    for (int j = 0; j < len2; j++) {
        rightArr[j] = A[mid + 1 + j];
    }

    int x = 0, y = 0, k = start;

    while (x < len1 && y < len2) {
        if (leftArr[x] <= rightArr[y]) {
            A[k] = leftArr[x];
            x++;
        } else {
            A[k] = rightArr[y];
            y++;
        }
        k++;
    }

    while (x < len1) {
        A[k] = leftArr[x];
        x++;
        k++;
    }

    while (y < len2) {
        A[k] = rightArr[y];
        y++;
        k++;
    }
}

void mergeSort(int A[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);

        merge(A, start, mid, end);
    }
}
int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}

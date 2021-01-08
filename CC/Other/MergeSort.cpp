#include <bits/stdc++.h>
#define LLI int
#define IN_ARR LLI n; cin >> n; LLI arr[n]; for (auto &i: arr) {cin >> i;}
#define OUT_ARR for (auto &i: arr) { cout << i << " ";} cout << "\n";
using namespace std;


void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int left[n1];
    int right[n2];
    for (int i=0;i<n1;i++) {
        left[i] = arr[l+i];
    }
    for (int i=0;i<n2;i++) {
        right[i] = arr[m+1+i];
    }

    int i=0, j=0, c = 0;
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[l + c] = left[i];
            i++;
        } else {
            arr[l + c] = right[j];
            j++;
        }
        c++;
    }

    while (i < n1) {
        arr[l + c] = left[i];
        i++;
        c++;
    }

    while (j < n2) {
        arr[l + c] = right[j];
        j++;
        c++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }

    return;
}


int main() {
    IN_ARR
    mergeSort(arr, 0, n-1);
    OUT_ARR
    return 0;
}
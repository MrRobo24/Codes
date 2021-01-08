#include <bits/stdc++.h>
#define LLI int
#define IN_ARR LLI n; cin >> n; LLI arr[n]; for (auto &i: arr) {cin >> i;}
#define OUT_ARR for (auto &i: arr) { cout << i << " ";} cout << "\n";
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = l;
    int left = l, right = r;
    while (left < right) {
        while (arr[left] <= arr[pivot]) {
            left++;
        }
        
        while (arr[right] > arr[pivot]) {
            right--;
        }

        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }

    swap(arr[right], arr[pivot]);
    
    return right;
}

void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int loc = partition(arr, l, r);
        quickSort(arr, l, loc-1);
        quickSort(arr, loc+1, r);
    }
}


int main() {
    IN_ARR
    quickSort(arr, 0, n-1);
    OUT_ARR
    return 0;
}
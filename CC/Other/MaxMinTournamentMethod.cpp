#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMaxMin(int arr[], int l, int r) {
    if (r - l <= 1) {
        return {max(arr[l], arr[r]), min(arr[l], arr[r])};
    } 

    int m = l + (r-l)/2;
    pair<int,int> a = findMaxMin(arr, l, m);
    pair<int,int> b = findMaxMin(arr, m+1, r);
    return {max(a.first, b.first), min(a.second, b.second)};
}


int main() {

    int n;
    cin >> n;
    int arr[n];
    for (auto &i: arr) {
        cin >> i;
    }

    pair<int, int> maxmin = findMaxMin(arr, 0, n-1);
    cout <<maxmin.first << " " << maxmin.second << "\n";
    return 0;
}
//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI search(vector<LLI>& arr, LLI l, LLI r, LLI k) {
    if (l > r) {
        return -1;
    }

    LLI mid = (l + r) / 2;

    if (arr[mid] == k) {
        return mid;
    }

    if (arr[mid] >= arr[l]) {
        if (k >= arr[l] && k < arr[mid]) {
            return search(arr, l, mid-1, k);
        }

        return search(arr, mid+1, r, k);
    } else {
        if (k > arr[mid] && k <= arr[r]) {
            return search(arr, mid+1, r, k);
        }
        return search(arr, l, mid-1, k);
    }
}



int main() {
    LLI n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector <LLI> arr(n);
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }

    LLI k;
    cout << "Enter element to be searched: ";
    cin >> k;

    LLI index = search(arr, 0, n-1, k);
    if (index != -1) {
        cout << index;
    } else {
        cout << "NOT FOUND";
    }

}

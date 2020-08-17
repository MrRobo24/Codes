/*
Rearrange array such that arr[i] >= arr[j] if i
is even and arr[i]<=arr[j] if i is odd and j < i
*/
#include <bits/stdc++.h>
#define LLI long long

using namespace std;

void rearrange(vector<LLI>& arr) {
    LLI n = arr.size();
    vector<LLI> brr;
    for (auto i: arr) {
        brr.push_back(i);
    }

    sort(brr.begin(), brr.end());

    LLI even = floor(n/2), odd = even - 1;
    for (LLI i=0;i<n;i++) {
        if (i%2 != 0) {
            //even
            arr[i] = brr[even++];
        } else {
            //odd
            arr[i] = brr[odd--];
        }
    }

}

int main() {
    LLI n;
    cin >> n;
    vector<LLI> arr;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        arr.push_back(val);
    }

    cout << "\nINITIAL: ";
    for (auto i: arr) {
        cout << i << " ";
    }
    rearrange(arr);

    cout << "\nFINAL: ";
    for (LLI i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

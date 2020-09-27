#include <bits/stdc++.h>
#define LLI long long

using namespace std;

void solve(vector<LLI> arr, LLI n) {
    LLI counter = n;
    for (LLI i=0;i<n-1;i++) {
        counter = counter - 2;
        if (arr[i] != arr[i+1]) {
            counter++;
            arr[i+1] = arr[i] + arr[i+1];
        }
    }

    cout << counter <<  "\n";
}


int main() {

    LLI t;
    cin >> t;
    while (t--) {
       LLI n;
       cin >> n;
       vector<LLI> arr;
       for (LLI i=0;i<n;i++) {
            LLI val;
            cin >> val;
            arr.push_back(val);
       }

       solve(arr, n);
    }

    return 0;
}

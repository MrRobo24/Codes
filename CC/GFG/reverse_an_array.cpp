#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI n;
    cin >> n;
    vector<LLI> arr;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        arr.push_back(val);
    }

    for (LLI i=0;i<n/2;i++) {
        LLI temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }

    for (LLI i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
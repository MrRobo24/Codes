#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    LLI n;
    cin >> n;
    vector <LLI> arr;
    vector <LLI> freq(n+1,0);
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        arr.push_back(val);
        freq[val] = 1;
    }

    cout << "INITIAL ARR: ";
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << "\n";

    for (LLI i=0;i<n;i++) {
        if (freq[i] != 0) {
            arr[i] = i;
        } else {
            arr[i] = -1;
        }
    }

    cout << "CHANGED ARR: ";

    for (auto i: arr) {
        cout << i <<  " ";
    }

}

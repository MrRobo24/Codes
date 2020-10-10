#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI subArray(vector<LLI> arr, LLI n) {

    for (LLI i=0; i <n; i++) {
        for (LLI j=i; j<n; j++) {
            for (LLI k=i; k<=j; k++) {
                cout << arr[k] << " ";
            }
            cout << "\n";
        }
    }
}

void subSeq(vector<LLI> arr, LLI n) {

    LLI lim = pow(2, n);

    for (LLI i = 1; i < lim; i++) {

        for (LLI j = 0; j < n; j++) {

            if (i & (1<<j)) {
                cout << arr[j] << " ";
            }
        }
        cout << "\n";
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
    cout << "SUBARRAYS:\n";
    subArray(arr, n);
    cout << "SUBSEQUENCES:\n";
    subSeq(arr, n);


    return 0;
}

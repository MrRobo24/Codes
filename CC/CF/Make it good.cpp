#include <bits/stdc++.h>
#define LLI long long
using namespace std;

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

        LLI i=n-1;
        while (i>0 && arr[i] <= arr[i-1]) {
            i--;
        }
        while (i>0 && arr[i] >= arr[i-1]) {
            i--;
        }
        cout << i << "\n\n";


    }

    return 0;

}

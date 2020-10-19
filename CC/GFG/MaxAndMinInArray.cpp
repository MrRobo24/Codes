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

    LLI maxim = INT_MIN, minim = INT_MAX;

    for (LLI i=0;i<n-1;i=i+2) {
        if (arr[i] > arr[i+1]) {

            if (arr[i] > maxim) {
                maxim = arr[i];
            }

            if (arr[i+1] < minim) {
                minim = arr[i+1];
            }

        } else {

            if (arr[i+1] > maxim) {
                maxim = arr[i+1];
            }
            
            if (arr[i] < minim) {
                minim = arr[i];
            }
        }
    }




    cout << "MAXIM: "<< maxim << " MINIM: " <<  minim <<"\n";

    return 0;
}
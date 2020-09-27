//top down approach to solve equal sum partition problem
#include <bits/stdc++.h>
#define LLI long long
using namespace std;


bool equalSumPartition(vector<LLI> &arr, LLI sum, LLI n) {

    if (sum % 2 != 0) {
        return false;
    }

    sum /= 2;
    LLI t[n+1][sum+1];
    for (LLI i=0;i<n+1;i++) {
        t[i][0] = true;
    }
    for (LLI j=1;j<sum+1;j++) {
        t[0][j] = false;
    }

    for (LLI i=1;i<n+1;i++) {
        for (LLI j=1;j<sum+1;j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int main() {

    LLI n,sum = 0;
    vector<LLI> arr;
    cout << "Enter the size of arr: ";
    cin >> n;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        arr.push_back(val);
        sum += val;
    }

    cout << equalSumPartition(arr, sum, n);
    return 0;
}

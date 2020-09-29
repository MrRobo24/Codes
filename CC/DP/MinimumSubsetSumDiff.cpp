#include <bits/stdc++.h>
#define LLI long long

using namespace std;

LLI minimumSubsetSumDiff(vector<LLI> &arr, LLI sum, LLI n) {

    bool t[n+1][sum+1];
    for (LLI i=0;i<n+1;i++) {
        t[i][0] = true;
    }
    for (LLI j=1;j<sum+1;j++) {
        t[0][j] = false;
    }
    for (LLI i=1;i<n+1;i++) {
        for (LLI j=1;j<sum+1;j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }


    vector<LLI> diff;
    for (LLI i=0;i<(sum+1)/2;i++) {
        if (t[n][i]) {
            diff.push_back(sum - 2 * i);
        }
    }

    return *min_element(diff.begin(), diff.end());
}


int main() {
    LLI n, sum = 0;
    cin >> n;
    vector<LLI> arr;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        arr.push_back(val);
        sum += val;
    }


    cout << minimumSubsetSumDiff(arr, sum, n);



    return 0;
}

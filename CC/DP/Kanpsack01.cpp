#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI kanpsack01(LLI* val, LLI* wt,LLI cap, LLI n) {
    if (n == 0 || cap == 0) {
        return 0;
    }

    LLI t[n+1][cap+1];
    for (LLI i=0;i<n+1;i++) {
        t[i][0] = 0;
    }
    for (LLI j=1;j<cap+1;j++) {
        t[0][j] = 0;
    }

    for (LLI i=1;i<n+1;i++) {
        for (LLI j=1;j<cap+1;j++) {
            if (wt[i-1] <= j) {
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][cap];
}


int main() {
    cout << "Enter the number of items: ";
    LLI n, cap;
    cin >> n;
    cout << "Enter the capacity of kanpsack: ";
    cin >> cap;
    LLI wt[n], val[n];
    cout << "Enter the value of all the items: ";
    for (LLI i=0;i<n;i++) {
        cin >> val[i];
    }
    cout << "Enter the weight of all the items: ";
    for (LLI i=0;i<n;i++) {
        cin >> wt[i];
    }

    cout << kanpsack01(val, wt, cap, n) << "\n";
    return 0;
}
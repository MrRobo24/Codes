#include <bits/stdc++.h>
#define LLI long long
using namespace std;

void takeInput(vector<LLI> &arr, LLI n) {
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        arr.push_back(val);
    }
}

void solve(vector<LLI> &a, vector<LLI> &b, vector<LLI> &c, LLI n) {
    LLI currRow = 0, currCol = 0;
    LLI prev = -1;
    while (currCol < n) {

        if (currRow == 0) {
            if (a[currCol] != prev) {
                prev = a[currCol];
                cout << prev << " ";
                currCol++;
                continue;
            } else {
                currRow = 1;
            }
        }


        if (currRow == 1) {
            if (b[currCol] != prev) {
                prev = b[currCol];
                cout << prev << " ";
                currCol++;
                continue;
            } else {
                currRow = 2;
            }
        }

        if (currRow == 1) {
            if (c[currCol] != prev) {
                prev = c[currCol];
                cout << prev << " ";
                currCol++;
                continue;
            } else {
                currRow = 0;
            }
        }
    }
}


int main() {
    LLI t;
    cin >> t;
    while(t--) {
        LLI n;
        cin >> n;
        vector<LLI> a,b,c;
        takeInput(a,n);
        takeInput(b,n);
        takeInput(c,n);

        solve(a,b,c,n);
    }


    return 0;
}

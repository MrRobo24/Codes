#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI cutTheRod(vector<LLI> &lengthSize, vector<LLI> &lengthVal, LLI l) {

    LLI n = lengthSize.size();
    LLI t[n+1][l+1];

    for (LLI i=0;i<n+1;i++)
        t[i][0] = 0;
    
    for (LLI j=0;j<l+1;j++)
        t[0][j] = 0;


    for (LLI i=1;i<n+1;i++) {
        for (LLI j=1;j<l+1;j++) {
            if (lengthSize[i-1] <= j) {
                t[i][j] = max(lengthVal[i-1] + t[i][j- lengthSize[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][l];
}


int main() {

    cout << "Enter the size of length array: ";
    LLI n;
    cin >> n;
    cout << "Enter the lengths:\n";
    vector<LLI> lengthSize;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        lengthSize.push_back(val);
    }

    cout << "Enter corresponding values:\n";
    vector<LLI> lengthVal;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        lengthVal.push_back(val);
    }

    cout << "Enter total length of the rod: ";
    LLI l;
    cin >> l;

    cout << "Calculating maximum obtainable value by cutting the rod...\n";
    cout << cutTheRod(lengthSize, lengthVal, l);

    return 0;
    
}

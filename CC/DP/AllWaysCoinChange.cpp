#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI change(LLI amount, vector<LLI>& coins) {


    LLI n = coins.size();
    LLI t[n+1][amount+1];
    for (LLI i=0;i<n+1;i++) {
        t[i][0] = 1;
    }

    for (LLI j=1;j<amount+1;j++) {
        t[0][j] = 0;
    }

    for (LLI i=1;i<n+1;i++) {
        for (LLI j=1;j<amount+1;j++) {
            if (coins[i-1] <= j) {
                t[i][j] = t[i][j - coins[i-1]] +  t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    for (LLI i=0;i<n+1;i++) {
        for (LLI j=0;j<amount+1;j++) {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }

    return t[n][amount];
}




int main() {

    LLI amount,n;
    vector<LLI> coins;

    cout << "Enter the length of arr: ";
    cin >> n;

    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        coins.push_back(val);
    }

    cout << "Enter the amount: ";
    cin >> amount;

    cout << change(amount, coins);

    return 0;

}

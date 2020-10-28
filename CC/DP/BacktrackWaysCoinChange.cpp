#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI coinChange(vector<LLI>& coins, LLI amount) {
    LLI n = coins.size();
    LLI t[n+1][amount+1];
    for (LLI i=0;i<amount+1;i++) {
        t[0][i] = INT_MAX;
    }
    for (LLI i=1;i<n+1;i++) {
        t[i][0] = 0;
    }
    t[0][0] = 1;
    for (LLI i=1;i<amount+1;i++) {
        if (i % coins[0] == 0) {
            t[1][i] = i / coins[0];
        } else {
            t[1][i] = INT_MAX;
        }
    }

    for (LLI i=2;i<n+1;i++) {
        for (LLI j=1;j<amount+1;j++) {
            if (coins[i-1] <= j) {
                t[i][j] = min(t[i][j - coins[i-1]] + 1, t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    vector<LLI> ans;
    LLI i = n, j = amount;
    while (j != 0) {
        if (coins[i-1] <= j && t[i][j-coins[i-1]] == t[i][j] - 1) {
            //checking if this element is optimal for answer
            ans.push_back(coins[i-1]);
            j = j - coins[i-1];
        } else {
            //not counting this element of array
            i--;
        }
    }
    cout << "ANS: ";
    for (LLI i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return (t[n][amount] == INT_MAX ? -1 : t[n][amount]);
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

    cout << coinChange(coins, amount);

    return 0;

}

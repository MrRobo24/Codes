#include <bits/stdc++.h>
#define LLI long long
#define D double
#define PI 3.141592653589793
using namespace std;

LLI cat[5];

LLI solve(LLI prices[][5], LLI days, LLI t, LLI n) {
    if (days == 0 || n == 0) {
        return INT_MAX;
    }

    LLI res[5];
    for (LLI i=t;i<5;i++) {
        res[i] = INT_MAX;
    }

    LLI ans = 0;
    
    for (LLI i=t;i<5;i++) {
        // cout << days << "\n";
        if (days >= cat[i]) {
            res[i] = min( min(   prices[n-1][i] + solve(prices, days - cat[i], t, n),

                            solve(prices, days, t+1, n)), 

                            solve(prices, days, 0, n-1) );
        } else {
            break;
        }
    }

    ans = solve(prices, days, 0, n-1);

    // cout << "RES ";
    // for (LLI i=0;i<5;i++) {
    //     cout << res[i] << " ";
    // }
    // cout << "\n";
    ans = min(ans,*min_element(res, res+5)) ;
    //cout << "CHECK " << ans << "\n";
    return ans;
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (LLI i=0;i<5;i++) {
        cin >> cat[i];
    }
    LLI n;
    cin >> n;

    LLI prices[n][5];
    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<5;j++) {
            cin >> prices[i][j];
        }
    }

    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<5;j++) {
            cout << prices[i][j] << " ";
        }
        cout << "\n";
    }

    LLI m;
    cin >> m;
    LLI arr[m];
    vector<LLI> days;
    
    for (LLI i=0;i<m;i++) {
        cin >> arr[i];
    }

    // cout << "\n";
    // for (LLI i=0;i<m;i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    
    LLI day = 1;
    for (LLI i=1;i<m;i++) {
        if (arr[i] != arr[i-1] + 1) {
            days.push_back(day);
            day = 1;
        } else {
            day++;
        }
    }
    days.push_back(day);

    LLI res = 0;
    for (LLI i=0;i<(LLI)days.size();i++) {
        //cout << days[i] << "\n";
        res += solve(prices, days[i], 0, n);
    }

    cout << res << "\n";
    return 0;
}
#include <bits/stdc++.h>
#define LLI long long
#define D double
#define PI 3.141592653589793
using namespace std;


D round(D val) { 
    D ans = (LLI)( (100 * val) + 0.5); 
    return (D)ans / 100; 
} 

D solve(D prices[], D prcnt[], LLI curr, LLI n, LLI k, D a) {
    
    if (n <= 0 || curr >= k || a <= 0) {
        return 0;
    }

    curr++;

    D val = 0;
    if (prices[n-1] <= a) {
        D prof =  ((D)prcnt[n-1]/100)*(curr * prices[n-1]);
        prof = round(prof);
        //cout << prof << "\n";

        D take =  prof + (D)solve(prices, prcnt, curr, n-1, k, a - (prices[n-1]));
        take = round(take);
        D dont = solve(prices, prcnt, 0, n-1, k, a);
        dont = round(dont);
        
        val = max(take, dont);
        // if (take > dont) {
        //     cout << "CURR " << curr << " "<< prices[n-1] << " " << a - prices[n-1] << "\n";
        // }
        
    } else {
        val = (LLI)solve(prices, prcnt, 0, n-1, k, a);
        val = round(val);
    }

    return val;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI n, k;
    D a;

    cin >> n >> k >> a;

    D prices[n], prcnt[n];
    for (LLI i=0;i<n;i++) {
        cin >> prices[i];
    }

    for (LLI i=0;i<n;i++) {
        cin >> prcnt[i];
    }

    cout << solve(prices, prcnt, 0, n, k, a) << "\n";



    // for (LLI i=1;i<=n;i++) {
    //     for (LLI j=1;j<=a;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    

    return 0;
}
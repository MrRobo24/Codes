#include <bits/stdc++.h>
#define LLI long long
#define D double
#define PI 3.141592653589793
using namespace std;

priority_queue<pair<D,D> > data;

D round(D val) { 
    D ans = (LLI)( (100 * val) + 0.5); 
    return (D)ans / 100; 
} 

void solve(LLI n, LLI k, D a) {

    D cost = 0;
    D prof = 0;

    while (!data.empty()) {
        pair<D,D> curr = data.top();
        data.pop();
        D prcnt = curr.first;
        D price = curr.second;
        for (LLI c=1;c<=k;c++) {
            if (cost + price <= a)  {
                cost += round(price);
                prof += round(  round((D)prcnt/100)*price);
            } else {
                cout << (LLI)prof << "\n";
                return;
            }
        }
    }
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

    // bool flag = false;
    // for (LLI i=0;i<n;i++) {
    //     for (LLI j=i+1;j<n;j++) {
    //         if (prcnt[j] > prcnt[i]) {
    //             flag = true;
    //             swap(prcnt[j], prcnt[i]);
    //             swap(prices[j], prices[i]);
    //         }
    //     }

    //     if (!flag) {
    //         break;
    //     }
    // }

    
    for (LLI i=0;i<n;i++) {
        data.push({prcnt[i],prices[i]});
    }

    for (LLI i=0;i<n;i++) {
        cout << prices[i] << " " << prcnt[i] << "\n";
    }


    solve(n, k, a);

    // for (LLI i=1;i<=n;i++) {
    //     for (LLI j=1;j<=a;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    

    return 0;
}
//WA & TLE
#include <bits/stdc++.h>
#define LLI long long
using namespace std;
LLI n, q, s, gMax = INT_MIN;
LLI arr[100000];

LLI solve(LLI l, LLI r) {
    LLI curr = 1, ans = INT_MIN;
    //cout << l << " " << r << "\n";
    for (LLI i=l;i<=r;i++) {
        LLI prev = arr[i];
        curr = 1;
        for (LLI j=i+1;j<=r;j++) {
            if (arr[j] > prev) {
                curr++;
                prev = arr[j];
            }

            if (arr[j] == gMax && j+1 <= r) {
                prev = arr[j+1];
                ans = max(curr, ans);
                curr = 1;
            }
        }
        ans = max(curr, ans);
    }

    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q >> s;
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
        gMax = max(arr[i], gMax);
    }

    //gMax = *max_element(arr, arr+n);

    LLI ans = 0;
    while (q--) {
        LLI x, y, l, r;
        cin >> x >> y;
        l = ((x + (s*ans) - 1) % n);
        r = ((y + (s*ans) - 1) % n);
        
        if (l > r) {
            swap(l,r);
        }

        ans = solve(l,r);
        //cout << "MY ANS FOR " << x << " " << y << "\n";
        cout << ans << "\n";
    }


    return 0;
}

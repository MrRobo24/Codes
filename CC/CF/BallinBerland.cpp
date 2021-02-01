//AC LATER
#include <bits/stdc++.h>
#define LLI int64_t
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI a,b,k;
        cin >> a >> b >> k;
        LLI arr[a], brr[b], ans = 0;
        pair<LLI, LLI> edge[k];
        memset(arr, 0, sizeof(arr));
        memset(brr, 0, sizeof(brr));
        
        for (LLI i=0;i<k;i++) {
            cin >> edge[i].first;
        }
        for (LLI i=0;i<k;i++) {
            cin >> edge[i].second;
        }

        for (LLI i=0;i<k;i++) {
            arr[edge[i].first-1]++;
            brr[edge[i].second-1]++;
        }


        for (LLI i=0;i<k;i++) {
            ans += k - (arr[edge[i].first-1] + brr[edge[i].second-1] - 1);
        }

        cout << ans/2 << "\n";
    }


    return 0;
}
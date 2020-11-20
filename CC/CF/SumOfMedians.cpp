#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, k, l;
        cin >> n >> k;
        l = n*k;
        LLI arr[l];
        for (LLI i=0;i<l;i++) {
            cin >> arr[i];
        }
        
        LLI set = ceil((double)n/2);
        LLI gap = n - set + 1;
        LLI c = 0, sum = 0;
        LLI i = l;
        //cout << "SOLVING\n";

        while (c < k) {
            i = i-gap;
            sum += arr[i];
          //  cout << arr[i] << " ";
            c++;
        }

        cout << sum << "\n";

    }
}
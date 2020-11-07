//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI arr[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }

        sort(arr, arr+n);
        LLI c = 0, i=n-1;
        while (i>0) {
            LLI res = abs(arr[i]-arr[i-1]);
            if (res) {
                c += min(arr[i-1], arr[i]);
                arr[i-1] = res;
                i--;
            } else {
                c += arr[i];
                i-=2;
            }
        }

        if (i == 0) {
            c += arr[0];
        }

        cout << c << "\n";
    }
}

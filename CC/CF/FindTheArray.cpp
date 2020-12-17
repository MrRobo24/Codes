//WA
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI arr[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }

        LLI brr[n];
        brr[0] = arr[0];
        for (LLI i=1;i<n;i++) {
            if (arr[i] > brr[i-1]) {
                brr[i] = brr[i-1] * (LLI)(arr[i] / brr[i-1]);
            } else {
                brr[i] = brr[i-1] / (LLI)(brr[i-1] / arr[i]);

                if (brr[i-1] % arr[i] == 0) {
                    brr[i] = brr[i-1] / (LLI)(brr[i-1] / arr[i]);
                } else {
                    brr[i] = brr[i-1] / ceil( (double)brr[i-1] / arr[i]);
                }
            }
        }

        for (LLI i=0;i<n;i++) {
            cout << brr[i] << " ";
        }
        cout << "\n";
        

    }


    return 0;
}
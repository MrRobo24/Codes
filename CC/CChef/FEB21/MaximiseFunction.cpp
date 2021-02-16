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

        cout << 2*(*max_element(arr, arr+n)-*min_element(arr, arr+n)) << "\n";
    }

    return 0;
}

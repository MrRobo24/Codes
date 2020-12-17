//AC
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


        for (LLI i=0;i<n/2;i++) {
            cout << arr[i] << " " << arr[n-i-1] << " ";
        }
        if (n%2 != 0) {
            cout <<  arr[n/2];
        }
        cout << "\n";
    }


    return 0;
}
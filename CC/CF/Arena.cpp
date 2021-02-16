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
       sort(arr, arr+n);
       LLI ans = -1;
       for (LLI i=0;i<n-1;i++) {
           if (arr[i] != arr[i+1]) {
               break;
           }
           ans--;
       }
       
       //cout << "ANS " << ans << "\n";

    //    1 1 3 3 7

       if (n + ans < 0) {
           cout << 0 << "\n";
       } else {
           cout << n + ans << "\n";
       }
       

    }

    return 0;
}

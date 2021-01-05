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
        
        LLI one = 0, two = 0;
        for (LLI i=0;i<n;i++) {
            if (arr[i] == 1) {
                one++;
            } else {
                two++;
            }
        }

        two = two % 2;


        if (two == 0) {
            one = one % 2;
            if (one == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (one < two) {
                cout << "NO\n";
            } else {
                one -= 2*two;
                one = one % 2;
                
                if (one != 0) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                }


            }
        }
        


    }

    return 0;
}
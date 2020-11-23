//Incomplete
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, k;
        cin >> n >> k;
        string a, b;
        cin >> a;
        cin >> b;

        if (a == b) {
            cout << "Yes\n";
            continue;
        } 

        LLI flag = 0;

        for (LLI i=0;i<n-1;i++) {
            if (a[i] != b[i]) {
                if (a[i+1] == b[i]) {
                    char ch = a[i+1];
                    a[i+1] = a[i];
                    a[i] = ch;
                } else if (a[i+1] == a[i] && b[i+1] == b[i] && a[i] != 'z') {
                    while (i < n-1 && a[i+1] == a[i] && b[i+1] == b[i] && a[i] != 'z') {
                        a[i] = b[i];
                        i++;
                    }
                    if (i == n) {
                        a[i] = a[i-1];
                    } else {
                        flag = 1;
                        break;
                    }
                } else {
                    flag = 1;
                    break;
                }
            }
        }


        if (flag) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
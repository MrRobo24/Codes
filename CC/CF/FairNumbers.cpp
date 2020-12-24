//AC - Overhyped about it
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

        while (true) {
            LLI cp = n;
            bool flag = true;
            while (cp != 0) {
                if (cp%10 >= 2 && n % (cp%10) != 0) {
                    flag = false;
                    break;
                }
                cp /= 10;
            }
            if (flag) {
                break;
            } else {
                n++;
            }   
        }

        cout << n << "\n";
    }

    return 0;
}
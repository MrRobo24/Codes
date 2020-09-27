#include <bits/stdc++.h>
#define LLI long long

using namespace std;
int main() {
    LLI t;
    cin >> t;
    while(t--) {
        LLI maxlen = INT_MIN;
        LLI len = 0;
        string s;
        cin >> s;
        LLI x;
        cin >> x;
        LLI n = s.size();
        bool flag = true;
        vector<char> arr(n, 'x');
        for (LLI i=0;i<n;i++) {
            char ch = s[i];
            if (i-x >= 0 && i+x >= n) {
                //left exists
                if (ch == '1') {
                    if (arr[i-x] == '0') {
                        flag = false;
                        cout << -1 << "\n";
                        break;
                    }

                    arr[i-x] = '1';
                } else {
                    if (arr[i-x] == '1') {
                        flag = false;
                        cout << -1 << "\n";
                        break;
                    }
                    arr[i-x] = '0';
                }

            } else if (i-x < 0 && i+x < n) {
                //right exists
                if (ch == '1') {
                    if (arr[i+x] == '0') {
                        cout << -1 << "\n";
                        break;
                    }
                    len = i + x;
                    arr[i+x] = '1';
                } else {
                    if (arr[i+x] == '1') {
                        flag = false;
                        cout << -1 << "\n";
                        break;
                    }
                    len = i + x;
                    arr[i+x] = '0';
                }

            } else if (i-x >= 0 && i+x < n) {
                //both exist

                if (ch == '1') {
                    if (arr[i-x] == '0' && arr[i+x] == '0') {
                        flag = false;
                        cout << -1 << "\n";
                        break;
                    }

                    if (arr[i-x] == '0') {
                        len = i + x;
                        arr[i+x] = '1';
                    } else if (arr[i+x] == '0') {
                        arr[i-x] = '1';
                    } else {
                        arr[i-x] = '1';
                        arr[i+x] = '1';
                    }

                } else {
                    if (arr[i-x] == '1' && arr[i+x] == '1') {
                        flag = false;
                        cout << -1 << "\n";
                        break;
                    }

                    if (arr[i-x] == '1') {
                        len = i + x;
                        arr[i+x] = '0';
                    } else if (arr[i+x] == '1') {
                        arr[i-x] = '0';
                    } else {
                        arr[i-x] = '0';
                        arr[i+x] = '0';
                    }
                }


            } else {
                //none exist
                if (ch == '1') {
                    flag = false;
                    cout << -1 << "\n";
                    break;
                }
            }

            maxlen = max(len, maxlen);
        }
        string ans = "";
        for (LLI i=0;i<n;i++) {
            if (arr[i] == 'x') {
                cout << -1 << "\n";
                flag = false;
                break;
            } else {
                ans += arr[i];
            }
        }
            //cout << "ANS: ";
            if (flag)
                cout << ans  << "\n";

    }

    return 0;
}

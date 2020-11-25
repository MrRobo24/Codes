#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
        if (n == 1) {      
            return "1";
        }
        
        string curr = countAndSay(n-1);
        //cout << curr << "CHECK\n";
        char ch = curr[0];
        string ans = "";
        int count = 1;

        for (int i=1;i<curr.size();i++) {
            //cout << "COUNT\n";
            if (ch == curr[i]) {
                count++;
            } else {
                ans = ans + (char)(count + '0');
                ans = ans + (ch);
                ch = curr[i];
                count = 1;
            }
        }

        ans += char(count + '0');
        ans += ch;
        cout << "ANS: " << ans << "\n";
        
        return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countAndSay(n) << "\n";
}
#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";
#define rep(i, start, end) for (i=start;i<end;i++)
#define v1(T) vector<T>
#define v2(T) vector< vector<T> > 

using namespace std;

void print(LLI t, LLI out) {
    cout << "Case #" << t << ": " << out << "\n";
}

void solve() {
    LLI t, tt;
    cin >> t;
    
    rep(tt, 1, t+1) {
        LLI x, y;
        string s;
        cin >> x >> y >> s;
        LLI n = s.size();
        char curr=' ', prev=' ';
        LLI sum = 0;
        // cout << s << " IN\n";
        for (LLI i=0;i<n;i++) {

            curr = s[i];
            if (curr == '?') {
                LLI j=i;
                while (j < n && s[j] == '?') {
                    j++;
                }

                if (j == n) {
                    break;
                }

                curr = s[j];

                if (prev == 'C' && curr == 'J') {
                    sum += x;
                } else if (prev == 'J' && curr == 'C') {
                    sum += y;
                }

                i = j;
                // cout << prev << " CHECKIN " << curr << "\n";
                // cout << sum << "\n";
                prev = curr;
            } else {

                if (prev == 'C' && curr == 'J') {
                    sum += x;
                } else if (prev == 'J' && curr == 'C') {
                    sum += y;
                }

                // cout << prev << " CHECKOUT " << curr << "\n"; 
                // cout << sum << "\n";
                prev = curr;
            }
        
        }


        print(tt, sum);
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
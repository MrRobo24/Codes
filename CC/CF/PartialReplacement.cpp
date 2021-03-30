#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";
#define rep(i, start, end) for (i=start;i<end;i++)
#define repn(i, start, end) for (i=start;i>=end;i--)
#define v1(T) vector<T>
#define v2(T) vector< vector<T> > 

using namespace std;

void solve() {
    
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, k;
        string s;
        cin >> n >> k >> s;
        LLI c = 1;
        LLI i = s.find_first_of('*');
        while (i < n) {
            LLI j = min(i + k, n-1);
            while (j > i) {
                if (s[j] == '*') {
                    c++;
                    break;
                }
                j--;
            }

            if (j > n || j == i) {
                break;
            }

            i = j;
        }

        cout << c << "\n";
        
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
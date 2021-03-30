#include <bits/stdc++.h>
#define LLI unsigned long long
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
        LLI n, m, x;
        cin >> n >> m >> x;
        
        x--;
        LLI col = x / n;
        LLI ex = x % n;

        LLI ans = (ex * m) + (col + 1);

        cout << ans << "\n";
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
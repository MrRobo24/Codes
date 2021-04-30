//AC
#include <bits/stdc++.h>
#define LLI long long
#define MOD 1000000007
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

LLI complement(LLI n) {
   LLI bits = floor(log2(n))+1;
   return ((1 << bits) - 1) ^ n;
}

void solve() {
    
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, k;
        cin >> n >> k;
        LLI p = 1;
        for (LLI i=0;i<k;i++) {
            p = (p%MOD * n % MOD)%MOD;
        }
        cout << p << "\n";
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
//AC
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
        cin >> n >> k;
        LLI arr[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }

        LLI l = 0, r = n-1;
        while (l < r && k > 0) {
            while (l < r && arr[l] == 0) {
                l++;
            }
            if (l == r) {
                break;
            }
            arr[l]--;
            arr[r]++;
            k--;
        }   

        for (const auto &e: arr) {
            cout << e << " ";
        } 
        cout << "\n";
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
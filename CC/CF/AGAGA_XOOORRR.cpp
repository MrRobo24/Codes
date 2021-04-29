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
        LLI n;
        cin >> n;
        LLI arr[n];
        LLI prexor[n+1];
        prexor[0] = 0;
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            prexor[i+1] = prexor[i] ^ arr[i];
        }

        LLI left = 0, right = 0;
        for (LLI i=0;i<n-1;i++) {
            left = prexor[i+1];
            right = left ^ prexor[n];

            if (left == right) {
                cout << "YES\n";
                left = -1;
                break;
            } else if (i < n-2) {
                for (LLI j=i+1;j<n-1;j++) {
                    if (prexor[i+1] == (prexor[j+1] ^ prexor[i+1]) && prexor[i+1] == (prexor[j+1] ^ prexor[n])) {
                        
                        cout << "YES\n";
                        left = -1;
                        break;
                    }
                }
                
                if (left == -1) {
                    break;
                }
            }

        }

        if (left != -1) {
            cout << "NO\n";
        }

    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
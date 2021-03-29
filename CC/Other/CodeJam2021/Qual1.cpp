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
        LLI n;
        cin >> n;
        v1(LLI) arr(n);
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }

        LLI sum = 0;
        for (LLI i=0;i<n-1;i++) {
            LLI minim = INT_MAX, k = -1;
            for (LLI j=i;j<n;j++) {
                if (minim > arr[j]) {
                    minim = arr[j];
                    k = j;
                }
            }

            sum += k - i + 1;
            reverse(arr.begin()+i, arr.begin()+k+1);

            // for (auto &e: arr) {
            //     cout << e << " ";
            // }
            // cout << "CHECK\n";
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
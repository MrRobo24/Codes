//AC
#include <bits/stdc++.h>
#define LLI long long
#define LLD long double
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

void print(LLI t, long double out) {
    cout << "Case #" << t << ": " << out << "\n";
}

void solve() {
    LLI t, tt;
    cin >> t;
    
    rep(tt, 1, t+1) {
        LLI n, k;
        cin >> n >> k;
        set<LLI> st;
        for (LLI i=0;i<n;i++) {
            LLI val;
            cin >> val;
            st.insert(val);
        }
        LLI prev = *st.begin()-1, maxim = 0, second = 0;
        for (const auto &e: st) {
            LLI curr = e - prev - 1;
            if (curr >= maxim) {
                second = maxim;
                maxim = curr;
            } else if (curr > second) {
                second = curr;
            }
            prev = e;
        }

        LLI ending = k -  *st.rbegin();
        LLI starting = *st.begin() - 1;

        LLI a = ceil((LLD)starting) + ceil((LLD)ending);
        LLI b = ceil((LLD)starting) + ceil((LLD)maxim/2);
        LLI c = ceil((LLD)ending) + ceil((LLD)maxim/2);
        LLI d = ceil((LLD)maxim/2) + ceil((LLD)second/2);
        LLI e = maxim;

        // cout << a << " " << b << " " << c << " " << d << "\n";

        LLI sum = max(max(max(max(a, b), c), d), e);

        print(tt, (long double)sum/k);

    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
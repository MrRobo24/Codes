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

void print(LLI t, v1(LLI) v) {
    cout << "Case #" << t << ": ";
    for (auto &e: v) {
        cout << e << " ";
    }
    cout << "\n";
}

LLI calc(LLI n, v1(LLI) arr) {

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
        
    return sum;
}

LLI cc, ttt;
bool flag = false;

void rec(vector<LLI> temp, uset<LLI> st, LLI s, LLI n) {
    if (s == n) {
        LLI res = calc(n, temp);
        if (res == cc) {
            print(ttt, temp);
            flag = true;
            return;
        }
        
    }
    for (LLI i=1;i<=n;i++) {
        if (st.find(i) != st.end()) {
            continue;
        }
        temp[s] = i;
        st.insert(i);
        rec(temp, st,  s+1, n);
        if (flag) {
            return;
        }
    }
}


void solve() {
    LLI t, tt;
    cin >> t;
    
    rep(tt, 1, t+1) {

        LLI n, c;
        cin >> n >> c;
        

        LLI upper = (n * (LLI)(n+1)/2) - 1;

        if (c < n-1 || c > upper) {
            cout << "Case #" << tt << ": " << "IMPOSSIBLE" << "\n";
            continue;
        }

        v1(LLI) arr(n);
        cc = c;
        ttt = tt;
        flag = false;
        
        uset<LLI> st;
        rec(arr, st, 0, n);
            
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
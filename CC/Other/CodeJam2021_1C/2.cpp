//Didn't submit
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

bool checkRoaring(string num) {
    LLI n = num.size();
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        LLI number = atoll(num.c_str());
        if (number % 10 == 1 + number/10) {
            return true;
        } else {
            return false;
        }
    }
    for (LLI i=1;i*i<=n;i++) {
        if (n % i == 0) { //possible segment size
            bool flag = true;
            LLI prev = atoll((num.substr(0, i)).c_str());
            // cout << prev << " PREV\n";
            LLI j=i;
            while (j < n) {
                string cString = num.substr(j, i);
                
                LLI curr = atoll(cString.c_str());

                // cout << curr << " ";
                if (curr - prev != 1) {
                    flag = false;
                    break;
                }

                prev = curr;
                j += i;
            }

            if (flag) {
                return true;
            }
        }
    }

    return false;
}

void solve() {
    LLI t, tt;
    cin >> t;
    
    rep(tt, 1, t+1) {
        string num;
        cin >> num;
        cout << checkRoaring(num) << "\n";
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}
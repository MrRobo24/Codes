//TLE
#include <bits/stdc++.h>
#define LLI long long int

using namespace std;

LLI n,k;
int func(vector<LLI>& arr, LLI m, unordered_map<LLI,LLI> f) {
    if (n == 0 || m == n) {
        return 0;
    }

    if (f[arr[m]] == 0) {
        // new member
        f[arr[m]]++;
        cout << arr[m] << "DIVING\n";
        return func(arr, m+1, f);
    } else {
        // repeated member
        if (f[arr[m]] == 1) {
            f[arr[m]]++;
            LLI inc = 2 + func(arr, m+1, f);
            f.clear();
            f[arr[m]]++;
            LLI kick = k + func(arr, m+1, f);

            cout << inc << " " << kick <<"\n";
            return min(inc, kick);

        } else {
            f[arr[m]]++;
            LLI inc = 1 + func(arr, m+1, f);
            f.clear();
            f[arr[m]]++;
            LLI kick = k + func(arr, m+1, f);

            cout << inc << " " << kick <<"\n";
            return min(inc, kick);

        }
    }

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        unordered_map<LLI, LLI> f;
        cin >> n >> k;
        vector<LLI> arr(n);
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }
        cout << k + func(arr, 0, f) << "\n";
    }




    return 0;
}

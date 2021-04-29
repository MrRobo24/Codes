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

LLI n;
LLI arr[100];

int dp[101][200001];

void modifyArr() {
    for (LLI i=0;i<n;i++) {
        arr[i] /= 2;
    }
}

bool checkSeq(LLI pos, LLI sum) {

    if (pos >= n || sum < 0) {
        return false;
    }

    if (dp[pos+1][sum] != -1) {
        return dp[pos+1][sum];
    }

    if (arr[pos] == sum) {
        return true;
    }
    
    if (sum < arr[pos]) {
        return  dp[pos+1][sum] = checkSeq(pos+1, sum);
    }
    
    return  dp[pos+1][sum] = ((checkSeq(pos+1, sum - arr[pos]) || checkSeq(pos+1, sum)));
}

void solve() {
    
    
    cin >> n;
    LLI sum = 0;
    LLI oddidx = -1;
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] % 2 != 0) {
            oddidx = i;
        }
    }

    // cout << sum << "\n";
    // cout << oddidx << "\n";

    if (sum % 2 != 0) {
        cout << 0 << '\n';
        return;
    }

    dp[0][0] = 1;
    memset(dp, -1, sizeof(dp));
    for (LLI i=1;i<=n;i++) {
        dp[i][0] = 0;
    }

    for (LLI i=1;i<=sum;i++) {
        dp[0][i] = 0;
    }


    if (!checkSeq(0, sum/2)) {
        cout << 0 << "\n";
        return;
    }


    if (oddidx != -1) {
        cout << 1 << "\n" << oddidx+1 << "\n";
        return;
    }

    while (true) {
        modifyArr();
        for (LLI i=0;i<n;i++) {
            if (arr[i] % 2 != 0) {
                cout << 1 << "\n" << i+1 << "\n";
                return;
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}


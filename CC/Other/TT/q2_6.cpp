#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI n;
    cin >> n;

    vector<LLI> arr(n);
    loop_arr(arr, n);

    if (n < 2) {
        cout << 0 << "\n";
        return 0;
    }
    LLI minim = *min_element(all(arr));
    LLI maxim = *max_element(all(arr));
    LLI range = maxim - minim + 1;
    vector<LLI> buck(range, INT_MIN);

    for (const auto &e: arr) {
        LLI idx = e - minim;
        buck[idx] = e;
    }

    LLI dmax = INT_MIN, prev = 0;
    for (LLI i=0;i<range;i++) {
        if (buck[i] != INT_MIN) {
            dmax = max(buck[i] - prev, dmax);
            prev = buck[i];
        }
    }

    cout << dmax << "\n";



    return 0;

}
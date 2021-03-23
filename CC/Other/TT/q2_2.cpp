#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";

using namespace std;

void shuffle(vector<LLI> &arr, LLI n) {
    srand(time(0));
    vector<LLI> ans(n);
    uset<LLI> st;
    cout << "Random Indices: ";
    for (LLI i=0;i<n;i++) {
        LLI r = rand() % n;
        while (st.find(r) != st.end()) {
            r = rand() % n;    
        }
        st.insert(r);

        ans[r] = arr[i];
        cout << r << " ";
    }    

    arr = ans;
    
    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI n;
    cin >> n;
    vector<LLI> arr(n);
    loop_vec(arr, n);

    shuffle(arr, n);

    cout << "Output arr: ";
    for (const auto &e: arr) {
        cout << e << " ";
    }
    cout << "\n";

    return 0;

}
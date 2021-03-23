#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";

using namespace std;

unordered_map<char, LLI> srank;

bool compare(const pair<char, LLI> &one, const pair<char, LLI> &two) {
    if (srank[one.first] < srank[two.first]) {
        return true;
    } else if (srank[one.first] > srank[two.first]) {
        return false;
    } 

    return one.second < two.second;
 }

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI n;
    cin >> n;

    vector< pair<char, LLI> > arr(n);

    for (LLI i=0;i<n;i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    srank['h'] = 1;
    srank['s'] = 2;
    srank['d'] = 3;
    srank['c'] = 4;

    sort(all(arr), compare);

    for (const auto &e: arr) {
        cout << "(" << e.first << ", " << e.second << ") ";
    }
    cout << "\n";



    return 0;

}
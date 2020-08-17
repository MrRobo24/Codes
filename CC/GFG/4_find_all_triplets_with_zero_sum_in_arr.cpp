#include <bits/stdc++.h>
#define LLI long long

using namespace std;

void zeroTriplet(vector<LLI>& arr) {
    LLI n = arr.size();
    unordered_map<LLI,LLI> freq;
    for (auto i: arr) {
        freq[i]++;
    }

    for (LLI i=0;i<n-2;i++) {
        LLI curr = arr[i];
        freq[curr]--;
        for (LLI j=i+1;j<n;j++) {
            freq[arr[j]]--;
            if (freq[0 - curr - arr[j]] == 1) {
                cout << curr << " "
                << arr[j] << " "
                << 0 - curr - arr[j] << "\n";
                break;
            }
            freq[arr[j]]++;
        }
    }
}


int main() {

    LLI n;
    cin >> n;
    vector<LLI> arr;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        arr.push_back(val);
    }

    cout << "\nINITIAL ARRAY: ";
    for (auto i: arr) {
        cout << i << " ";
    }

    cout << "\n";
    zeroTriplet(arr);




    return 0;
}

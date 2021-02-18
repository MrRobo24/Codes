//7
#include <bits/stdc++.h>
#define LLI long long

using namespace std;

void print(vector<LLI> arr) {
    
    for (const auto &i: arr) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {

    LLI n;
    cin >> n;
    
    vector<LLI> arr(n);

    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << "OUTPUT:\n";
    print(arr);
    while (next_permutation(arr.begin(), arr.end())) {
        print(arr);
    }

    return 0;
}
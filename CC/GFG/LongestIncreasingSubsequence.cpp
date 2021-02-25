#include <bits/stdc++.h>
#define LLI long long 
using namespace std;

LLI find(vector<LLI>& arr, LLI l, LLI r, LLI key) {
    //finding the number which is just greater or 
    //equal to the key or arr[i]
    //to replace it with arr[i]
    while (r-l > 1) {
        LLI mid = l + (r-l)/2;
        if (arr[mid] >= key) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return r;
}


LLI lisFunc(vector<LLI>& arr) {
    LLI n = arr.size();
    
}


int main() {
    LLI n;
    cin >> n;
    vector<LLI> arr(n);
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << lisFunc(arr) << "\n";


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        
        if (n == 1) {
            cout << arr[0] << "\n";
            continue;
        }
        int t = arr[n-1];
        for (int i=n-1;i>0;i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = t;
        for (int i=0;i<n;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
	return 0;
}
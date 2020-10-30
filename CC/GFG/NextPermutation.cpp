#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI arr[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }
        
        LLI i=n-1,j=n-1;
        for (;i>0;i--) {
            if (arr[i] > arr[i-1]) {
                i--;
                break;
            }
        }
        for (;j>=i;j--) {
            if (arr[j] > arr[i]) {
                break;
            }
        }
        
        swap(arr[i], arr[j]);
        i = i+1;
        j = n-1;
        while(i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        for (LLI i=0;i<n;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
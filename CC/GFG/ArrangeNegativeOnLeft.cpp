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
        
        LLI j=0;
	    for (LLI i=0;i<n;i++) {
            if (arr[i] < 0) {
                swap(arr[j], arr[i]);
                j++;
            }
        }	    

        for (LLI i=0;i<n;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
	}	
	
	return 0;
}
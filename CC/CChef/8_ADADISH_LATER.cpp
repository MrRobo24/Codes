//AC
#include <bits/stdc++.h>
#define  LLI long long int
#define MOD 1000000009
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	LLI t;
	cin >> t;
	while (t--) {
	    LLI n;
	    cin >> n;
	    LLI arr[n];
	    for (LLI i=0;i<n;i++) {
	        cin >> arr[i];
	    }
	       
	    sort(arr, arr+n, greater<LLI>());
	    LLI b1 = 0, b2 = 0;
	    LLI i=0;
	    while (i<n) {
	        if (b1 > b2) {
	            b2 += arr[i];
	        } else {
	            b1 += arr[i];
	        }
	        i++;
	    }
	    
	    cout << max(b1, b2) << "\n";
	    
	}
	return 0;
}

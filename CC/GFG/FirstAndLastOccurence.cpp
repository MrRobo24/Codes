#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
	LLI t;
	cin >> t;
	while (t--) {
	    LLI n, k;
	    cin >> n >> k;
	    LLI arr[n];
	    for (LLI i=0;i<n;i++) {
	        cin >> arr[i];
	    }
	    
	    LLI a = -1, b = -1;
	    LLI l = 0, r = n-1;
	    while (l <= r) {
	        LLI m = l + (r-l)/2;
	        if (arr[m] == k) {
	            cout << m << "FOUND\n";
	           a = m;
	           while (a >= 0 && arr[a] == k) {
	               a--;
	               if (a >= 0 && arr[a] != k) {
	                   a++;
	                   break;
	               }
	           }
	           b = m;
	           while (b < n && arr[b] == k) {
	               b++;
	               if (b < n && arr[b] != k) {
	                   b--;
	                   break;
	               }
	           }
               break;
	        } else if (arr[m] < k) {
	            l = m+1;
	        } else {
	            r = m-1;
	        }
	    }
	    
	    
	    if (a != -1) {
	        cout << a << " " << b << "\n";
	    } else {
	        cout << -1 << "\n";
	    }
	}
	
	return 0;
}
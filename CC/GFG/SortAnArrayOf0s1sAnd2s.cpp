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
	    LLI a = 0, b = 0, c = 0;
	    for (LLI i=0;i<n;i++) {
	        cin >> arr[i];
	        if (arr[i] == 0) {
	            a++;
	        } else if(arr[i] == 1) {
	            b++;
	        } else {
	            c++;
	        }
	    }
	    
	    LLI i=0;
	    while (a-- != 0) {
	        arr[i++] = 0;
	        cout << arr[i-1] << " ";
	    }
	    while (b-- != 0) {
	        arr[i++] = 1;
	        cout << arr[i-1] << " ";
	    }
	    while (c-- != 0) {
	        arr[i++] = 2;
	        cout << arr[i-1] << " ";
	    }
	    cout << "\n";
	    
	    
	}
	
	
	
	return 0;
}
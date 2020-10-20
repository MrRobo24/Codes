/*
Will be using dutch flag method or 
three way partitioning
*/

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
	    LLI a = 0, b = 0, c = n-1;
	    for (LLI i=0;i<n;i++) {
	        cin >> arr[i];
	    }
	    
	    while (b <= c) {
			switch(arr[b]) {
				case 0:
					swap(arr[a++], arr[b++]);
					break;
				case 1:
					b++;
					break;
				case 2:
					swap(arr[b], arr[c--]);
					break;
			}
		}

		for (LLI i=0;i<n;i++) {
			cout << arr[i] << " ";
		}
	    cout << "\n";  
	    
	}
	
	
	
	return 0;
}
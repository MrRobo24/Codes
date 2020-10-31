#include <bits/stdc++.h>
#define LLI long long

using namespace std;

int shortestDistance(vector<string> &s, string word1, string word2) {
	int a = -1, b = -1, n = s.size(), d = INT_MAX;
	for (int i=0;i<n;i++) {
	    
		if (s[i] == word1) {
		    a = i;
		}
	    
		if (s[i] == word2) {
		    b = i;
	    }
	    
		if (a != -1 && b != -1) {
		    d = min(abs(a-b), d);
		}
		    
	}
		
    return d;
}

int main() {

    string word1, word2;
    int n;
    cout << "Enter the length of arr: ";
    cin >> n;
    vector<string> arr(n);
    cout << "Enter the words: ";
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    cout << "Minimum distance: " << shortestDistance(arr, word1, word2) << "\n";
    return 0;
}
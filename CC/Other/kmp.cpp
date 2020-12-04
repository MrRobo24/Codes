#include <bits/stdc++.h> 
#define LLI long long

using namespace std;

void calc(char* p, LLI M, LLI* lps) { 

	LLI l = 0; 

	lps[0] = 0; 
	LLI i = 1; 
	while (i < M) { 
		if (p[l] == p[i]) { 
			l++; 
			lps[i] = l; 
			i++; 
		} else { 
			if (l != 0) { 
				l = lps[l - 1]; 
			} else { 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

void KMPSearch(char* p, char* s) { 
	LLI M = strlen(p); 
	LLI N = strlen(s); 

	LLI lps[M]; 
	calc(p, M, lps); 
	LLI i=0,j=0;
	while (i < N) { 

		if (p[j] == s[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			cout << "Found at: " <<  i - j << "\n"; 
			j = lps[j - 1]; 
		} else if (i < N && p[j] != s[i]) { 
			
			if (j != 0) {
                j = lps[j - 1]; 
            }
				
			else {
                i = i + 1; 
            }
		} 
	} 
} 


int main() { 
	char s[] = "AAARPITSSARPITTIARPIT"; 
	char p[] = "ARPIT"; 

    cout << "STRING: " << s << "\n";
    cout << "PATTERN: " << p << "\n";
	KMPSearch(p, s); 
	return 0; 
} 

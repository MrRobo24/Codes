#include <bits/stdc++.h>
#define LLI int
#define OCC_SIZE 256

using namespace std;

void calcLastOccurrence(LLI* occ, string pat) {

    LLI n = pat.size();
    for (LLI i=0;i<n;i++) {
        occ[pat[i]] = i;
    }
}


void boyerMoorePatternSearch(string txt, string pat) {

    LLI occ[OCC_SIZE] = {-1};
    LLI m = pat.size();
    LLI n = txt.size();

    calcLastOccurrence(occ, pat);

    LLI s = 0;
    while (s + m <= n) {
        LLI j = m-1;
        while (j >= 0 && txt[s + j] == pat[j]) {
            j--;
        }

        if (j < 0) {
            cout << pat << " found at shift = " << s << "\n";
            s += (s+m < n)? m - occ[txt[s + m]] : 1;
        } else {
            s += max(1, j - occ[txt[s+j]]);
        }

    }


}



int main() {

    string txt, pat;
    cout << "Enter the value of text: ";
    getline(cin, txt);
    cout << "Enter the value of pattern: ";
    getline(cin, pat);

    boyerMoorePatternSearch(txt, pat);
    return 0;
}
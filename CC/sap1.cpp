#include <bits/stdc++.h>
#define LLI long long
using namespace std;


bool wrong_code = false;

bool freqCheck(string s) {
    unordered_map<char, LLI> freq;

    vector <string> groups;

    LLI prev = -1;

    for (LLI i=0;i<s.size();i++) {
        freq[s[i]]++;
        if (freq[s[i]] > 3) {
            return false;
        }

        if (!  ((s[i] >= '0' && s[i] <= '9')
        || (s[i]<='z' && s[i]>='a')
        || (s[i]<='Z' && s[i]>='A')
        || s[i] == '_'   ) ) {
            return false;
        }

        if (s[i] == '_' && i - prev == 4) {
            prev = i;
        } else  if (s[i] == '_'){

            //cout << i << " \n";
            wrong_code = true;
            cout << "wrong_code";
            return false;
        }

    }

    if (freq['_'] != 3) {
        return false;
    }



    return true;
}


int main() {

    string input;
    cin >> input;

    bool freqFlag = true;
    freqFlag = freqCheck(input);

    if (!wrong_code) {

        if (freqFlag) {
            cout << "valid";
        } else {
            cout << "invalid";
        }

    }

    return 0;
}
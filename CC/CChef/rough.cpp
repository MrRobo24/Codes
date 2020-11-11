#include <bits/stdc++.h>
#define LLI int
using namespace std;

int main() {

    map<int,int> m;
    
    m[2] = 2;
    m[3] = 3;
    m[9] = 9;
    m[11] = 11;
    m[12] = 12;


    int r = 16;

     if (!m.empty()) {
        map<int,int>::iterator last = m.find(r);
        if (last != m.end()) {
            cout << last->second << "\n";
        } else {
            LLI curr = r;
            while (curr > 0 && m[curr] == 0) {
                curr--;
            }

            if (curr == 0) {
                cout << "NOT FOUND\n";
            } else {
                cout << curr << "FOUND\n";
            }
        }

    }


    return 0;
}
#include<bits/stdc++.h>
#define LLI long long
using namespace std;
LLI A, B;

LLI solve(LLI a, LLI b, LLI c) {

    if (a == c || b == c || a + b == c) {
        return 1;
    }

    if (a == b) {
        return 0;
    }

    if (a == 0) {
        return solve(A, b, c);
    }

    if (b == B) {
        return solve(a, 0, c);
    }
    
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI a, b, c;
        cin >> a >> b >> c;
        A = min(a,b);
        B = max(a,b);
        
        if(solve(min(a,b), max(b,a), c)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
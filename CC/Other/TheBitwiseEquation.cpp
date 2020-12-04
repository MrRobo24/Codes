//Asked in Linkedin Internship Online Round

/*

SUM = XOR + 2*AND

*/

#include <bits/stdc++.h>
#define LLI long long
using namespace std;

void solve(LLI* arr, LLI* brr, LLI n) {
    LLI t = 0;
    vector<LLI> ansX, ansY;
    while (t < n) {
        
        LLI a = arr[t], b = brr[t];
        //cout << a << " " << b << " ab\n";
        LLI A = (LLI)(a - b)/2;
        LLI x = 0, i = 0;
        while (A != 0 || b != 0) {
            LLI bitXor = b & 1;
            LLI bitAnd = A & 1;
            //cout << bitXor << " " << bitAnd << "CHECK\n";

            if (bitAnd && !bitXor) {
                x += pow(2, i);
            } else if (bitAnd && bitXor) {
                ansX.push_back(0);
                ansY.push_back(0);
                break;
            }

            b = b >> 1;
            A = A >> 1;
            i++;
        }

        if (b == 0) {
            ansX.push_back(x);
            ansY.push_back(a - x);
        }

        t++;
    }

    for (LLI i=0;i<n;i++) {
        cout << ansX[i] << " " << ansY[i] << "\n";
    }
    
}

int main() {
    LLI n;
    cin >> n;
    LLI arr[n], brr[n]; 
    for (LLI i=0;i<n;i++) { 
        cin >> arr[i] >> brr[i];
    }
 
    solve(arr, brr, n);
    return 0;
}
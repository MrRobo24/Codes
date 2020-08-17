#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI calcGCD(LLI a, LLI b) {
    if (b == 0) {
        return a;
    }

    return calcGCD(b, a%b);
}


void rotateLeftArr(vector<LLI> &arr, LLI d, LLI n) {
    d = d % n;

    LLI gcd = calcGCD(n, d);
    for (LLI i=0;i<gcd;i++) {
        LLI j = i;
        LLI temp = arr[j];
        while (true) {
            LLI k = j + d;

            if (k >= n) {
                k = k - n;
            }

            if (k == i) {
                break;
            }

            arr[j] = arr[k];
            j = k;

        }

        arr[j] = temp;
    }
}

int main() {

    LLI n, d;
    cin >> n >> d;
    vector<LLI> arr(n);
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }
    rotateLeftArr(arr, d, n);
    for (LLI i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
}

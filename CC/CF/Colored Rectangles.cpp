#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI r,g,b;
    cin >> r >> g >> b;

    vector<LLI> red;
    vector<LLI> green;
    vector<LLI> blue;

    for (LLI i=0;i<r;i++) {
        LLI val;
        cin >> val;
        red.push_back(val);
    }
    for (LLI i=0;i<g;i++) {
        LLI val;
        cin >> val;
        green.push_back(val);
    }
    for (LLI i=0;i<b;i++) {
        LLI val;
        cin >> val;
        blue.push_back(val);
    }

    sort(red.begin(), red.end());
    sort(green.begin(), green.end());
    sort(blue.begin(), blue.end());

    LLI i = r-1, j = g-1, k = b-1;

    LLI area = 0;

    while (true) {

        LLI x = 0;
        LLI y = 0;
        LLI z = 0;
        if (i >= 0) {
            x = red[i];
        }
        if (j >= 0) {
            y = green[j];
        }
        if (k >= 0) {
            z = blue[k];
        }

        LLI a1 = 0, a2 = 0, a3 = 0;
        a1 = x * y;
        a2 = y * z;
        a3 = x * z;

        if (a1 > a2) {
            if (a1 >= a3) {
                i--;
                j--;
                area += a1;
            } else {
                i--;
                k--;
                area += a3;
            }
        } else if (a1 < a2) {
            if (a2 >= a3) {
                j--;
                k--;
                area += a2;
            } else {
                i--;
                k--;
                area += a3;
            }
        } else {
            LLI prevA = 0, prevB = 0, c = 0;

            while (j - c > 0 && k- c > 0 && prevA == prevB) {
                if (j-c>0) {
                    prevA = green[j-(++c)];
                } else {
                    prevA = -1;
                }
                if (k-c>0) {
                    prevB = blue[k-(++c)];
                } else {
                    prevB = -1;
                }
            }

            if (prevA > prevB) {

            }



        }


        if ((i < 0 && j < 0 ) ||
            (j < 0 && k < 0) ||
            (i < 0 && k < 0) ) {
                break;
            }

    }

    cout << area << "\n";
    return 0;


}

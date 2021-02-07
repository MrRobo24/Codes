#include <bits/stdc++.h>
#define LLI long long
#define D double
#define PI 3.141592653589793
using namespace std;

double _gcd(double a, double b) { 
    if (a < b) 
        return _gcd(b, a); 
  
    if (fabs(b) < 0.001) 
        return a; 
  
    else
        return (_gcd(b, a - floor(a / b) * b)); 
} 


int main() {

    LLI r1, r2, s1, s2, t, d;
    cin >> r1 >> r2 >> s1 >> s2 >> t >> d;

    LLI common = r1 + r2 - d;
    if (common < 0) {
        // no intersection
        cout << "no crash\n";
        return 0;
    }

    D leftT = (D)(2 * PI * r1)/s1;
    D rightT = (D)(2 * PI * r2)/s2;

    if (common == 0) {
        // one intersection
        s1 = abs(s1);
        s2 = abs(s2);

        if (t < leftT || t < rightT) {
            cout << "no crash\n";
            return 0;
        }

        LLI gcd = __gcd( (LLI)leftT, (LLI)rightT);
        LLI lcm = (LLI)leftT * (LLI)rightT / gcd;
        if (lcm > t) {
            cout << "no crash\n";
            return 0;
        } else {
            cout << lcm << " E&F\n";
            return 0;
        }

    }

    D leftD = (abs(r1*r1 - r2*r2) + d*d)/(2*d);
    D rightD = abs(d - leftD);

    D alpha = acos((D)leftT/r1);
    D beta = acos((D)rightD/r2);

    D leftDis = (2*alpha) * r1;
    D rightDis = (2*beta) * r2;

    // vector<D> eleft;
    // vector<D> fleft;

    // vector<D> eright;
    // vector<D> fright;

    LLI c = 0;
    if (s1 < 0) {
        leftDis = 2*PI*r1 - leftDis;
    }

    if (s2 < 0) {
        rightDis = 2*PI*r2 - rightDis;
    }

    s1 = abs(s1);
    s2 = abs(s2);

    D time = 0;
    // while (time <= t) {
    //     time += leftT;
    //     eleft.push_back(time);
    //     fleft.push_back(time + (D)leftDis/s1);
    // }

    LLI gcd = _gcd(leftT, (rightT + (D)rightDis/s2));
    LLI lcm = leftT * (rightT + (D)rightDis/s2 ) / gcd;

    if (lcm <= t) {
        cout << lcm << " E\n";
        return 0;
    }
    


    gcd = __gcd( (LLI)leftDis/s1, (LLI)rightT);
    lcm = ((LLI)leftDis/s1) * (LLI)rightT / gcd;

    if (lcm <= t) {
        cout << lcm << " F\n";
        return 0;
    }


    // time = 0;
    // while (time <= t) {
    //     time += rightT;
    //     fright.push_back(time);
    //     eright.push_back(time + (D)rightDis/s2);
    // }

    // for (LLI i=0;i<eleft.size();i++) {
    //     cout << eleft[i] << " " << fleft[i] << "\n";
    // }

    // cout << "\n";

    // for (LLI i=0;i<eright.size();i++) {
    //     cout << eright[i] << " " << fright[i] << "\n";
    // }

    // for (LLI i=0;i<(LLI)eleft.size();i++) {
    //     for (LLI j=0;j<(LLI)eright.size();j++) {
    //         if (floor(eleft[i]) == floor(eright[j])) {
    //             cout << floor(eleft[i]) << " E\n";
    //             return 0;
    //         }
    //     }
    // }

    // for (LLI i=0;i<(LLI)fleft.size();i++) {
    //     for (LLI j=0;j<(LLI)fright.size();j++) {
    //         if (floor(fleft[i]) == floor(fright[j])) {
    //             cout << floor(fleft[i]) << " F\n";
    //             return 0;
    //         }
    //     }
    // }


    return 0;
}
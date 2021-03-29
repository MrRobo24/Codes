#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI n;
    cin >> n;
    LLI petrol[n], distance[n];
    for (LLI i=0;i<n;i++) {
        cin >> petrol[i];
    }

    for (LLI i=0;i<n;i++) {
        cin >> distance[i];
    }

    LLI curr = 0, begin = 0;
    LLI sum = 0;

    for (LLI i=0;i<n;i++) {
        sum += petrol[i] - distance[i];
        curr += petrol[i] - distance[i];
        //cout << sum << " CHECK\n";
        if (curr < 0) {
            //if no petrol is left mid journey
            curr = 0;
            begin = i+1;
        }
    }

    if (sum < 0) {
        cout << "Truck can't complete the journey\n";
    } else {
        cout << "Starting point should be: " << begin << "\n";
    }

    return 0;
}

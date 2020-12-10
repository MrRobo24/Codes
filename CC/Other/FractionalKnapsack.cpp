#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI n;
    cout << "Enter the number of items: ";
    cin >> n;
    LLI weight[n], value[n], cap;
    float vw[n];
    cout << "Enter the weights:\n";
    for (LLI i=0;i<n;i++) {
        cin >> weight[i];
    }
    cout << "Enter the values:\n";
    for (LLI i=0;i<n;i++) {
        cin >> value[i];
        vw[i] = (float)value[i]/weight[i];
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> cap;

    bool sort = false;

    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n-i-1;j++) {
            if (vw[j] < vw[j+1]) {
                sort = true;
                LLI val;
                float ratio;

                ratio = vw[j+1];
                vw[j+1] = vw[j];
                vw[j] = ratio;

                val = value[j+1];
                value[j+1] = value[j];
                value[j] = val;

                val = weight[j+1];
                weight[j+1] = weight[j];
                weight[j] = val;
            }
        }

        if (!sort) {
            break;
        }
    }

    for (LLI i=0;i<n;i++) {
        cout << value[i] << " " << weight[i] << " " << vw[i] << "\n";
    }

    float optimal = 0;
    LLI w = 0;
    for (LLI i=0;i<n;i++) {
        if (w + weight[i] <= cap) {
            w += weight[i];
            optimal += value[i];
        } else {
            LLI left = cap - w;
            optimal += value[i] * ((float)left / (float)weight[i]);
            break;
        }
    }

    cout << "The maximum possible value obtained is: " << optimal << "\n";
    

    return 0;
}
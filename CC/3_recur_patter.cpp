#include <bits/stdc++.h>
#define LLI long long
using namespace std;

void func(LLI n) {

    if (n == 0) {
        return;
    }

    cout << n << " ";
    func(n-1);
    cout << n << " ";
    func(n-1);
    cout << n << " ";
}

int main() {
    func(2);
    return 0;
}

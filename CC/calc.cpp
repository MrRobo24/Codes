#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b;
    cout << "Enter the first number: ";
    cin >> a;
    
    cout << "Enter the second number: ";
    cin >> b;

    char ch;
    cout << "Entet the operation: like +, -, *, /";
    cin >> ch;

    if (ch == '+') {
        cout << "Sum is " << a + b << "\n";
    } else if (ch == '-') {
        cout << "Subtraction is " << a - b << "\n";
    } else if (ch == '*') {
        cout << "Product is " << a * b << "\n";
    } else {
        if (b == 0) {
            cout << "Not possible\n";
        } else {
            cout << "Division is " << a / b << "\n";
        }
    }

    return 0;

}
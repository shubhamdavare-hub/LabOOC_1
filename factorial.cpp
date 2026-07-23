#include <iostream>
using namespace std;

int main() {
    int n;
    long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    while (n > 0) {
        fact = fact * n;
        n--;
    }

    cout << "Factorial = " << fact;

    return 0;
}
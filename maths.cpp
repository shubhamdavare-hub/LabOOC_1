#include <iostream>
using namespace std;

int main() {
    int choice, a, b;

    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    switch(choice) {
        case 1: 
            cout << "Result = " << a + b; 
            break;
        case 2: 
            cout << "Result = " << a - b; 
            break;
        case 3: 
            cout << "Result = " << a * b; 
            break;
        case 4: 
            cout << "Result = " << a / b; 
            break;
        case 5: 
            cout << "Result = " << a % b; 
            break;
        default: 
            cout << "Wrong choice!";
    }

    return 0;
}
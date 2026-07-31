#include <iostream>

int main() {
    int num, reversedNum = 0, remainder;

    std::cout << "Enter an integer: ";
    std::cin >> num;

    int original = num; 

    while (num != 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    std::cout << "Reversed Number = " << reversedNum << std::endl;

    return 0;
}

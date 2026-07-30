#include <stdio.h>

int main() {
    int num;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of negative numbers does not exist.\n");
    } else {
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %lld\n", num, fact);
    }

    return 0;
}
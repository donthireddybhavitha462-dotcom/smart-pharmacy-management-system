#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("===== C Calculator =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("Result = %.2lf\n", result);
            break;

        case 2:
            result = num1 - num2;
            printf("Result = %.2lf\n", result);
            break;

        case 3:
            result = num1 * num2;
            printf("Result = %.2lf\n", result);
            break;

        case 4:
            if (num2 == 0) {
                printf("Error: Cannot divide by zero.\n");
            } else {
                result = num1 / num2;
                printf("Result = %.2lf\n", result);
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

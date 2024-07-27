#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep function, use <windows.h> on Windows

// Function prototypes
void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);

void clear_screen();

int main() {
    int choice;
    double num1, num2;

    while (1) {
        clear_screen();  // Clear the screen

        // Display menu
        printf("====================================\n");
        printf("         Simple Calculator          \n");
        printf("====================================\n");
        printf("Select an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice (1/2/3/4/5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        // Get input numbers
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Perform the operation based on user's choice
        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                if (num2 != 0) {
                    divide(num1, num2);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }

        // Wait for user input before clearing the screen
        printf("\nPress Enter to continue...");
        getchar(); // Clear leftover newline character from buffer
        getchar(); // Wait for user to press Enter
    }

    return 0;
}

// Function to add two numbers
void add(double a, double b) {
    printf("Result: %.2lf\n", a + b);
}

// Function to subtract two numbers
void subtract(double a, double b) {
    printf("Result: %.2lf\n", a - b);
}

// Function to multiply two numbers
void multiply(double a, double b) {
    printf("Result: %.2lf\n", a * b);
}

// Function to divide two numbers
void divide(double a, double b) {
    printf("Result: %.2lf\n", a / b);
}

// Function to clear the screen
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

#include<stdio.h>
#include<math.h>

float function_fx(float x);
void calculate(float error, float f1, float f2, float x1, float x2);

int main() {
    float tolerable_error, x1, x2, f1, f2;
    
    // User input for tolerable error
    printf("Enter tolerable error: ");
    scanf("%f", &tolerable_error);
    
    // User input for initial guesses
    do {
        printf("Enter x1: ");
        scanf("%f", &x1);
        printf("Enter x2: ");
        scanf("%f", &x2);
        f1 = function_fx(x1);
        f2 = function_fx(x2);
    } while (f1 * f2 > 0);

    // Call the bisection method
    calculate(tolerable_error, f1, f2, x1, x2);

    return 0;
}

float function_fx(float x) {
    return (x * x) - 25;
}

void calculate(float error, float f1, float f2, float x1, float x2) {
    float x3, f3;

    do {
        // Calculate midpoint
        x3 = (x1 + x2) / 2;

        // Evaluate function at x3
        f3 = function_fx(x3);

        // Update the interval
        if (f1 * f3 < 0) {
            x2 = x3;
            f2 = f3;
        } else {
            x1 = x3;
            f1 = f3;
        }

    } while (fabsf(f3) > error);

    // Print the result
    printf("The root is %f", x3);
}


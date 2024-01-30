#include<stdio.h>
#include<math.h>

float function_fx(float x);
float derivative_fx(float x);
float calculate(float E, float fx1, float fx1_derivative, float x1);

int main() {
    float E, x1, fx1, fx1_derivative;
    printf("Enter the tolerable error: ");
    scanf("%f", &E);

    do {
        printf("Enter the initial guess x1: ");
        scanf("%f", &x1);
        fx1 = function_fx(x1);
        fx1_derivative = derivative_fx(x1);
    } while (fx1 == 0);

    calculate(E, fx1, fx1_derivative, x1);

    return 0;
}

float function_fx(float x) {
    return (x * x) - 25;
}

float derivative_fx(float x) {
    return 2 * x;
}

float calculate(float E, float fx1, float fx1_derivative, float x1) {
    float x2, fx2;

    do {
        x2 = x1 - (fx1 / fx1_derivative);
        fx2 = function_fx(x2);

        // Display values at each iteration
        printf("x1 = %f, x2 = %f, fx1 = %f, fx2 = %f\n", x1, x2, fx1, fx2);

        x1 = x2;
        fx1 = fx2;
        fx1_derivative = derivative_fx(x2);

        if (fabsf(fx1) <= E) {
            printf("The root is %f\n", x2);
            return x2;  // Added return statement to exit the function
        }
        
    } while (fabsf(fx1) > E);

    return x2;  // Return the result after the loop
}


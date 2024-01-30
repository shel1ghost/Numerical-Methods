#include <stdio.h>
#include <math.h>

float fx(float x);
void calculate(float error, float f1, float f2, float x1, float x2);

int main() {
    float tolerable_error, x1, x2, f1, f2;

    printf("Enter tolerable error: ");
    scanf("%f", &tolerable_error);

    printf("Enter x1: ");
    scanf("%f", &x1);
    printf("Enter x2: ");
    scanf("%f", &x2);
    f1 = fx(x1);
    f2 = fx(x2);

    // Initial output before starting recursion
    printf("f1\tf2\tx1\tx2\n");
    printf("%f\t%f\t%f\t%f\n", f1, f2, x1, x2);

    // Start the recursion
    calculate(tolerable_error, f1, f2, x1, x2);

    return 0;
}

float fx(float x) {
    return (2 * x * x) + (4 * x) - 10;
}

void calculate(float error, float f1, float f2, float x1, float x2) {
    float x3, f3;
    x3 = (x1 * f2 - x2 * f1) / (f2 - f1);
    f3 = fx(x3);

    // Output values at each iteration
    printf("%f\t%f\t%f\t%f\n", f1, f2, x1, x2);

    if (fabsf((x3 - x2) / x3) <= error) {
        printf("The root is %f\n", x3);
    } else {
        // Update values for the next iteration
        x1 = x2;
        x2 = x3;
        f1 = f2;
        f2 = f3;
        
        // Recursive call
        calculate(error, f1, f2, x1, x2);
    }
}


#include <stdio.h>
#include <math.h>

float g(float x);

void calculate(float error, float x1);

int main() {
    float tolerable_error = 0.01;
    float initial_guess;

    printf("Enter the initial guess: ");
    scanf("%f", &initial_guess);

    calculate(tolerable_error, initial_guess);

    return 0;
}

float g(float x) {
    return (x*x - 8) / 6;
}

void calculate(float error, float x1) {
    float x2, err;
    int iteration = 1;

    do {
        x2 = g(x1);
        err = fabs(x2 - x1);

        // Display values at each iteration
        printf("Iteration %d: x1 = %f, x2 = %f, err = %f\n", iteration, x1, x2, err);

        if (err <= error) {
            printf("The root is approximately %f\n", x2);
            return;
        }

        x1 = x2;
        iteration++;
    } while (iteration <= 100); // Added a maximum iteration limit to avoid infinite loops

    printf("The method did not converge within the maximum number of iterations.\n");
}


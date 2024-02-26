#include<stdio.h>
float fx(float x);
float fx_derivative(float x, float h);
int main(){
	  float x, h, result;
	  printf("Enter the value of x and h:\n");
	  scanf("%f%f", &x, &h);
	  result = fx_derivative(x, h);
	  printf("The result is %f\n", result);
}

float fx(float x){
	return x*x;
}

float fx_derivative(float x, float h){
	return (fx(x+h)-fx(x))/h;
}

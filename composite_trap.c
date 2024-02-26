#include<stdio.h>
#include<math.h>
float fx(float x);
int main(){
	float h, b, a, result;
	int n, i;
	printf("Enter the value of a and b: \n");
	scanf("%f%f", &a, &b);
	printf("Enter the value of n: ");
	scanf("%d", &n);
	h = (b-a)/n;
	float x[n];
	float output = fx(a)+fx(b);
	for(i=1; i<n; i++){
		output = output + 2*fx(a+h*i);
	}
	output = (h/2)*output;
	printf("The result is %f\n", output);	
}

float fx(float x){
	return log(x);
}

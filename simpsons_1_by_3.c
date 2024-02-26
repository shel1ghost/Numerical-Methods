#include<stdio.h>
#include<math.h>
float fx(float x);
int main(){
	float n=2, h;
    float x0 = 0, x2 = 2;
    h = (x2-x0)/n;
    float x1 = x0 + h;;
	float output = (h/3)*(fx(x0)+4*fx(x1)+fx(x2));
	printf("The result of integration is  %f\n", output);	
}

float fx(float x){
	return 3*x*x+2*x-5;
}

#include<stdio.h>
#include<math.h>
#define ln(x) log(x)
int main(){
	int n, i;
	float deno, a, b;
	float x[20], y[20], sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter x[%d]: ", i);
		scanf("%f", &x[i]);
        x[i] = ln(x[i]);
	}
	for(i=0; i<n; i++){
		printf("Enter y[%d]: ", i);
		scanf("%f", &y[i]);
        y[i] = ln(y[i]);
	}
	for(i=0; i<n; i++){
		sumx+=x[i];
		sumx2 = sumx2 +x[i]*x[i];
		sumy+=y[i];
		sumxy = sumxy +x[i]*y[i];
	}
	deno = n*sumx2-sumx*sumx;
	b = (n*sumxy-sumx*sumy)/deno;
	a = (sumy-b*sumx)/n;
	a = exp(a);
	
	printf("The equation of line y = %fx ^ %f\n", a, b);
}


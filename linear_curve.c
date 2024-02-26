#include<stdio.h>
int main(){
	int n, i;
	float deno, a, b;
	int x[20], y[20], sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	for(i=0; i<n; i++){
		printf("Enter y[%d]: ", i);
		scanf("%d", &y[i]);
	}
	for(i=0; i<n; i++){
		sumx+=x[i];
		sumx2 = sumx2 +x[i]*x[i];
		sumy+=y[i];
		sumxy = sumxy +x[i]*y[i];
	}
	deno = n*sumx2-sumx*sumx;
	if(deno == 0){
		printf("The solution does not exist!");
	}else{
		b = (n*sumxy-sumx*sumy)/deno;
		a = (sumy-b*sumx)/n;
	}
	printf("The equation of line is y = %f + %fx\n", a, b);
}

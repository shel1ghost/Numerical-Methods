#include<stdio.h>
float fx(float x, float y);
int main(){
	   float x[20], y[20], h, xp, n, m1, m2, m3, m4;
	   int i;
	   printf("Enter x0 and y0:\n"); //0, 1
	   scanf("%f%f", &x[0], &y[0]);
	   printf("Enter the value of h and xp (calculation point):\n");  //0.1, 1
	   scanf("%f%f", &h, &xp);
	   n = (xp-x[0])/h;
	   for(i=0; i<=n; i++){
	   		y[i+1]=y[i]+h*fx(x[i], y[i]);
			x[i+1]=x[0]+h;
			printf("%0.1f\t%f\n", x[i], y[i]);
	   }
	                                                             
}
float fx(float x, float y){
	return (x+y);
}

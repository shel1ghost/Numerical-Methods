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
			x[i+1]=x[i]+h;
			m1=fx(x[i], y[i]);
			m2=fx((x[i]+h/2), (y[i]+(m1*h)/2));
			m3=fx((x[i]+h/2), (y[i]+(m2*h)/2));
			m4=fx(x[i]+h, y[i]+m3*h);
			y[i+1]=y[i]+h/6*(m1+2*m2+2*m3+m4);
			printf("%0.1f\t%f\n", x[i], y[i]);
	   }
	                                                             
}
float fx(float x, float y){
	return (x+y);
}


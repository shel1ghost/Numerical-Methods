#include<stdio.h>
#include<math.h>
#define f1(x, y, z) (17-y+2*z)/20
#define f2(x, y, z) (-18-3*x+z)/20
#define f3(x, y, z) (25-2*x+3*y)/20;
int main(){
	   float e, x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3;
	   int count = 1;
	   printf("Enter tolerable error: ");
	   scanf("%f", &e);
	   printf("\nCount\tx\ty\tz");
	   do{
	   	x1 = f1(x0, y0, z0);
	   	y1 = f2(x1, y0, z0);
	   	z1 = f3(x1, y1, z0);
	   	printf("\n%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);
	   	e1 = fabs(x0-x1);
	   	e2 = fabs(y0-y1);
	   	e3 = fabs(z0-z1);
	   	count++;
	   	x0=x1;
	   	y0=y1;
	   	z0=z1;
	   }while(e1>e && e2>e && e3>e);
	   printf("\n x=%0.3f, y=%0.3f and z=%0.3f\n", x1, y1, z1);
}

/* Equations:
	   20x+y-2z = 17
	   3x+20y-z=-18
	   2x-3y+10z=25
	   Arranging in diagonally dominant form:
	   x=(17-y+2z)/20;
	   y=(-18-3x+z)/20;
	   z=(25-2x+3y)/20;
	*/

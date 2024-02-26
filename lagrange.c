#include<stdio.h>
int main(){
	  int n, i, j;
	  float xi[10], yi[10], x, y, l;
	  printf("Enter the data available: ");
	  scanf("%d", &n);
	  printf("Enter the value for x:\n");
	  for(i=1; i<=n; i++){
	  	scanf("%f", &xi[i]);
	  }
	  printf("Enter the value for y:\n");
	  for(i=1; i<=n; i++){
	  	scanf("%f", &yi[i]);
	  }
	  printf("Enter the value of x for which y is to be calculated: ");
	  scanf("%f", &x);
	  y = 0;
	  for(i=1; i<=n; i++){
		  l = 1;
		  for(j=1; j<=n; j++){
		  	if(i != j){
		  		l = l*(x-xi[j])/(xi[i]-xi[j]);
		  	}
		  }
		  y = y+l*yi[i];
	  }
	  printf("The interopolated value is: %f\n", y);
}

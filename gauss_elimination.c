#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, i, j, k;
	float ratio, x[20], a[20][20];
	printf("Enter the order of matrix: ");
	scanf("%d", &n);
	printf("Enter the augmented matrix:\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n+1; j++){
			scanf("%f", &a[i][j]);
		}
	}
	
	for(j=1; j<=n; j++){
		if(a[j][j] == 0){
			printf("Error");
			exit(0);
		}
		for(i=1; i<=n; i++){
			if(i>j){
				ratio = a[i][j]/a[j][j];
				for(k=1; k<=n+1; k++){
					a[i][k] = a[i][k] - ratio*a[j][k];
				}
			}
		}
	}
	x[n] = a[n][n+1]/a[n][n];
	for(i=n-1; i>=1; i--){
		x[i] = a[i][n+1];
		for(j=i+1; j<=n; j++){
			x[i] = x[i]-a[i][j]*x[j];
		}
		x[i] = x[i]/a[i][i];
	}
	printf("The result is:\n");
	for(i=1; i<=n; i++){
		printf("x[%d] = %f\n", i, x[i]);
	}
}

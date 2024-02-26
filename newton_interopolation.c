#include<stdio.h>
#include<math.h>

int main(){
  float x[20], y[20], d[20][20], xint, yint, a[20], p;
  int i, j, n;
  
  printf("Enter the number of data: ");
  scanf("%d", &n);
  
  for(i=1; i<=n; i++){
    printf("Enter the value of X[%d]: ", i);
    scanf("%f", &x[i]);
    printf("Enter the value of Y[%d]: ", i);
    scanf("%f", &y[i]);
  }
  
  yint = y[1];
  
  printf("Enter the value of x at which interpolation is to be done: ");
  scanf("%f", &xint);
  
  for(i=1; i<=n; i++){
    d[i][1] = y[i];
  }
  
  for(j=2; j<=n; j++){
    for(i=1; i<=(n-j+1); i++){
      d[i][j] = (d[i+1][j-1] - d[i][j-1]) / (x[i+j-1] - x[i]);
    }
  }
  
  for(j=1; j<=n; j++){
    a[j] = d[1][j];
  }
  
  yint = y[1];
  
  for(i=2; i<=n; i++){
    p = 1;
    
    for(j=1; j<=(i-1); j++){
      p = p * (xint - x[j]);
    }
    
    yint = yint + p * a[i]; // Increment j in this line
  }
  
  printf("The interpolated value is %f\n", yint);

  return 0;
}


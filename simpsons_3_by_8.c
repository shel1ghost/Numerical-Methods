#include<stdio.h>
float fx(float x);
int main(){
  float a, b, h, term;
  int i, n;
  printf("Enter the upper limit and lower limit:\n");
  scanf("%f%f", &a, &b);
  printf("Enter number of segments n: ");
  scanf("%d", &n);
  h = (b-a)/n;
  term = fx(a)+fx(b);
  for(i=1; i<n; i++){
    if(i%3 != 0){
      term = term+3*fx(a+i*h);
    }else{
      term = term+2*fx(a+i*h);
    }
  }
  float integration = (3*h)/8*term;
  printf("The result of integration is %f\n", integration);
}
float fx(float x){
  return x*x*x+3*x*x;
}

#include<stdio.h>
#include<math.h>


double nth_rt(int nth, double num)
{
 double m = (1/(double)nth) * log10(num);
 return pow(10.0, m);
}

int main()
{
 int n;
 double p;


 while(scanf("%d %lf", &n, &p) != EOF && n>=1 && n<=200 && p >=1 && p<1.0e+101) {

  printf("%.0lf\n", nth_rt(n, p));

 }
 return 0;
}
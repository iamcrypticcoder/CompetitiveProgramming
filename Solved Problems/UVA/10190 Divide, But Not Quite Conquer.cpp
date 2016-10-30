#include<stdio.h>
#include<math.h>


	     int main()
	     {
		 double n,m,a[100],num;
		 int k,i;
		 while(scanf("%lf%lf",&n,&m)==2)
		 {
		     k=1;
		     num=1;
		     if(fmod(n,m)|| m==1)
			printf("Boring!");

		     else
		     {
			while(num<n) {
			  num=num*m;
			  a[k]=num;
			  k++;
		    }
		    a[0]=1;
			if(num==n) {
			 printf("%.0lf",a[k-1]);
			 for(i=k-2;i>=0;i--)
			   
			   printf(" %.0lf",a[i]);
			}

		     else
			 printf("Boring!");
		     }
		     printf("\n");
		 }
		 return 0;
	     }


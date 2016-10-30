#include <iostream>
#include <stdio.h>
//#include <conio.h>

using namespace std;

unsigned long lowerlimit, upperlimit;
unsigned long g=0, a[10000000][2];
unsigned long A, L;


unsigned long stepof(unsigned long num)
{
 unsigned long step=1;
 
 unsigned long x = num;

 while(x != 1) {
	 x = (x%2)== 0 ? x/2 : 3*x+1;
	 if(x > L) break;
	 step++;
 }

 return step;
}

void swap(unsigned long *a, unsigned long *b)
{
 unsigned long temp;
 temp = *a;
 *a = *b;
 *b = temp;

}

int main()
{
unsigned long i, max;


	for(i=0 ;scanf("%ld %ld", &A, &L) != EOF && A != -1 && L != -1; i++) {
	
		printf("Case %d: A = %ld, limit = %ld, number of terms = %ld\n", i+1, A, L, stepof(A));

		//cout << stepof(A) << "\n";
	}

//getch();

return 0;
}	


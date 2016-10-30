#include <stdio.h>
#include <math.h>

unsigned long old[20000];
int n;

int Match(unsigned long num)
{
	int i;
	for(i=0; i<n-1; i++)
		if(num == old[i])
			return i;
	return 0;

}

int main()
{
 unsigned long Z, I , M , L;

 unsigned long cycle=0;
 unsigned long pri_L;
 unsigned long t_case=0;
 int i;


 while(scanf("%ld %ld %ld %ld", &Z, &I, &M, &L) && Z!=0 && I!=0 && M!=0 && L!=0) {
 pri_L = L;
 old[0] = pri_L;
 n=1;
 cycle = 0;
 t_case++;
 while(1) {
  L = (Z*L + I) % M;
	old[n++] = L;
  cycle++;
	if(i=Match(L))
		break;
	
 }

 printf("Case %ld: %ld\n", t_case, cycle-i);
 }
return 0;
}
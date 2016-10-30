#include <iostream>
//#include <conio.h>
//#include <time.h>
using namespace std;

bool list[1100000];


int Process()
{
 unsigned long  gen_num, num=0, a, b, c, d, e;
 int i, j, k, l, m, n;

 for(i =0; i<10; i++) {
	 a = 100000*i;
	 for(j =0; j<10; j++) {
		 b = 10000*j;
		 for(k =0; k<10; k++) {
			 c = 1000*k;
			 for(l =0; l<10; l++) {
				 d = 100*l;
				 for(m =0; m<10; m++) {
					 e = 10*m;
					 for(n =0; n<10; n++) {
						 num = a + b + c + d +e + n;
						 gen_num = num + (i+j+k+l+m+n);
						 list[gen_num] = 1;
						 //cout << gen_num << "\n";
					 }
				 }
			 }
		 }
	 }
 }

return 0;
}



int main()
{

	unsigned long i;
//	time_t s, e;
//	s = time(NULL);

	Process();
//	cout << GeneratedNumber(987654);

//	cout << "1";
	for(i = 1; i<=1000000; i++)
		if(list[i] == 0)
			printf("%ld\n", i);

//	e  = time(NULL);

//	cout << difftime(e,s);

// getch();
 return 0;
}

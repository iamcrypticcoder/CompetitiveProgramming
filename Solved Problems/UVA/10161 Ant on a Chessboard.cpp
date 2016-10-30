#include <iostream>
#include <math.h>
//#include <conio.h>

using namespace std;

//#define SQR(x) ((x)*(x))

unsigned long SQR(unsigned long num)
{
	return (num*num);
}


int main()
{
	unsigned long num = 22, order, UpperRight, col , row; 
	
	while(cin >> num && num != 0) {
	
		order = (unsigned long)sqrt(num);

		if(SQR((unsigned long)sqrt(num)) != num)
			order += 1;
	

		UpperRight = (SQR(order)-(order-1));

		if(order%2) {
			if(num  > UpperRight) {
				col =  order - labs(num - UpperRight);
				row = order;
			}
			else if(num < UpperRight) {
				col = order;
				row = order - labs(UpperRight - num);
			}
			else
				col = row = order;
		}

		if(!(order %2)) {
			if(num  < UpperRight) {
				col =  order - labs(UpperRight - num);
				row = order;
			}
			else if(num > UpperRight) {
				col = order;
				row = order - labs(num - UpperRight);
			}
			else
				col = row = order;
		}
	cout << col << " " << row << "\n";
	}



//getch();
return 0;
}
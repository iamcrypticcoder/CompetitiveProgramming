#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define maxlength 500
#define max(a,b) ((a) > (b) ? (a) : (b))

class Mbigint {
public:
	int length;
	int digit[maxlength];

	Mbigint(int=0);
	~Mbigint() {}
	void checklength();
	void operator=(long M);
	Mbigint operator+(Mbigint m);
};

void show(Mbigint M);

Mbigint::Mbigint(int v)
{
	(*this)=v;
	//this->checklength();
}

void Mbigint::checklength()
{
 for(;length>0 && digit[length]==0;length--);
}

void Mbigint::operator=(long M)
{
	memset(digit,0, maxlength*sizeof(int));

	for(length=0; M!=0; M /= 10000)
		digit[++length] = M % 10000;
	checklength();
}

Mbigint Mbigint::operator+(Mbigint m)
{
	if (m.length==0)
		return (*this);
	if (length==0)
		return m;

	Mbigint c;
		c.length=max(length,m.length)+1;
		for (int i=1,temp=0;i<=c.length;i++)
			c.digit[i]=(temp=(temp/10000+digit[i]+m.digit[i]))%10000;
		c.checklength();
		return c;

}

void show(Mbigint M)
{
	printf("%d", M.digit[M.length]);

	for(int i=M.length-1; i>=1; i--)
		printf("%04d", M.digit[i]);
}

Mbigint fibo[5000];

int main()
{
	int input;

	fibo[0]= 1;
	fibo[1]= 1;

	for(int i=2; i<5000; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];

	/*for(i=2; i<30; i++) {
		show(fibo[i]);
		cout << "\n";
	}*/

	while(scanf("%d", &input) != EOF) {
		if(input == 0) {
			cout << "The Fibonacci number for 0 is 0\n";
			continue;
		}
		//cout << input;
		show(fibo[input-1]);
		cout << endl;
	}

return 0;
}
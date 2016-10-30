
/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 2, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/

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
	void operator=(char *str);
	void operator=(Mbigint M);
	Mbigint operator+(Mbigint M);
	Mbigint operator*(Mbigint M);
	Mbigint operator*(int M);
	Mbigint operator/(int M);
	Mbigint operator%(int M);

	bool operator<(Mbigint M);
	bool operator<=(Mbigint M);
	bool operator>(Mbigint M);
	bool operator>=(Mbigint M);
	bool operator==(Mbigint M);
	bool operator!=(Mbigint M);

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

void Mbigint::operator=(char *str)
{
	int L = strlen(str), temp = 0, i,j, k;
	length = (L + 3)/4;

	for(i=0;i < L%4; i++)
		temp = temp * 10 + (str[i] - '0');

	digit[length] = temp;

	j=0;
	if(L%4==0) k = length;
	else k = length - 1;
	temp = 0;
	for(i=L%4; i<L; i++) {
		temp = temp * 10 + (str[i] - '0');
		j++;
		if(j%4==0) {
			digit[k--] = temp;
			temp =0;
			j=0;
		}
	}
}

void Mbigint::operator=(Mbigint M)
{
	length = M.length;
	memcpy(digit, M.digit, maxlength*sizeof(int));
	this->checklength();

}
Mbigint Mbigint::operator+(Mbigint M)
{
	if (M.length==0)
		return (*this);
	if (length==0)
		return M;

	Mbigint T;
		T.length=max(length,M.length)+1;
		for (int i=1,temp=0;i<=T.length;i++)
			T.digit[i]=(temp=(temp/10000+digit[i]+M.digit[i]))%10000;
		T.checklength();
		return T;
}

Mbigint Mbigint::operator*(int M)
{
	Mbigint T;
	int temp=0, i;

	T.length = length+2;
	
	for(i=1; i<=T.length; i++)
		T.digit[i] = (temp=(temp/10000+digit[i]*M)) % 10000;
	T.checklength();
	return T;
}

Mbigint Mbigint::operator*(Mbigint M)
{
	int number, i, j, k, temp;
	Mbigint T;

	T.length = length + M.length;

	for(i=1; i<=length; i++) {
		number = digit[i];
		temp  = 0;

		for(j=1; j<=M.length; j++)
			T.digit[i+j-1] += number*M.digit[j];
		if(!(i%10) || i == length)
			for(j=1; j<=T.length; j++)
				T.digit[j] = (temp=(temp/10000)+T.digit[j]) % 10000;
	}
	T.checklength();
	return T;
}


Mbigint Mbigint::operator/(int M)
{
	int temp = 0, i;
	Mbigint T;

	T.length = length;
	for(i=T.length; i>=1; i--)
		T.digit[i] = (temp=(temp%M*10000 + digit[i])) / M;
	T.checklength();
	return T;
}

Mbigint Mbigint::operator%(int M)
{
	int temp=0;
	for(int i = length; i>=1; i--)
		temp = (temp*10000 + digit[i])% M;

	return temp;
}

// COMPARISON FUNCTION START HERE --------------------------------------------

bool Mbigint::operator<(Mbigint M)
{
	if(length != M.length)
		return length < M.length;
	for(int i = length; i>=1; i--)
		if(digit[i] != M.digit[i])
			return digit[i]<M.digit[i];
	return false;
}

bool Mbigint::operator<=(Mbigint M)	{		return !(M<(*this));	}
bool Mbigint::operator>(Mbigint M)		{		return M<(*this);			}
bool Mbigint::operator>=(Mbigint M)	{		return !((*this)<M);	}

bool Mbigint::operator==(Mbigint M)	
{		
	return (!((*this) < M) && (!((*this) > M)));	
}

bool Mbigint::operator!=(Mbigint M)	
{		
	return (((*this) < M) || ((*this) > M));	
}


// PRESENTATION FUNCTION START HERE --------------------------------------------

void show(Mbigint M)
{
	printf("%d", M.digit[M.length]);

	for(int i=M.length-1; i>=1; i--)
		printf("%04d", M.digit[i]);
}

Mbigint fibo[5000];
//double fibo[3000];

int main()
{
	int count, i;
	char str1[105], str2[105];
	Mbigint zero, a, b;
	

	fibo[0]= 1;
	fibo[1]= 2;

	for(i=2; i<5000; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];

	/*for(i=2; i<30; i++) {
		show(fibo[i]);
		cout << "\n";
	}*/
/*	fibo[0] = 1;
	fibo[1] = 1;

	for(int i=2; i<3000; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
*/

	while(scanf("%s %s", &str1, &str2)) {
		a = str1; b = str2;
		if(strcmp(str1, "0")==0 && strcmp(str2, "0")==0) 
			break;
		count = 0;

		for(i=0; i<5000; i++)
			if(fibo[i] >= a && fibo[i] <= b) {
				//show(fibo[i]); 
				//cout << "\n";
				count++;
			}

		cout << count << "\n";
	}

return 0;
}
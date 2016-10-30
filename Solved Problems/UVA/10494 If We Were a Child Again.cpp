/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 2, Term - 1,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define maxlength 1000
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
	Mbigint operator-(Mbigint M);
	Mbigint operator*(Mbigint M);
	Mbigint operator*(int M);
	Mbigint operator/(int M);
	Mbigint operator/(Mbigint M);
	Mbigint operator%(int M);
	Mbigint operator%(Mbigint M);

	void operator+=(Mbigint M);
	void operator-=(Mbigint M);
	void operator*=(Mbigint M);
	void operator/=(int M);
	void operator/=(Mbigint M);


	bool operator<(Mbigint M);
	bool operator<=(Mbigint M);
	bool operator>(Mbigint M);
	bool operator>=(Mbigint M);
	bool operator==(Mbigint M);
	bool operator!=(Mbigint M);

};

void show(Mbigint M);
Mbigint GCD(Mbigint a, Mbigint b);
Mbigint LCM(Mbigint a, Mbigint b);

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

Mbigint Mbigint::operator-(Mbigint M)
{
	if(M.length == 0) return (*this);

	Mbigint ans;
	ans.length = length;
	for(int i=1, temp=0; i<=length; i++)
		ans.digit[i] = ((temp=(-(temp<0) + digit[i] - M.digit[i]))+10000) % 10000;
	ans.checklength();
	return ans;
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
	int number, i, j, temp;
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

Mbigint Mbigint::operator/(Mbigint M)
{
	if(M.length == 0) cout << "Division by 0 not possible";
	if((*this) < M) return 0;

	Mbigint div, ans;
	int head, tail, mid;

	ans.length = length - M.length+1;
	div.length = M.length - 1;
	memcpy(div.digit+1, digit+length-div.length+1, div.length*sizeof(int));

	for(int i=ans.length; i>=1; i--) {
		div = div*10000 + digit[i];
		head = 0; tail = 10000; 
		while(head+1 < tail) {
			mid = (head+tail)/2;
			if(M*mid <= div)
				head = mid;
			else 
				tail = mid;
		}
		ans.digit[i] = head;
		div = div - (M*head);
	}
	ans.checklength();
	return ans;
}

Mbigint Mbigint::operator%(int M)
{
	int temp=0;
	for(int i = length; i>=1; i--)
		temp = (temp*10000 + digit[i])% M;

	return temp;
}

Mbigint Mbigint::operator%(Mbigint M)
{
	return (*this) - ((*this)/M)*M;

}

//---------------------------------------------------------------------------
void Mbigint::operator+=(Mbigint M)
{
	(*this) = (*this) + M;
}

void Mbigint::operator-=(Mbigint M)
{
	(*this) = (*this) - M;
}

void Mbigint::operator*=(Mbigint M)
{
	(*this) = (*this) * M;
}

void Mbigint::operator/=(int M)
{
		(*this) = (*this) / M;
}

void Mbigint::operator/=(Mbigint M)
{
	(*this) = (*this) / M;
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

// MATHEMATICAL OPERATION----------------------------------------------------------------------------
Mbigint GCD(Mbigint a, Mbigint b)
{
	return(b == 0) ? a : GCD(b, a%b);
}

Mbigint LCM(Mbigint a, Mbigint b)
{
	return a*b/GCD(a, b);
}
// PRESENTATION FUNCTION START HERE --------------------------------------------

void show(Mbigint M)
{
	printf("%d", M.digit[M.length]);

	for(int i=M.length-1; i>=1; i--)
		printf("%04d", M.digit[i]);
}

int main()
{
	char str1[2000], str2[15];
	char op;

	Mbigint num1, num2;

	while(cin >> str1 >> op >> str2) {
		num1 = 1;
		num2 = 1;
		num1 = str1;
		num2 = str2;

		if(op == '/')
			show(num1/num2);
		else if(op == '%')
			show(num1%num2);
		cout << endl;
	}	
return 0;
}
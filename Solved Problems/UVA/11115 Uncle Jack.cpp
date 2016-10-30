// CopyRight Mahbub, CSE, 08, KUET.
// Roll No: 0807009
// Mobile No : 01911276607
// Partial or full copy of this code is strictly prohibited without my permission.

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdio.h>


using namespace std;

#define maxlength 500
// For 500 we can store an integer of 500*4 = 2000 digits.

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

	string toString();
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


void show(Mbigint M)
{
	printf("%d", M.digit[M.length]);

	for(int i=M.length-1; i>=1; i--)
		printf("%04d", M.digit[i]);
}

string Mbigint::toString()
{
	string ret, temp;
	int d;

	d = digit[length];
	while(d) {
		temp += (d%10) + '0';
		d /= 10;
	}
	reverse(temp.begin(), temp.end());
	ret += temp;

	temp.clear();
	for(int i=length-1; i>=1; i--) {
		d = digit[i];
		while(d) {
			temp += (d%10) + '0';
			d /= 10;
		}
		while(temp.size() != 4)
			temp += '0';
		reverse(temp.begin(), temp.end());
		ret += temp;
		temp.clear();
	}
	if(ret.size() == 0) return "0";
	return ret;
}

// --------------------------------------------------------------------------------



//Mbigint fibo[5000];
//char bignum[10];

int main()
{
    int N, D;
    Mbigint ans;

    while(cin >> N >> D) {
        if(N == 0 && D == 0) break;

        if(D == 0 ) {
            cout << "1\n";
            continue;
        }

        ans = N;

        for(int i=2; i<=D; i++)
            ans = ans * N;

        cout << ans.toString() << "\n";
    }

    return 0;
}

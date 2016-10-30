#include <iostream>
#include <string>
#include <algorithm>
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
	void operator=(Mbigint M);
	Mbigint operator*(int M);


	string toString();
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

void Mbigint::operator=(Mbigint M)
{
	length = M.length;
	memcpy(digit, M.digit, maxlength*sizeof(int));
	this->checklength();

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
// PRESENTATION FUNCTION START HERE --------------------------------------------

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

	return ret;
}

// ------------------------------------------------------------------------------

#define EPS 1e-9

double R, fraction;
int newR, n, totaldigit, multiplier;
Mbigint ans;


int main()
{
//	freopen("E:\\input.txt", "r", stdin);
//	freopen("E:\\output.txt", "w", stdout);

	int temp, i, k, pointPlace;
	string str;
	double tempR;


	n = 2;
	while(cin >> R >> n) {
//	for(tempR = .00001; tempR <= 1.000; tempR = tempR + 0.00001) {
//		R = tempR;
		R += EPS;
//		printf("%.5lf\n", R);
		temp = (int)(R * 1e5);
		while(temp % 10 == 0)
			temp /= 10;
		if(temp < (int)R) temp = (int)R;
	
		multiplier = 0;

		while((int)R != temp)  {
			R *= 10;
			multiplier++;
		}
				
		ans = temp;
		for(i = 1; i<n; i++)
			ans = ans * temp;
		
		str = ans.toString();
		pointPlace = str.size() - n*multiplier;

		if(pointPlace < 0) {
			cout << '.';
			for(i=1; i <= abs(pointPlace); i++)
				cout << '0';
			cout << str << "\n";
		}
		else {
			for(i = 0; i < pointPlace; i++)
				cout << str[i];
			
			if(i < str.size())cout << '.';

			for(i; i<str.size(); i++)
				cout << str[i];
			cout << "\n";
		}
//		cout << "\n";
	
	}

	return 0;
}

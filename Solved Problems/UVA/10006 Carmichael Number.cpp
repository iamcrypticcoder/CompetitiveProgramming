#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

#define SQR(x) ((x)*(x))
#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;


LL mod (LL a, LL n, LL b)
{
	if (n == 1 ) return a % b;
	LL ans = mod(a,n / 2 ,b);
	ans = (ans * ans) % b;
	if (n % 2 == 1 ) return ans * a % b;
	return ans; return ans;
}


#define MAX_PRIME 1000101
bool Flag[MAX_PRIME];

class MPrime {
public:
	VI Prime;
	MPrime();
	void Sieve();
	bool IsPrime(LL num);

};

MPrime::MPrime()
{
	Sieve();
}

void MPrime::Sieve() {
	int i, j;
	for(i = 2; i*i<=MAX_PRIME;) {
		for(j = i+i; j<=MAX_PRIME; j+= i)
			Flag[j] = 1;
		for(++i; Flag[i]; i++);
	}
	Prime.push_back(2);
	for(i = 3; i<MAX_PRIME; i += 2)  // i+=2 ?? there is no consecutive prime except 2,3
		if(Flag[i] == 0)
			Prime.push_back(i);
}

bool MPrime::IsPrime(long long num)
{
	if(num == 1 || num == 0) return 0;
	if(num <= MAX_PRIME) return (!Flag[num]);
	int root = sqrt((double)num);
	for(int i=0; Prime[i]<=root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

MPrime P;
VI carmi;

bool Check(int n)
{
    LL i;
    for(i=2; i < n; i++)
        if(mod(i, (LL)n, (LL)n) != i)
            return false;

    return true;
}

void PreCalculate()
{
	int input;
	for(input = 2; input <= 65000; input++)
        if( !P.IsPrime(input) && Check(input))
           carmi.push_back(input);

}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	PreCalculate();

    int input;

    while(cin >> input) {
		if(input == 0) break;

		if(binary_search(carmi.begin(), carmi.end(), input))
			cout << "The number " << input << " is a Carmichael number.\n";
		else
			cout << input << " is normal.\n";


    }

    return 0;
}

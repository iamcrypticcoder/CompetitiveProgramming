#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef vector<LL> VLL;

#define MAX_PRIME 20000101
bool Flag[MAX_PRIME];
VI Prime;

void Sieve()
{
	int i, j;
	for(i = 2; i*i<=MAX_PRIME;) {
		for(j = i+i; j<=MAX_PRIME; j+= i)
			Flag[j] = 1;
		for(++i; Flag[i]; i++);
	}
	Prime.push_back(2);
	for(i = 3; i<MAX_PRIME; i += 2) { // i+=2 ?? there is no consecutive prime except 2,3
		if(Flag[i] == 0)
			Prime.push_back(i);

	}
}

bool isPrime(LL num)
{
	if(num == 1 || num == 0) return 0;
	if(num <= MAX_PRIME) return (!Flag[num]);
	int root = sqrt((double)num);
	for(int i=0; Prime[i]<=root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

vector<pair<int,int> > twinPrime;

void CalculateTwinPrime()
{

    for(int i=1; i<Prime.size(); i++) {
        if(Prime[i-1] + 2 == Prime[i])
            twinPrime.push_back(pair<int,int>(Prime[i-1], Prime[i]));
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    Sieve();

    CalculateTwinPrime();

    int S;

    while(cin >> S) {
        pair<int,int> p = twinPrime[S-1];
        printf("(%d, %d)\n", p.first, p.second);
    }

    return 0;
}

#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>

using namespace std;

#define MAX_PRIME 1000101
typedef vector<int> VI;
typedef long long LL;
typedef vector<LL> VLL;

VI Prime;
bool Flag[MAX_PRIME];

void Sieve()
{
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


vector<int> Factorize(LL num)
{
	vector<int> F;

	if(isPrime(num)) {
		F.push_back(num);
		return F;
	}

	for(int i=0; ; i++) {
		if( !(num % Prime[i])) {
			while(!(num % Prime[i])) {
				num /= Prime[i];
				F.push_back(Prime[i]);
			}
			if(isPrime(num) || num == 1) break;
		}
	}

	if(isPrime(num)) F.push_back(num);

	return F;
}


int main()
{

    Sieve();

    int TC, tc;
    VI fact;
    int numSum, factSum, temp, num;

    cin >> TC;

    while(TC--) {
        cin >> num;

        for(num++; ; num++) {
            fact = Factorize(num);
            if(fact.size() == 1) continue;              // Because Prime is not Smith number.

            temp = num;
            numSum = 0;
            while(temp) {
                numSum += (temp%10);
                temp /= 10;
            }

            factSum = 0;

            for(int i=0; i<fact.size(); i++) {
                temp = fact[i];
                while(temp) {
                    factSum += temp%10;
                    temp /= 10;
                }
            }

            if(numSum == factSum) {
                cout << num << "\n";
                break;
            }
        }
    }

/*
    // From this I understand there are lots of SMITH NUMBER.
    for(int num=12; num<1e9; num++) {
        fact = Factorize(num);

        temp = num;
        numSum = 0;
        while(temp) {
            numSum += (temp%10);
            temp /= 10;
        }

        factSum = 0;
        int s = fact.size();
        for(int i=0; i<fact.size(); i++) {
            temp = fact[i];
            while(temp) {
                factSum += temp%10;
                temp /= 10;
            }
        }

        if(numSum == factSum) cout << num << "\n";
    }
*/

    return 0;
}

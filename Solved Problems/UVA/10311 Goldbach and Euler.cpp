#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef vector<LL> VLL;

#define MAX_PRIME 1000101
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

int main()
{
    Sieve();

    int input;
    int i;

    while(cin >> input) {
        if(input <= 4) {
            cout << input << " is not the sum of two primes!\n";
            continue;
        }
        if(input % 2 != 0) {
            if(isPrime(input-2)) {
                printf("%d is the sum of %d and %d.\n", input, 2, input-2);
            }
            else cout << input << " is not the sum of two primes!\n";

        }
        else {
            bool isFound = false;
            for(i= input/2-1; i>=2; i--) {
                if(isPrime(i) && isPrime(input - i)) {
                    printf("%d is the sum of %d and %d.\n", input, i, input-i);
                    isFound = true;
                    break;
                }
            }

            if(!isFound) cout << input << " is not the sum of two primes!\n";
        }

    }

    return 0;
}

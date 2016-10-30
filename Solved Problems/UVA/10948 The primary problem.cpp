#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
#include<bitset>

using namespace std;

#define MAX_PRIME 1000101

typedef long long LL;
typedef vector<int> VI;

bitset<MAX_PRIME+1> Flag;
VI Prime;

void Sieve()
{
    Flag.reset();
    Flag.set(0, true);
    Flag.set(1, true);

	int i, j;
	for(i = 2; i*i<=MAX_PRIME;) {
		for(j = i+i; j<=MAX_PRIME; j+= i)
			Flag.set(j, true);
		for(++i; Flag.test(i) == true; i++);
	}
	Prime.push_back(2);
	for(i = 3; i<=MAX_PRIME; i += 2)  // i+=2 ?? there is no consecutive prime except 2,3
		if(Flag.test(i) == false)
			Prime.push_back(i);
}

bool isPrime(LL num)
{
    if(num <= MAX_PRIME) return (!Flag.test(num));

    int root = (int)sqrt(num);
    for(int i=2; i<=root; i++)
        if(num % Prime[i] == 0)
            return false;
    return true;
}



int main()
{
    Sieve();

    int i;
    int input;

    while(cin >> input && input != 0) {
        bool hasWay = false;

        for(i = 0; Prime[i] <= input/2; i++) {
            if(isPrime(input - Prime[i])) {
                hasWay = true;
                break;
            }
        }
        cout << input << ":\n";
        if(hasWay) cout << Prime[i] << "+" << input-Prime[i] << "\n";
        else cout << "NO WAY!\n";
    }


    return 0;
}

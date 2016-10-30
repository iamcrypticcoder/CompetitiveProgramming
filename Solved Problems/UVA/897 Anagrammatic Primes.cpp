/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/


#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

#define MAX_PRIME 1000101

typedef long long LL;
typedef vector<int> VI;

bool Flag[MAX_PRIME];

// This Function converts an integer to a string
string toString(LL num)
{
	string ret;

	while(num != 0) {
		ret += (char)(num%10 + '0');
		num /= 10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

class MPrime {
public:
	VI Prime;
	MPrime();
	void Sieve();
	bool IsPrime(LL num);
    bool isAnaPrime(int num);
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
	int root = (int)sqrt((double)num);
	for(int i=0; Prime[i]<=root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

MPrime P;

bool isAnaPrime(int num)
{
    string numStr = toString(num);
	sort(numStr.begin(), numStr.end());

	if(!P.IsPrime(atoi(numStr.c_str()))) return false;

    while(next_permutation(numStr.begin(), numStr.end())) {
        if(!P.IsPrime(atoi(numStr.c_str()))) {
			return false;
        }
    }

    return true;
}

// At first I use this code to generate all Ana Prime number and take a output to file.
// I found 22 Ana Primes.
// 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 119, 311, 337, 373, 733, 919, 991
/*
VI anaPrime;

void FindAllAnaPrime()
{
	int i;
	anaPrime.push_back(2);

	for(i=3; i <= 10000000; i += 2)
		if(P.IsPrime(i)) {
			if(isAnaPrime(i)) {
				anaPrime.push_back(i);
			}
		}

		for(i=0; i<anaPrime.size(); i++)
			cout << anaPrime[i] <<"\n";

}
*/

// The pre-calculated ana Primes are :

int anaPrime[22] = { 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 119, 311, 337, 373, 733, 919, 991 };

int main()
{
//	freopen("output.txt", "w", stdout);

//    int i;
    int N;


    while(cin >> N) {
		if(N == 0) break;

        if(N >= 991)
            cout << "0\n";
        else {
			bool isFound = false;
            int digit =  floor(log10((double)N)) + 1;
            for(int i=0; i<22; i++) 
				if( anaPrime[i] > N && anaPrime[i] < (int)pow(10.0, digit) ) {
                    cout << anaPrime[i] << "\n";          
					isFound = true;
					break;
				}
			if(!isFound) cout << "0\n";
        }

    }


	return 0;
}

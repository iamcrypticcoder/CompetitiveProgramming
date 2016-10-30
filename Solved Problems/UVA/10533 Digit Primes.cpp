#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define MAX_PRIME 1000101
typedef vector<int> VI;
bool Flag[MAX_PRIME];

struct powerPrime {
	int p, a;					// Every powerPrime is in the form p^a
};								// That is A number is represented in this form --  p1^a1 * p2^a2 * p3^a3

class MPrime {
public:
	VI Prime;
	MPrime();
	void Sieve();
	bool IsPrime(long long num);
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
// ------------------------------------------------------------------------------

MPrime P;
int DP[1000001];

void Process()
{
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = DP[4] = 2;
	DP[5] = DP[6] = 3;
	DP[7] = DP[8] = DP[9] = DP[10] = 4;

	int sum_of_digit, num ;

	for(num = 11; num <= 1e6; num++) {
		int temp = num;

		if(!P.IsPrime(temp)) {
			DP[temp] = DP[temp-1];
			continue;
		}
		sum_of_digit = 0;

		while(temp) {
			sum_of_digit += (temp%10);
			temp /= 10;
		}

		if(P.IsPrime(sum_of_digit)) 
			DP[num] = DP[num-1]+1;
		else DP[num] = DP[num-1];

	}
}

bool isDigitPrime(int num)
{
     if(!P.IsPrime(num))
      return false;
     
     int temp = num, sum_of_digit = 0;
          
 		while(temp) {
			sum_of_digit += (temp%10);
			temp /= 10;
		}   
    
    if(P.IsPrime(sum_of_digit)) return true;
    else return false; 
     
}

int main() 
{
	int N, low, high, ans;
	
	Process();

	cin >> N;

	for(int i=1; i<=N; i++) {
  
		cin >> low >> high;
		ans = DP[high] - DP[low-1];
		
//		if(isDigitPrime(low)) ans += 1;
		
		cout << ans << "\n";
		
	}
	
//	cout << P.IsPrime(10501);
   return 0;
}

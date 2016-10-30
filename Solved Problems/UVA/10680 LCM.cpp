

#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SQR(x) ((x)*(x))

#define MAX_PRIME 1000101
typedef vector<int> VI;
bool Flag[MAX_PRIME];

struct powerPrime {
int p, a; // Every powerPrime is in the form p^a
}; // That is A number is represented in this form -- p1^a1 * p2^a2 * p3^a3

class MPrime {
public:
VI Prime;
MPrime();
void Sieve();
bool IsPrime(long long num);
VI Factorize(long long num);
vector<powerPrime> FactorizeAsPower(long long num);
void PrintPrime();
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
for(i = 3; i<MAX_PRIME; i += 2) // i+=2 ?? there is no consecutive prime except 2,3
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

vector<int> MPrime::Factorize(long long num)
{
vector<int> F;

if(IsPrime(num)) {
F.push_back(num);
return F;
}

for(int i=0; ; i++) {
if( !(num % Prime[i])) {
while(!(num % Prime[i])) {
num /= Prime[i];
F.push_back(Prime[i]);
}
if(IsPrime(num) || num == 1) break;
}
}

if(IsPrime(num)) F.push_back(num);

return F;
}

// Dont input 1 in this function. It will crash.
vector<powerPrime> MPrime::FactorizeAsPower(long long num)
{
vector<powerPrime> F;
powerPrime powP;
long long power;

if(IsPrime(num)) {
powP.p = num;
powP.a = 1;
F.push_back(powP);
return F;
}

for(int i=0; ; i++)
if( !(num % Prime[i]) ) {
power = 0;
while(!(num % Prime[i])) {
num /= Prime[i];
power++;
}
powP.p = Prime[i];
powP.a = power;
F.push_back(powP);

if(IsPrime(num) || num == 1) break;
}

if(IsPrime(num)) {
powP.p = num;
powP.a = 1;
F.push_back(powP);
}
return F;
}

void MPrime::PrintPrime() {
int i;
printf("Total prime numbers between 1 and 1000000 is: %d\n",Prime.size());
for(i = 0; i<Prime.size(); i++) { // printing 1st 100 primes
printf("%d ",Prime[i]);
}
puts("");
}

MPrime P;

int pattern[10][5] = {
{0, 0, 0, 0, 0},
{1, 1, 1, 1, 1},
{1, 2, 4, 8, 6},
{1, 3, 9, 7, 1},
{1, 4, 6, 4, 6},
{1, 5, 5, 5, 5},
{1, 6, 6, 6, 6},
{1, 7, 9, 3, 1},
{1, 8, 4, 8, 4},
{1, 9, 1, 9, 1},
};

int getAns( int N )
{
int temp, p2 = 0, p3 = 0, p5 = 0, p;
int ans;

temp = N; while(temp >= 2) { temp /= 2; p2++; }
temp = N; while(temp >= 3) { temp /= 3; p3++; }
temp = N; while(temp >= 5) { temp /= 5; p5++; }

if( p3 == 0 ) ans = pattern[3][0];
else if( p3 % 4 == 0) ans = pattern[3][4];
else ans = pattern[3][p3%4];

p2 -= p5;
if( p2 == 0 ) ans *= pattern[2][0];
else if( p2 % 4 == 0) ans *= pattern[2][4];
else ans *= pattern[2][p2%4];

FOR(j, 3, P.Prime.size()-1) {
if( P.Prime[j] > N) break;

p = 0;
temp = N; while(temp >= P.Prime[j]) { temp /= P.Prime[j]; p++; }

if( p == 0 ) ans *= pattern[P.Prime[j]%10][0];
else if( p % 4 == 0) ans *= pattern[P.Prime[j]%10][4];
else ans *= pattern[P.Prime[j]%10][p%4];

ans %= 10;
}

return ans;
}

int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

int N;

while( cin >> N && N) {
cout << getAns(N) << "\n";

}

return 0;
}

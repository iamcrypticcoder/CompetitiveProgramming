/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_PRIME 1000101
bool Flag[MAX_PRIME];
VI Prime;
int NOP[MAX_PRIME];       // Number of primes less or equal
double E[MAX_PRIME];      // Expectation we need.

void Sieve() {
    int i, j;
    for(i = 2; i*i<=MAX_PRIME;) {
        for(j = i+i; j<=MAX_PRIME; j+= i)
            Flag[j] = 1;
        for(++i; Flag[i]; i++);
    }
    Prime.push_back(2);
    NOP[1] = NOP[2] = 1;
    for(i = 3; i<MAX_PRIME; i += 2) { // i+=2 ?? there is no consecutive prime except 2,3
        NOP[i-1] = NOP[i-2];
        if(Flag[i] == 0) {
            Prime.push_back(i);
            NOP[i] = NOP[i-1] + 1;
        }
        else NOP[i] = NOP[i-1];
    }
}

bool IsPrime(long long num)
{
    if(num == 1 || num == 0) return 0;
    if(num <= MAX_PRIME) return (!Flag[num]);
    int root = sqrt((double)num);
    for(int i=0; Prime[i]<=root; i++)
        if(num % Prime[i] == 0)
            return 0;
    return 1;
}

void PrintPrime() {
    int i;
    printf("Total prime numbers between 1 and 1000000 is:%d\n",Prime.size());
    for(i = 0; i<Prime.size(); i++) { // printing 1st 100 primes
        printf("%d ",Prime[i]);
    }
    puts("");
}


void Expectation()
{
    E[1] = 0.0;
    E[2] = 1.0;
    E[3] = 2.0;

    FOR(D, 4, 1000000) {
        int root = (int)sqrt(D);
        double rh = 0.0;
        double lh = 0.0;
        int pDiv = 0;

        if(IsPrime(D)) {
            E[D] = NOP[D];
            continue;
        }

        FOR(i, 2, root) {
            if(IsPrime(i)) {
                if(D % i == 0) {
                    rh += E[D/i];
                    pDiv++;
                    if( D/i != i && IsPrime(i)) { rh += E[i]; pDiv++; }
                }
            }
        }
        rh = rh / NOP[D] + 1;
        lh = 1 - (double)(NOP[D] - pDiv ) / NOP[D];

        E[D] = rh / lh;
    }


}

int main()
{
 //   READ("input.txt");
//    WRITE("output.txt");

    int TC, tc;
    int N;

    Sieve();
//    cout << Prime.size() ;
    Expectation();

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d", &N);

        printf("Case %d: %.10lf\n", tc, E[N]);
    }

    return 0;
}


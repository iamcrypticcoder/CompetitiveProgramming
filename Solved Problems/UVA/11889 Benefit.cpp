#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define MAX_PRIME 10000101
typedef vector<int> VI;
bool Flag[MAX_PRIME];

struct powerPrime {
    int p, a;                    // Every powerPrime is in the form p^a
};                                // That is A number is represented in this form --  p1^a1 * p2^a2 * p3^a3

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

    if( num == 1) {
        powP.p = 1;
        powP.a = 1;
        F.push_back(powP);
        return F;
    }

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


int powI(int a, int b)
{
    int ret = a;

    FOR(i, 2, b)
        ret *= a;
    return ret;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int A, B, C;
    bool isPossible, found;
    vector<powerPrime> factA, factB, factC;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> A >> C;

        if( A == C ) {
            cout << "1\n";
            continue;
        }
        else if( A == 1 && C != 1) {
            cout << C <<"\n";
            continue;
        }


        factC = P.FactorizeAsPower(C);
        factA = P.FactorizeAsPower(A);

        isPossible = true;

        FOR(i, 0, factA.SZ-1) {
            found = false;
            FOR(j, 0, factC.SZ-1) {
                if( factA[i].p == factC[j].p) {
                    found = true;
                    break;
                }
            }
            if(found == false) {
                isPossible = false;
                break;
            }
        }

        if(isPossible == false) {
            cout << "NO SOLUTION\n";
            continue;
        }

        B = 1;
        FOR(i, 0, factC.SZ-1) {
            found = false;
            FOR(j, 0, factA.SZ-1)
                if( factC[i].p == factA[j].p) {
                    if(factA[j].a < factC[i].a)
                        B *= powI(factC[i].p, factC[i].a);
                    found = true;
                    break;
                }
            if( ! found )  B *= powI(factC[i].p, factC[i].a);
        }

        cout << B << "\n";
    }


    return 0;
}



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

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;

inline int src() { int ret; scanf("%d", &ret); return ret; }

const int MAX = 1e7;
unsigned int bigPrime[MAX + 7];
unsigned long long tau[MAX + 7];

void preCalTau() {
    memset(bigPrime, 0, sizeof(bigPrime));
    int root = (int)sqrt(MAX);
    for (int i = 2; i <= MAX; ++i) {
        if (bigPrime[i] == 0) {
            bigPrime[i] = i;
            if (i > root) continue;
            for (int j = i*i; j <= MAX; j += i)
                bigPrime[j] = i;
        }
    }
    tau[0] = 0, tau[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        int p = bigPrime[i];
        int power = 0;
        int tmp = i;
        while (tmp % p == 0) { power++; tmp /= p; }
        tau[i] = (power + 1) * tau[tmp];
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    preCalTau();

    TC = src();

    for (int tc = 1; tc <= TC; tc++) {
        int n = src();
        printf("%llu\n", tau[n]);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
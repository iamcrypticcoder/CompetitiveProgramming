/*
    Problem Link: https://www.spoj.com/problems/DIVSUM/
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Time :      AC
	Rank :
	Complexity:
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

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 500000

unsigned int bigPrime[MAX + 7];
unsigned int sigma[MAX + 7];

void preCalSigma() {
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

    sigma[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        int p = bigPrime[i];
        int pa = p;
        int tmp = i;

        while (tmp % p == 0) {
            pa *= p;
            tmp /= p;
        }

        sigma[i] = (pa - 1) / (p - 1) * sigma[tmp];
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    preCalSigma();

    TC = src();

    for (int tc = 1; tc <= TC; tc++) {
        int n = src();
        printf("%lu\n", sigma[n] - n);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


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
long long phi[MAX + 7] = { 0 };

void preCalPhi() {
    phi[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (phi[i] == 0) {
            phi[i] = i-1;
            for (int j = 2*i; j <= MAX; j += i) {
                if (phi[j] == 0) phi[j] = j;
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    preCalPhi();

    TC = src();

    for (int tc = 1; tc <= TC; tc++) {
        int n = src();
        printf("%lld\n", phi[n]);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
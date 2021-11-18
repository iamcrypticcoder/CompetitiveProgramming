/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      Wrong Answer
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int countDivisors(int n) {
    int ret;
    int root = (int)sqrt(n);
    for (int i = 1; i <= root; i++) {
        if (n % i == 0) {
            ret++;
            if (i != n/i) ret++;
        }
    }
    return ret;
}

int solve(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int g = gcd(a, b);
    return countDivisors(g);
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    //READ("input.txt");
    //WRITE("../output.txt");
    int i, j, k;
    int TC, tc;
    int a, b;

    double cl = clock();
    cl = clock() - cl;

    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", solve(a, b));
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

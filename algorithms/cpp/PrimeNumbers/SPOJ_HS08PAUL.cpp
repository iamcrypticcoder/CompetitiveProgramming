/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
const int MAX_PRIME = 1e7;
vector<bool> flag(MAX_PRIME + 7, false);
vector<int> primes;
vector<int> primeCount(MAX_PRIME + 7);

void sieveOptimized() {
    for (int i = 3; i * i <= MAX_PRIME; i += 2) {
        if (!flag[i]) {
            for (int j = i*i; j <= MAX_PRIME; j += 2*i)
                flag[j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MAX_PRIME; i += 2)
        if (!flag[i]) primes.push_back(i);
}

bool isPrime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return !flag[n];
}

void preCal() {
    int root = sqrt(MAX_PRIME);
    for (int x = 1; x <= root; x++) {
        for (int y = x+1; y <= root; y += 2) {
            LL n1 = (LL)x*x + (LL)y*y*y*y;
            LL n2 = (LL)y*y + (LL)x*x*x*x;
            //printf("%d, %d = %lld, %lld\n", x, y, n1, n2);
            if (n1 > (LL)MAX_PRIME && n2 > (LL)MAX_PRIME) break;
            if (n1 < (LL)MAX_PRIME && isPrime(n1)) primeCount[n1] = 1;
            if (n2 < (LL)MAX_PRIME && isPrime(n2)) primeCount[n2] = 1;
        }
    }
    primeCount[2] = 1;
    for (int i = 1; i <= MAX_PRIME; i++)
        primeCount[i] += primeCount[i-1];
}

int main()
{
    //READ("input.txt");
    //WRITE("../output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    sieveOptimized();
    preCal();

    cin >> TC;
    int n;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> n;
        cout << primeCount[n] << endl;
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

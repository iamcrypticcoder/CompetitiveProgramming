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
const int MAX_N = 3e3;
vector<bool> flag(MAX_N + 7, false);
vector<int> primes;
vector<int> csum;

void sieveOptimized() {
    for (int i = 3; i * i <= MAX_N; i += 2) {
        if (!flag[i]) {
            for (int j = i*i; j <= MAX_N; j += 2*i)
                flag[j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MAX_N; i += 2)
        if (!flag[i]) primes.push_back(i);
}

bool isPrime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return !flag[n];
}

// Return count of distinct prime count in factorization
int factorize(LL n) {
    int ret = 0;
    int root = sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        if (n % primes[i] == 0) {
            while(n % primes[i] == 0) n /= primes[i];
            ret++;
        }
    }
    if(n > 1) ret++;
    return ret;
}

void preCal() {
    csum = vector<int>(MAX_N + 7, 0);
    for (int n = 2; n <= MAX_N; n++) {
        int x = factorize(n);
        if (x == 2) csum[n] = 1;
    }
    for (int i = 1; i <= MAX_N; i++) {
        csum[i] += csum[i - 1];
        //printf("%d = %d\n", i, csum[i]);
    }
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
    int n;
    while (cin >> n) {
        cout << csum[n] << endl;
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

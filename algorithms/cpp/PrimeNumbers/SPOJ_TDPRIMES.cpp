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
const int MAX_PRIME = 1e8;
vector<bool> flag(MAX_PRIME + 7, false);
vector<int> primes;

void seiveOptimized() {
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

int main()
{
    //READ("input.txt");
    WRITE("../output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    seiveOptimized();
    for (int i = 0; i < primes.size(); i += 100)
        printf("%d\n", primes[i]);

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

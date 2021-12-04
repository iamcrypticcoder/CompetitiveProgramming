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
#include <limits.h>
#include <algorithm>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

const int MAX = int(1e6);

int N;
vector<int> A;
vector<int> bit;

void add(int idx, int delta) {
    idx = idx+1;
    while (idx <= N) {
        bit[idx] += delta;
        idx += idx & -idx;
    }
}

void build() {
    bit = vector<int>(N+1, 0);
    for (int i = 0; i < N; i++)
        add(i, A[i]);
}

int sum(int r) {
    int ret = 0;
    r += 1;
    while (r > 0) {
        ret += bit[r];
        r -= r & -r;
    }
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l-1);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    cin >> N;
    A = vector<int>(N);
    for (auto& x : A) cin >> x;

    build();
    for (int i = 0; i < N; i++)
        printf("Sum up to index %d is %d\n", i, sum(i));

    return 0;
}
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

void rangeAdd(int l, int r, int delta) {
    add(l, delta);
    add(r + 1, -delta);
}

int pointQuery(int idx) {
    int ret = 0;
    idx = idx + 1;
    while (idx > 0) {
        ret += bit[idx];
        idx -= idx & -idx;
    }
    return ret;
}

void build() {
    bit = vector<int>(N+1, 0);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    N = 10;

    build();
    rangeAdd(0, N-1, 1);
    rangeAdd(0, 4, 1);
    cout << pointQuery(0) << endl;
    cout << pointQuery(1) << endl;
    cout << pointQuery(8) << endl;
    cout << pointQuery(9) << endl;

    return 0;
}
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
vector<int> bit1, bit2;

void add(vector<int>& bit, int idx, int x) {
    idx = idx+1;
    while (idx <= N) {
        bit[idx] += x;
        idx += idx & -idx;
    }
}

void rangeAdd(int l, int r, int x) {
    add(bit1, l, x);
    add(bit1, r+1, -x);
    add(bit2, l, x*(l-1));
    add(bit2, r+1, -x*r);
}

int sum(vector<int>& bit, int idx) {
    int ret = 0;
    idx = idx + 1;
    while (idx > 0) {
        ret += bit[idx];
        idx -= idx & -idx;
    }
    return ret;
}

int prefixSum(int idx) {
    return sum(bit1, idx)*idx - sum(bit2, idx);
}

int rangeSum(int l, int r) {
    return prefixSum(r) - prefixSum(l-1);
}

void init() {
    bit1 = vector<int>(N+1, 0);
    bit2 = vector<int>(N+1, 0);
}

int main() {
    //READ("../input.txt");
    //WRITE("output.txt");

    N = 10;
    init();

    rangeAdd(0, 9, 1);
    rangeAdd(0, 4, 1);

    cout << rangeSum(0, 9) << endl;
    cout << rangeSum(0, 4) << endl;
    cout << rangeSum(5, 9) << endl;
    cout << rangeSum(0, 0) << endl;
    cout << rangeSum(9, 9) << endl;

    return 0;
}
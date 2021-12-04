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
#include <climits>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define MAX 1000001

int N;
vector<int> A;
vector<int> bit;

void update(int idx, int val) {
    while (idx < N) {
        bit[idx] = min(bit[idx], val);
        idx = idx | (idx+1);
    }
}

void build() {
    bit = vector<int>(N, INT_MAX);
    for (int i = 0; i < N; i++)
        update(i, A[i]);
}

int getMin(int r) {
    int ret = INT_MAX;
    while (r >= 0) {
        ret = min(ret, bit[r]);
        r = (r & (r+1)) - 1;
    }
    return ret;
}

int rmq(int l, int r) {
    return 0;
    //return sum(r) - sum(l-1);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    cin >> N;
    A = vector<int>(N);
    for (auto& x : A) cin >> x;

    // NOT COMPLETED

    return 0;
}
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

#define MAX 1000001

int N;
vector<int> A;
vector<int> bit;

void add(int idx, int delta) {
    while (idx < N) {
        bit[idx] += delta;
        idx = idx | (idx+1);
    }
}

void build() {
    bit = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
        add(i, A[i]);
}

int sum(int r) {
    int ret = 0;
    while (r >= 0) {
        ret += bit[r];
        r = (r & (r+1)) - 1;
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
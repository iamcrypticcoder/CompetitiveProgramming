#include <bits/stdc++.h>
using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

// Input Methods
inline int32_t srcInt32() { int ret; scanf("%d", &ret); return ret; }
inline uint32_t srcUInt32() { uint32_t ret; scanf("%u", &ret); return ret; }
inline int64_t srcInt64() { int64_t ret; scanf("%lld", &ret); return ret; }
inline uint64_t srcUInt64() { uint64_t ret; scanf("%llu", &ret); return ret; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //READ("../input.txt");
    //WRITE("output.txt");

    int64_t TC, tc;
    double cl = clock();

    TC = srcInt64();
    for (tc = 1; tc <= TC; tc++) {
        // Start code for a test case
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

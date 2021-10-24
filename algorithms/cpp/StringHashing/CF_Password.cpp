/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      AC
    Rank :      434 ms
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
#include <unordered_set>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

const long long MOD = 1e9 + 9;
const long long p = 61;
string txt;

int solve() {
    int n = (int)txt.length();
    if (n < 3) return 0;

    vector<long long> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i-1]*p) % MOD;

    vector<long long> txtHash(n);
    txtHash[0] = txt[0];
    for (int i = 1; i < n; i++) {
        txtHash[i] = (txtHash[i-1] + txt[i] * power[i]) % MOD;
    }

    vector<int> possibleLenList;
    for (int len = 1; len <= n-2; len++) {
        long long prefixHash = txtHash[len-1];
        long long suffixHash = (txtHash[n-1] - txtHash[n-len-1]) % MOD;
        if (suffixHash < 0) suffixHash += MOD;
        prefixHash = (prefixHash * power[n-len]) % MOD;
        if (prefixHash == suffixHash)
            possibleLenList.push_back(len);
    }

    int ret = 0;
    int l = 0, r = possibleLenList.size()-1;
    while (l <= r) {
        int mid = (l+r) / 2;
        int len = possibleLenList[mid];

        bool found = false;
        for (int i = 1; i < n-len; i++) {          // "Less than" and start from 1 because we dont want first and last occurance
            long long hash = (txtHash[i+len-1] - txtHash[i-1]) % MOD;
            if (hash < 0) hash += MOD;
            long long prefixHash = (txtHash[len-1] * power[i]) % MOD;
            if (prefixHash == hash) {
                found = true;
                break;
            }
        }

        if (found) {
            l = mid+1;
            ret = max(ret, len);
        }
        else r = mid-1;
    }

    return ret;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    while(cin >> txt) {
        int x = solve();
        if (x == 0) printf("Just a legend\n");
        else printf("%s\n", txt.substr(0, x).c_str());
    }
}

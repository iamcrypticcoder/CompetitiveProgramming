/*
        Problem Link : https://www.spoj.com/problems/HMLIS/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status :
        Time :
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
#include <limits.h>
#include <algorithm>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

const int MAX_N = int(1e5);
const int MOD = int(1e9 + 7);

void countAllPossibleLIS(vector<int> v, int& lisLen, int& lisCount) {
    struct Card {
        int val, cnt = 0;
        Card* parent = NULL;
        Card(int val) {
            this->val = val;
            this->cnt = 1;
        }
    };
    auto comp = [](Card* a, Card* b) {
        return a->val < b->val;
    };

    int n = v.size();
    // Convert integers into card node
    vector<Card*> cards = vector<Card*>(n);
    for (int i = 0; i < n; i++) cards[i] = new Card(v[i]);
    vector<Card*> piles = vector<Card*>(n, new Card(INT_MAX));
    vector<Card*> lastPileCards;
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(piles.begin(), piles.end(), new Card(v[i]), comp) - piles.begin();
        Card* currentCard = piles[pos];
        piles[pos] = cards[i];

        if (currentCard->val == v[i]) {
            if (pos == 0) piles[pos]->cnt++;
            else piles[pos]->cnt += piles[pos-1]->cnt;
        } else {
            piles[pos] = cards[i];
            // Link to top card of left pile
            if (pos == 0) piles[pos]->parent = NULL;
            else piles[pos]->parent = piles[pos-1];
        }

        // Plus 1 because of 0-based index.
        if (pos+1 == maxLen) {
            lastPileCards.push_back(piles[pos]);
        } else if (pos+1 > maxLen) {
            lastPileCards.clear();
            lastPileCards.push_back(piles[pos]);
            maxLen = pos + 1;
        }
    }

    lisLen = maxLen;
    lisCount = 0;
    for (int i = 0; i < lastPileCards.size(); i++) {
        lisCount = (lisCount + lastPileCards[i]->cnt) % MOD;
    }
}

int main() {
    READ("../input.txt");

    int N = srcInt();
    vector<int> arr = vector<int>(N);
    for (auto& x : arr) x = srcInt();

    int lisLen, lisCount;
    countAllPossibleLIS(arr, lisLen, lisCount);

    printf("%d %d ")

    return 0;
}
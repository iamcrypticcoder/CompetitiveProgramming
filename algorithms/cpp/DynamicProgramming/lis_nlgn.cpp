/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
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
#include <algorithm>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

vector<int> lisNlgN(vector<int> v) {
    int n = v.size();
    vector<int> piles = vector<int>(n, INT_MAX);
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(piles.begin(), piles.end(), v[i]) - piles.begin();
        piles[pos] = v[i];
        maxLen = max(maxLen, pos+1); // Plus 1 because of 0-based index.
    }

//    // Print piles for debug purpose
//    for (auto x : piles) cout << x << " ";
//    cout << endl;
//
//    // Print position for debug purpose
//    for (auto x : position) cout << x << " ";
//    cout << endl;

    vector<int> ret = vector<int>(piles.begin(), piles.begin() + maxLen);
    return ret;
}

vector<vector<int>> allPossibleLIS(vector<int> v) {
    struct Card {
        int val;
        Card* parent = NULL;
        Card(int val) {
            this->val = val;
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
        piles[pos] = cards[i];

        // Link to top card of left pile
        if (pos == 0) cards[i]->parent = NULL;
        else cards[i]->parent = piles[pos-1];

        // Plus 1 because of 0-based index.
        if (pos+1 == maxLen) {
            lastPileCards.push_back(cards[i]);
        } else if (pos+1 > maxLen) {
            lastPileCards.clear();
            lastPileCards.push_back(cards[i]);
            maxLen = pos + 1;
        }
    }

    // Print for debug purpose
//    printf("maxLen = %d\n", maxLen);
//    printf("Total unique lis list = %d\n", lastPileCards.size());

    vector<vector<int>> ret;
    for (auto card : lastPileCards) {
        vector<int> lis;
        Card* c = card;
        while (c != NULL) {
            lis.push_back(c->val);
            c = c->parent;
        }
        reverse(lis.begin(), lis.end());
        ret.push_back(lis);
    }

    return ret;
}


// https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
int main() {
    //READ("../input.txt");
    //WRITE("output.txt");

    double cl = clock();
    cl = clock() - cl;

    int N;

//    vector<int> v {6, 3, 5, 10, 11, 2, 9, 14, 13, 7, 4, 8, 12};
//    vector<vector<int>> allLisList = allPossibleLIS(v);
//    printf("All possible LIS lists: \n");
//    for (vector<int> v : allLisList) {
//        for (auto x : v) printf("%d ", x);
//        printf("\n");
//    }

    while (cin >> N) {
        vector<int> v = vector<int>(N);
        for (int i = 0; i < N; i++) cin >> v[i];

        vector<int> lisList = lisNlgN(v);
        printf("LIS Length = %d\n", lisList.size());
        printf("LIS List = ");
        for (auto x : lisList) printf("%d ", x);
        printf("\n");

        vector<vector<int>> allLisList = allPossibleLIS(v);
        printf("All possible LIS lists: \n");
        for (vector<int> list : allLisList) {
            for (auto x : list) printf("%d ", x);
            printf("\n");
        }
        printf("----------------------------------------------------------------------------------\n");
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


/**
Input:

13
6 3 5 10 11 2 9 14 13 7 4 8 12
9
10 22 9 33 21 50 41 60 80
8
10 9 2 5 3 7 101 18
7
7 7 7 7 7 7 7
6
0 1 0 3 2 3

Output:

LIS Length = 5
LIS List = 2 4 7 8 12
All possible LIS lists:
3 5 10 11 14
3 5 10 11 13
3 5 7 8 12
----------------------------------------------------------------------------------
LIS Length = 6
LIS List = 9 21 33 41 60 80
All possible LIS lists:
10 22 33 41 60 80
----------------------------------------------------------------------------------
LIS Length = 4
LIS List = 2 3 7 18
All possible LIS lists:
2 3 7 101
2 3 7 18
----------------------------------------------------------------------------------
LIS Length = 1
LIS List = 7
All possible LIS lists:
7
7
7
7
7
7
7
----------------------------------------------------------------------------------
LIS Length = 4
LIS List = 0 1 2 3
All possible LIS lists:
0 1 2 3
----------------------------------------------------------------------------------

**/

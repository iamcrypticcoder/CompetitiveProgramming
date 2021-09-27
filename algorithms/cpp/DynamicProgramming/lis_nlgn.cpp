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
    vector<int> position;
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(piles.begin(), piles.end(), v[i]) - piles.begin();
        piles[pos] = v[i];
        position.push_back(pos);
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

// https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    double cl = clock();
    cl = clock() - cl;

    int N;

    while (cin >> N) {
        vector<int> v = vector<int>(N);
        for (int i = 0; i < N; i++) cin >> v[i];

        vector<int> lisList = lisNlgN(v);
        printf("LIS Length = %d\n", lisList.size());
        printf("LIS List = ");
        for (auto x : lisList) printf("%d ", x);
        printf("\n\n");

//        printf("LIS Last Index = %d\n", lisLastIndex);
//        vector<int> lisList;
//        printLIS(lisLastIndex, lisList);
//        printf("LIS List = ");
//        for (auto x : lisList) printf("%d ", x);
//        printf("\n\n");
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

LIS Length = 6
LIS List = 9 21 33 41 60 80

LIS Length = 4
LIS List = 2 3 7 18

LIS Length = 1
LIS List = 7

LIS Length = 4
LIS List = 0 1 2 3

**/

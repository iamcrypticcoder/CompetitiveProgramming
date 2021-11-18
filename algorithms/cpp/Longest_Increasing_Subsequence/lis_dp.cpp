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

const int MAX = 1e4;

// A is the main data list
// L contains length if every 1 <= i <= MAX
// P contains path of the for every 1 <= i <= MAX
int N;
int A[MAX+7], L[MAX+7], P[MAX+7];
int lisLen;

// Indicates last element of final LIS. From here we will generate lis list.
int lisLastIndex;

int lisTD(int i)
{
    if(L[i] != -1) return L[i];

    if(i == 0) return L[i] = 1;

    int maxLen = 0;
    for (int j = i-1; j >= 0; j--) {
        int t = lisTD(j);
        if (A[i] > A[j] && t > maxLen) {
            maxLen = t;
            P[i] = j;
        }
    }

    L[i] = 1 + maxLen;
    if (L[i] > lisLen) {
        lisLen = L[i];
        lisLastIndex = i;
    }
    return L[i];
}

void printLIS(int i, vector<int>& result) {
    if (i == -1) return;
    printLIS(P[i], result);
    result.push_back(A[i]);
}

int main()
{
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    while (cin >> N) {
        for (int i = 0; i < N; i++)
            cin >> A[i];

        memset(L, -1, sizeof L);
        memset(P,  -1, sizeof P);
        lisLen = 0, lisLastIndex = 0;
        lisTD(N-1);
        printf("LIS Length = %d\n", lisLen);
        printf("LIS Last Index = %d\n", lisLastIndex);
        vector<int> lisList;
        printLIS(lisLastIndex, lisList);
        printf("LIS List = ");
        for (auto x : lisList) printf("%d ", x);
        printf("\n\n");
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
LIS Last Index = 7
LIS List = 3 5 10 11 14

LIS Length = 6
LIS Last Index = 8
LIS List = 10 22 33 41 60 80

LIS Length = 4
LIS Last Index = 6
LIS List = 2 3 7 101

LIS Length = 1
LIS Last Index = 1
LIS List = 7

LIS Length = 4
LIS Last Index = 5
LIS List = 0 1 2 3

 **/

#include <bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

const int MAX = 1e4;

int memo[2500];
int parent[2500];
int lisLastIndex;

int lisTD(vector<int>& nums, int i) {
    if (memo[i] != -1) return memo[i];
    if (i == 0) return memo[i] = 1;
    int ret = 0;
    for (int j = i-1; j >= 0; j--) {
        if (nums[j] < nums[i] && lisTD(nums, j) > ret) {
            ret = lisTD(nums, j);
            parent[i] = j;
        }
    }
    return memo[i] = 1+ret;
}

int lis(vector<int>& nums) {
    int n = (int)nums.size();
    memset(memo, -1, sizeof memo);
    memset(parent, -1, sizeof parent);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (lisTD(nums, i) > ret) {
            ret = lisTD(nums, i);
            lisLastIndex = i;
        }
    }
    return ret;
}

int countLIS(vector<int>& nums, int lisLen) {
    int ret = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (lisLen == lisTD(nums, i)) ret++;
    }
    return ret;
}

void genLIS(vector<int>& nums, vector<int>& result, int i) {
    if (i == -1) return;
    genLIS(nums,result, parent[i]);
    result.push_back(nums[i]);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;
    int N;

    while (cin >> N) {
        vector<int> nums(N);
        for (int& x : nums) cin >> x;

        int lisLen = lis(nums);
        printf("LIS Length = %d\n", lisLen);
        printf("LIS Last Index = %d\n", lisLastIndex);
        printf("Number of LIS = %d\n", countLIS(nums, lisLen));

        vector<int> lisList;
        genLIS(nums, lisList, lisLastIndex);
        printf("LIS List = ");
        for (auto x : lisList) printf("%d ", x);
        printf("\n\n");
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**
Classic DP Problem:
L[i] = 1 + max { L[j] }      where  0 <= j < i and A[j] < A[i]
L[0] = 1
**/

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
Number of LIS = 3
LIS List = 3 5 10 11 14

LIS Length = 6
LIS Last Index = 8
Number of LIS = 1
LIS List = 10 22 33 41 60 80

LIS Length = 4
LIS Last Index = 6
Number of LIS = 2
LIS List = 2 3 7 101

LIS Length = 1
LIS Last Index = 0
Number of LIS = 7
LIS List = 7

LIS Length = 4
LIS Last Index = 5
Number of LIS = 1
LIS List = 0 1 2 3

 **/

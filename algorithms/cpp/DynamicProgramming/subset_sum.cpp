#include<bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

/**
n = number of items
sum = desired sum
DP[n][sum] = DP[n-1][sum-val[n]] || DP[n-1][sum]     if val[n] <= sum (Take or Not Take)
           = DP[n-1][sum]                            if val[n] > sum  (Not Take)
           = false                                   if n == 0 and sum > 0
           = true                                    if sum == 0
**/
const int MAX_SUM = 100*200;
char memo[101][MAX_SUM+1];
bool subsetSum(vector<int>& nums, int n, int sum) {
    if (sum < 0) return 0;
    if (memo[n][sum] != -1) return memo[n][sum];
    if (sum == 0) return memo[n][sum] = 1;
    if (n == 0) return memo[n][sum] = 0;
    return memo[n][sum] = subsetSum(nums, n-1, sum-nums[n-1]) || subsetSum(nums, n-1, sum);
}

int main() {
    READ("../input.txt");
    int n, sum;

    while (cin >> n >> sum) {
        vector<int> nums(n);
        for(auto& x : nums) cin >> x;

        memset(memo, -1, sizeof memo);
        bool isPossible = subsetSum(nums, n, sum);
        printf("%s\n", isPossible ? "YES" : "NO");
    }

    return 0;
}

/**
 *
Input:
-----
13 20
6 3 5 10 11 2 9 14 13 7 4 8 12
9 100
10 22 9 33 21 50 41 60 80
8 30
10 9 2 5 3 7 101 18
7 15
7 7 7 7 7 7 7
6 10
0 1 0 3 2 3

Output:
------
YES
YES
YES
NO
NO


*/

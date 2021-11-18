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

const int MAX = int(1e4);

vector<int> A, L, C;

int lisTD(int i) {
    if(L[i] != -1) return L[i];

    int maxLen = 0;
    for (int j = i-1; j >= 0; j--) {
        lisTD(j);
        if (A[i] > A[j])
            maxLen = max(maxLen, L[j]);
    }
    if (maxLen == 0) C[i] = 1;
    else {
        for (int j = i-1; j >= 0; j--)
            if (A[i] > A[j] && L[j] == maxLen) C[i] += C[j];
    }

    L[i] = 1 + maxLen;
    return L[i];
}

// Complexity : O(n^2)
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    A = nums;
    L = vector<int>(n, -1);
    C = vector<int>(n, 0);

    int ret = 0;
    lisTD(n-1);
    int lisLen = 0;
    for (int i = 0; i < n; i++) lisLen = max(lisLen, L[i]);
    for (int i = 0; i < n; i++) if (L[i] == lisLen) ret += C[i];
    return ret;
}

// Complexity : O(n lg n)
// Need to complete this method.
int findNumberOfLIS_2(vector<int>& nums) {
    int n = nums.size();
    vector<int> L(n, 0);
    vector<int> C(n, 0);

    vector<vector<int>> piles (n, vector<int>());
    vector<int> currentPiles(n, INT_MAX);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(currentPiles.begin(), currentPiles.end(), nums[i]) - currentPiles.begin();
        currentPiles[pos] = nums[i];
        piles[0].push_back(nums[i]);
        L[i] = pos + 1;  // +1 because pos is 0 based

        if (pos == 0) {
            C[i] = 1;
        } else {

        }

    }
}

int main()
{
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (auto& x : nums) cin >> x;

        int cnt = findNumberOfLIS(nums);

        cout << "L = ";
        for (int i = 0; i < n; i++) cout << L[i] << " ";
        cout << endl;
        cout << "C = ";
        for (int i = 0; i < n; i++) cout << C[i] << " ";
        cout << endl;

        printf("LIS Count = %d\n", cnt);
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**

Input:
5
1 3 5 4 7
5
2 2 2 2 2
8
1 2 4 3 5 4 7 2


Output:


 **/

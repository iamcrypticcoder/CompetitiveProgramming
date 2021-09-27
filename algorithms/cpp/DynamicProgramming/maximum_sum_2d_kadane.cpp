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

int maximumSum2D(vector<vector<int>> v) {
    if (v.size() == 0 || v[0].size() == 0) return 0;

    int m = v.size();
    int n = v[0].size();

    // Start from 2nd row
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = v[i-1][j] + v[i][j];
        }
    }

    int maxSum = v[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            int curMax = (i == 0 ? v[j][0] : v[j][0] - v[i-1][0]);
            for (int k = 1; k < n; k++) {
                int val = i == 0 ? v[j][k] : v[j][k] - v[i-1][k];
                curMax = max(val, curMax + val);
                maxSum = max(maxSum, curMax);
            }
        }
    }

    return maxSum;
}

int main()
{
    //READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    int m, n;
    while (cin >> m >> n) {
        vector<vector<int>> v = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
            cin >> v[i][j];

        cout << maximumSum2D(v) << endl;
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


/**
Input:
4 4
 0 -2 -7  0
 9  2 -6  2
-4  1 -4  1
-1  8  0 -2

Output:
15

**/

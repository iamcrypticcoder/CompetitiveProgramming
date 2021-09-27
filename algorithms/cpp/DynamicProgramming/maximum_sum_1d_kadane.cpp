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

int maximumSum1D(vector<int> v) {
    int n = v.size();
    int curMax = v[0];
    int maxSum = v[0];
    for (int i = 1; i < n; i++) {
        curMax = max(v[i], curMax + v[i]);
        maxSum = max(maxSum, curMax);
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

    int n;
    while (cin >> n) {
        vector<int> v = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        cout << maximumSum1D(v) << endl;
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


/**
Input:
 
8
-2 -3 4 -1 -2 1 5 -3
8
-2 -3 -4 -1 -2 -1 -5 -3
9
-2 1 -3 4 -1 2 1 -5 4

 
Output:
 
7
-1
6

**/

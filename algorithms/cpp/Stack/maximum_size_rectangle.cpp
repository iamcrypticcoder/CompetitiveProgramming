// C++ program to find maximum rectangular area in
// linear time
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


int maxHist(vector<int> hist) {
    stack<int> st;
    int ret = 0;

    int i = 0;
    while (i < hist.size()) {
        if (st.empty() || hist[st.top()] <= hist[i]) {
            st.push(i++);
            continue;
        }
        int top = st.top();
        st.pop();
        int area = hist[top] * (st.empty() ? i : i - st.top() - 1);
        ret = max(ret, area);
    }

    while (!st.empty()) {
        int top = st.top();
        st.pop();
        int area = hist[top] * (st.empty() ? i : i - st.top() - 1);
        ret = max(ret, area);
    }

    return ret;
}

int maxRect(vector<vector<int>> mat) {
    if (mat.size() == 0) return 0;
    int ret = INT_MIN;
    int R = mat.size();
    int C = mat[0].size();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i > 0 && mat[i][j])
                mat[i][j] = mat[i - 1][j] + 1;
        }
        ret = max(ret, maxHist(mat[i]));
    }
    return ret;
}

// https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    vector<vector<int>> arrList;
    arrList.push_back(vector<int> {0, 1, 1, 0});
    arrList.push_back(vector<int> {1, 1, 1, 1});
    arrList.push_back(vector<int> {1, 1, 1, 1});
    arrList.push_back(vector<int> {1, 1, 0, 0});
    cout << maxRect(arrList) << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
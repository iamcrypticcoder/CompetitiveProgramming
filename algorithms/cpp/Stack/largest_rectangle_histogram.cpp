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

// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    vector<vector<int>> arrList;
    arrList.push_back(vector<int> {1, 2, 3, 4, 5});
    arrList.push_back(vector<int> {5, 4, 3, 2, 1});
    arrList.push_back(vector<int> {1, 2, 3, 4, 5, 4, 3, 2, 1});
    arrList.push_back(vector<int> {6, 2, 5, 4, 5, 1, 6});

    for (int i = 0; i < arrList.size(); i++) {
        int ret = maxHist(arrList[i]);
        cout << ret << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
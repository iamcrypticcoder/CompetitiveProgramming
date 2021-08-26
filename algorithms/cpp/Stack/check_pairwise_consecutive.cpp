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

bool check(stack<int> &st, int lastVal) {
    if (st.empty())
        return true;

    int top = st.top();
    st.pop();
    if (lastVal != INT_MAX && abs(lastVal - top) > 1) {
        st.push(top);
        return false;
    }
    bool ret = check(st, top);
    st.push(top);
    return ret;
}


// https://www.geeksforgeeks.org/check-if-stack-elements-are-pairwise-consecutive/
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    vector<vector<int>> arrList;
    arrList.push_back(vector<int> {1, 2, 3, 4, 5, 6});
    arrList.push_back(vector<int> {1, 2, 3, 5});
    arrList.push_back(vector<int> {3, 5, 6});

    for (int i = 0; i < arrList.size(); i++) {
        stack<int> st;
        for (int j = 0; j < arrList[i].size(); j++)
            st.push(arrList[i][j]);
        cout << check(st, INT_MAX) << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
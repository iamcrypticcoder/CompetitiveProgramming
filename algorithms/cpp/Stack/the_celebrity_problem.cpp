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

int findCelebrity(vector<vector<int>> mat) {
    stack<int> st;
    for (int i = 0; i < mat.size(); i++)
        st.push(i);

    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        // If a knows b, then a isn't celebrity
        if (mat[a][b]) st.push(b);
        else st.push(a);
    }

    int ret = st.top();
    st.pop();
    for (int i = 0; i < mat[ret].size(); i++) {
        if (ret == i) continue;
        if (mat[ret][i] == 1 || mat[i][ret] == 0) return -1;
    }
    return ret;
}

// https://www.geeksforgeeks.org/the-celebrity-problem/
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    vector<vector<int>> mat1;
    mat1.push_back(vector<int> {0, 0, 1, 0});
    mat1.push_back(vector<int> {0, 0, 1, 0});
    mat1.push_back(vector<int> {0, 0, 0, 0});
    mat1.push_back(vector<int> {0, 0, 1, 0});
    cout << findCelebrity(mat1) << endl;

    vector<vector<int>> mat2;
    mat2.push_back(vector<int> {0, 0, 1, 0});
    mat2.push_back(vector<int> {0, 0, 1, 0});
    mat2.push_back(vector<int> {0, 0, 0, 0});
    mat2.push_back(vector<int> {0, 0, 1, 0});
    mat2.push_back(vector<int> {0, 0, 0, 0});
    cout << findCelebrity(mat2) << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
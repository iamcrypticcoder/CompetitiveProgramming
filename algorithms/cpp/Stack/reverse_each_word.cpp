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

string reverseEachWord(string s) {
    string ret = "";
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '.') {
            st.push(s[i]);
            continue;
        }
        while (!st.empty()) {
            ret += st.top();
            st.pop();
        }
        ret += '.';
    }
    while (!st.empty()) {
        ret += st.top();
        st.pop();
    }
    return ret;
}

// https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1/?category[]=Stack&category[]=Stack&page=2&query=category[]Stackpage2category[]Stack
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    vector<string> strList;
    strList.push_back("i.like.this.program.very.much");
    strList.push_back("pqr.mno");

    for (tc = 0; tc < strList.size(); tc++) {
        cout << reverseEachWord(strList[tc]) << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
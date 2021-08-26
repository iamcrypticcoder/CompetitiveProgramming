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

stack<int> s1, s2;

void initQueue() {
    s1 = stack<int>();
    s2 = stack<int>();
}

void queuePush(int val) {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(val);
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

int queuePop() {
    if (s1.empty()) return INT_MIN;
    int ret = s1.top();
    s1.pop();
    return ret;
}

int queueFront() {
    if (s1.empty()) return INT_MIN;
    return s1.top();
}

bool isEmpty() {
    return s1.empty();
}

int main() {
    initQueue();

    vector<int> v {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < v.size(); i++) {
        queuePush(v[i]);
    }
    cout << queueFront() << endl;

    while (!isEmpty()) {
        cout << queuePop() << " ";
    }

    cout << endl;
}
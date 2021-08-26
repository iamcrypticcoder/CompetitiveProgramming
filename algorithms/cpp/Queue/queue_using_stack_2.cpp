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
int front;

void initQueue() {
    s1 = stack<int>();
    s2 = stack<int>();
}

void queuePush(int val) {
    s1.push(val);
    if (s1.size() == 1) front = val;
}

int queuePop() {
    if (s1.empty()) return INT_MIN;

    while (s1.size() > 1) {
        s2.push(s1.top());
        s1.pop();
    }
    int ret = s1.top();
    s1.pop();
    if (!s2.empty()) front = s2.top();
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
    return ret;
}

int queueFront() {
    if (s1.empty()) return INT_MIN;
    return front;
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
        cout << "queuePop(): " << queuePop() << ", queueFront = " << queueFront() << endl;
    }

    cout << endl;
}
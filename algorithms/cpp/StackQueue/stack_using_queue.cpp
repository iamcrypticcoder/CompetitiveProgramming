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

queue<int> q1;
queue<int> q2;

void initStack() {
    q1 = queue<int>();
    q2 = queue<int>();
}

void stackPush(int val) {
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(val);
    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
}

int stackPop() {
    if (q1.empty()) return INT_MIN;
    int ret = q1.front();
    q1.pop();
    return ret;
}

int stackTop() {
    if (q1.empty()) return INT_MIN;
    return q1.front();
}

bool isEmpty() {
    return q1.empty();
}

int main() {
    initStack();
    stackPush(1);
    stackPush(2);
    stackPush(3);
    stackPush(4);

    cout << stackTop() << endl;

    stackPush(5);
    stackPush(6);
    stackPush(7);

    while (!isEmpty()) {
        cout << stackPop() << " ";
    }
    cout << endl;
}
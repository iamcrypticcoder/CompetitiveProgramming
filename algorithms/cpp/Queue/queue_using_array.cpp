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

const int MAX = 5;

int first, last;
int queueArr[MAX];
int queueSize;

void initQueue() {
    first = last = -1;
}

void queuePush(int val) {
    queueSize++;
    if (first == -1) {
        queueArr[0] = val;
        first = last = 0;
        return;
    }

    int nextIndex = (last + 1) % MAX;
    if (nextIndex == first) {
        cout << "Memory overflow" << endl;
        return;
    }
    queueArr[nextIndex] = val;
    last = nextIndex;
}

int queuePop() {
    if (first == -1) return INT_MIN;
    queueSize--;
    int ret = queueArr[first];
    if (first == last)
        first = last = -1;
    else first = (first + 1) % MAX;

    return ret;
}

int queueFront() {
    if (first == -1) return INT_MIN;
    return queueArr[first];
}

bool isEmpty() {
    return (first == -1);
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
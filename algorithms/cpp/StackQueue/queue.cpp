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

struct Node {
    int val;
    Node* next;

    Node();
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

Node *first, *last;
int queueSize;

void initQueue() {
    first = last = NULL;
    queueSize = 0;
}

void queuePush(Node val) {
    queueSize++;
    Node *node = new Node(val);
    if (NULL == first) {
        first = node;
        last = node;
        return;
    }
    last->next = node;
    last = last->next;
}

int queuePop() {
    if (NULL == first) return INT_MIN;
    queueSize--;
    int ret = first->val;
    first = first->next;
    return ret;
}

int queueFront() {
    if (NULL == first) return INT_MIN;
    return first->val;
}

bool isEmpty() {
    return (NULL == first);
}

int main() {
    initQueue();
    queuePush(1);
    queuePush(2);
    queuePush(3);
    queuePush(4);
    queuePush(5);

    cout << queueFront() << endl;

    while (!isEmpty()) {
        cout << queuePop() << " ";
    }
    cout << endl;
}
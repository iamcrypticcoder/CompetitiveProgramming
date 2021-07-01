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
    }
};

Node* top;
int stackSize;

void initStack() {
    top = NULL;
    stackSize = 0;
}

void stackPush(int val) {
    stackSize++;
    if (NULL == top) {
        top = new Node(val);
        return;
    }
    Node* node = new Node(val);
    node->next = top;
    top = node;
}

int stackPop() {
    if (NULL == top) return INT_MIN;
    int ret = top->val;
    top = top->next;
    stackSize--;
    return ret;
}

int stackTop() {
    if (NULL == top) return INT_MIN;
    return top->val;
}

bool isEmpty() {
    return (NULL == top);
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
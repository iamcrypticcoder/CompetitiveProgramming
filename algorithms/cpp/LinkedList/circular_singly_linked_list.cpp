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
    Node *next = NULL;

    Node();
    Node(int val) {
        this->val = val;
    }
};

Node *last;
int size;

void initLinkedList() {
    last = NULL;
    size = 0;
}

// Complexity: O(1)
void insertAtFirst(int val) {
    if (NULL == last) {
        last = new Node(val);
        last->next = last;
        return;
    }
    Node *newNode = new Node(val);
    Node *next = last->next;
    last->next = newNode;
    newNode->next = next;
}

// Complexity: O(1)
void insertAtLast(int val) {
    if (NULL == last) {
        last = new Node(val);
        last->next = last;
        return;
    }
    Node *newNode = new Node(val);
    Node *next = last->next;
    last->next = newNode;
    newNode->next = next;
    last = newNode;
}


vector<int> asVector() {
    vector<int> ret;
    Node *ptr = last;
    do {
        ret.push_back(ptr->val);
        ptr = ptr->next;
    } while (ptr != last);
    return ret;
}


int main() {
    int arr[] = {10, 5, 6, 9, 20, 13, 1, 25};
    int cnt = sizeof(arr) / sizeof(arr[0]);

    initLinkedList();
    for (int i = 0; i < cnt; i++) {
        insertAtFirst(arr[i]);
    }

    vector<int> v = asVector();
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}
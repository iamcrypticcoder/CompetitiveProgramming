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

Node* makeLinkedList(vector<int> v) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < v.size(); i++) {
        int val = v[i];
        if (NULL == head) {
            head = new Node(val);
            tail = head;
            continue;
        }
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}

// Complexity: O(size)
vector<int> toVector(Node* head) {
    vector<int> ret;
    Node *ptr = head;
    while (NULL != ptr) {
        ret.push_back(ptr->val);
        ptr = ptr->next;
    }
    return ret;
}

void rorateLinkedList(Node **headRef, int k) {
    if (NULL == *headRef || k == 0) return;
    Node *head = *headRef;
    Node *ptr = head;
    int c = 1;
    while (c < k && NULL != ptr) {
        ptr = ptr->next;
        c++;
    }
    // If reach at end node or beyond, no need to rotate
    if (NULL == ptr || NULL == ptr->next) return;

    Node *next = ptr->next;
    ptr->next = NULL;
    ptr = next;
    while (NULL != ptr->next)
        ptr = ptr->next;
    ptr->next = head;
    *headRef = next;
}

// https://www.geeksforgeeks.org/rotate-a-linked-list/
int main() {
    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{0, 1, 2, 3, 4, 5, 6});

    for (int tc = 0; tc < inputs.size(); tc++) {
        for (int k = 0; k <= inputs[tc].size(); k++) {
            cout << "rorateLinkedList() : k = " << k << " : ";
            Node *head = makeLinkedList(inputs[tc]);
            rorateLinkedList(&head, k);
            vector<int> v = toVector(head);
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
        }
    }

    return 0;
}
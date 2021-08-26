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
#include <unordered_set>

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

Node* nthNodeFromEnd(Node *head, int n) {
    if (n == 0) return NULL;

    Node* slow = head;
    Node *fast = head;
    while (n > 0 && NULL != fast) {
        fast = fast->next;
        n--;
    }

    if (NULL == fast) {
        if (n == 0) return head;
        if (n  > 0) return NULL;
    }

    while (NULL != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
int main() {
    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{0, 1, 2, 3, 4, 5, 6, 7});

    for (int tc = 0; tc < inputs.size(); tc++) {
        vector<int> v = inputs[tc];
        Node *head = makeLinkedList(v);

        for (int n = 0; n <= v.size()+3; n++) {
            cout << "nthNodeFromEnd() : n = " << n << " : ";
            Node *nthNode = nthNodeFromEnd(head, n);
            if (NULL == nthNode) cout << "NULL";
            else cout << nthNode->val;
            cout << endl;
        }
    }

    return 0;
}
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

// Return reversed linked list head
// Complexity : O(n)
Node* reverseLinkedList(Node* head) {
    if (NULL == head) return NULL;
    Node *ptr = head;
    Node *prev = NULL, *next = NULL;
    while (NULL != ptr) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
    return head;
}

Node* reverseInGroupsRecur(Node* head, int k) {
    if (NULL == head) return NULL;
    Node *ptr = head, *prev = NULL, *next = NULL;
    int count = 0;
    while (NULL != ptr && count < k) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
        count++;
    }

    if (NULL != next)
        head->next = reverseInGroupsRecur(next, k);

    return prev;
}

Node* reverseInGroups_UsingStack(Node* head, int k)  {
    if (NULL == head) return NULL;
    Node *nHead = NULL;
    Node *nTail = NULL;
    Node *ptr = head;
    stack<Node*> s;

    while (NULL != ptr) {
        int count = 0;
        while (NULL != ptr && count < k) {
            s.push(ptr);
            ptr = ptr->next;
            count++;
        }

        while (!s.empty()) {
            if (NULL == nHead) {
                nHead = nTail = s.top();
                s.pop();
            } else {
                nTail->next = s.top();
                nTail = nTail->next;
                s.pop();
            }
        }
    }
    nTail->next = NULL;
    return nHead;
}

Node* reverseInGroups(Node* head, int k) {
    if (NULL == head) return NULL;
    Node *ret = NULL;
    Node *tHead = NULL, *tTail = NULL, *prevGroupTail = NULL;
    Node *ptr = head;
    int c;

    while (NULL != ptr) {
        c = 0;
        tHead = tTail = NULL;
        while (NULL != ptr && c < k) {
            c++;
            if (NULL == tHead) {
                tHead = tTail = ptr;
            } else {
                tTail->next = ptr;
                tTail = tTail->next;
            }
            ptr = ptr->next;
        }

        tTail->next = NULL;
        Node *revHead = reverseLinkedList(tHead);
        // For first group
        if (NULL == prevGroupTail) {
            ret = revHead;
        } else {
            // Link to previous group
            prevGroupTail->next = revHead;
        }
        prevGroupTail = tHead;
    }
    return ret;
}

// https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
// https://www.geeksforgeeks.org/reverse-linked-list-groups-given-size-set-2/
int main() {
    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{0});
    inputs.push_back(vector<int>{0, 1});
    inputs.push_back(vector<int>{0, 1, 2});
    inputs.push_back(vector<int>{0, 1, 2, 3});
    inputs.push_back(vector<int>{0, 1, 2, 3, 4, 5});
    inputs.push_back(vector<int>{0, 1, 2, 3, 4, 5, 6, 7});

    for (int tc = 0; tc < inputs.size(); tc++) {
        vector<int> v;
        Node *head;

        cout << "reverseInGroupsRecur() : ";
        head = makeLinkedList(inputs[tc]);
        Node *rev = reverseInGroupsRecur(head, 2);
        v = toVector(rev);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;

        cout << "reverseLinkedListRecur() : ";
        head = makeLinkedList(inputs[tc]);
        rev = reverseInGroups_UsingStack(head, 2);
        v = toVector(rev);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;

        cout << "reverseInGroups() : ";
        head = makeLinkedList(inputs[tc]);
        rev = reverseInGroups(head, 2);
        v = toVector(rev);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl << endl;
    }

    return 0;
}
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

// Time complexity : O(n)
// Auxiliary Space : O(n)
bool detectLoop_UsingHash(Node *head) {
    unordered_set<Node*> s;
    Node *ptr = head;
    while (NULL != ptr) {
        if (s.find(ptr) != s.end())
            return true;
        s.insert(ptr);
        ptr = ptr->next;
    }
    return false;
}

// Time complexity : O(n)
// Auxiliary Space : O(1)
bool detectLoop_UsingFloyd(Node *head) {
    Node *slow = head, *fast = head;
    while (NULL != slow && NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// Time complexity : O(n)
// Auxiliary Space : O(n)
bool detectLoop_UsingTempNode(Node *head) {
    Node *ptr = head;
    Node *dummy = new Node(INT_MIN);
    while (NULL != ptr) {
        if (ptr->next == dummy)
            return true;

        Node *next = ptr->next;
        ptr->next = dummy;
        ptr = next;
    }
    return false;
}

// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
int main() {
    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{0});
    inputs.push_back(vector<int>{0, 1});
    inputs.push_back(vector<int>{0, 1, 2, 3, 4, 5, 6, 7});

    for (int tc = 0; tc < inputs.size(); tc++) {
        Node *head = makeLinkedList(inputs[tc]);

        cout << "detectLoop_UsingHash() : " << detectLoop_UsingHash(head) << endl;
        cout << "detectLoop_UsingFloyd() : " << detectLoop_UsingFloyd(head) << endl;
        cout << "detectLoop_UsingTempNode() : " << detectLoop_UsingTempNode(head) << endl;
        cout << endl;
    }

    // Create cycle linked list
    Node *head1 = makeLinkedList(inputs[0]);
    head1->next = head1;

    Node *head2 = makeLinkedList(inputs[1]);
    head2->next->next = head2;

    Node *head3 = makeLinkedList(inputs[2]);
    Node *tail = head3;
    while (NULL != tail->next) tail = tail->next;
    tail->next = head3->next->next->next;

    vector<Node*> headList {head1, head2, head3};

    for (int tc = 0; tc < headList.size(); tc++) {
        vector<int> v;
        Node *head = headList[tc];

        cout << "detectLoop_UsingHash() : " << detectLoop_UsingHash(head) << endl;
        cout << "detectLoop_UsingFloyd() : " << detectLoop_UsingFloyd(head) << endl;
        cout << "detectLoop_UsingTempNode() : " << detectLoop_UsingTempNode(head) << endl;
        cout << endl;
    }

    return 0;
}
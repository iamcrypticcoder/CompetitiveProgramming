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
bool removeLoop_UsingHash(Node *head) {
    unordered_set<Node*> s;
    Node *ptr = head, *last = head;
    while (NULL != ptr) {
        if (s.find(ptr) != s.end()) {
            last->next = NULL;
            return true;
        }
        s.insert(ptr);
        last = ptr;
        ptr = ptr->next;
    }
    return false;
}

// Time complexity : O(n)
// Auxiliary Space : O(1)
bool removeLoop_UsingFloyd(Node *head) {
    if (NULL == head) return false;
    Node *slow = head, *fast = head;
    while (NULL != slow && NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Start Remove loop
            Node *ptr1 = slow, *ptr2 = slow->next;
            // Count nodes in loop
            int k = 1;
            while (ptr2 != ptr1) {
                ptr2 = ptr2->next;
                k++;
            }
            // One pointer starts from head, another from kth node from head
            ptr1 = ptr2 = head;
            Node *prev = head;
            while (k > 0) {
                prev = ptr2;
                ptr2 = ptr2->next;
                k--;
            }
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                prev = ptr2;
                ptr2 = ptr2->next;
            }
            prev->next = NULL;
            return true;
        }
    }
    return false;
}

// Time complexity : O(n)
// Auxiliary Space : O(1)
// Optimized than above method
bool removeLoop_UsingFloyd2(Node *head) {
    if (NULL == head) return false;
    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (NULL != fast && NULL != fast->next) {
        if (slow == fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != fast) return false;

    // Start slow from head
    slow = head;
    if (slow == fast) {
        while (fast->next != slow) fast = fast->next;
    }
    else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;
    return true;
}

int main() {
    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{0});
    inputs.push_back(vector<int>{0, 1});
    inputs.push_back(vector<int>{0, 1, 2, 3, 4, 5, 6, 7});

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

//        cout << "removeLoop_UsingHash() : " << removeLoop_UsingHash(head) << endl;
//        v = toVector(head);
//        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
//        cout << endl;

//        cout << "removeLoop_UsingFloyd() : " << removeLoop_UsingFloyd(head) << endl;
//        v = toVector(head);
//        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
//        cout << endl;

        cout << "removeLoop_UsingFloyd2() : " << removeLoop_UsingFloyd2(head) << endl;
        v = toVector(head);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}
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

Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = new Node(INT_MIN);
    Node* tail = head;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while (NULL != ptr1 && NULL != ptr2) {
        if (ptr1->val < ptr2->val) {
            tail->next = ptr1;
            ptr1 = ptr1->next;
        } else {
            tail->next = ptr2;
            ptr2 = ptr2->next;
        }
        tail = tail->next;
    }
    if (NULL != ptr1) tail->next = ptr1;
    if (NULL != ptr2) tail->next = ptr2;
    return head->next;
}

vector<int> toVector(Node* head) {
    vector<int> ret;
    Node *ptr = head;
    while (NULL != ptr) {
        ret.push_back(ptr->val);
        ptr = ptr->next;
    }
    return ret;
}

// https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
// https://www.geeksforgeeks.org/flattening-a-linked-list/
int main() {
    vector<int> list1 {5, 10, 20, 25};
    vector<int> list2 {1, 10, 20, 30};
    vector<int> list3 {3,  9, 12, 15, 18, 21};

    Node* head1 = makeLinkedList(list1);
    Node* head2 = makeLinkedList(list2);
    Node* head3 = makeLinkedList(list3);

    Node* ret = mergeLinkedList(head1, head2);
    ret = mergeLinkedList(ret, head3);
    vector<int> v = toVector(ret);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
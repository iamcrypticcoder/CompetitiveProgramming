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

void splitHalf(Node *head, Node **left, Node **right) {
    Node *slow = head, *fast = head->next;

    while (NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
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

void mergeSort(Node **headRef) {
    Node *head = *headRef;
    Node *left, *right;

    if (NULL == head || NULL == head->next)
        return;

    splitHalf(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = mergeLinkedList(left, right);
}

// https://www.geeksforgeeks.org/merge-sort-for-linked-list/
int main() {
    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{});
    inputs.push_back(vector<int>{0});
    inputs.push_back(vector<int>{1, 0});
    inputs.push_back(vector<int>{40, 20, 60, 10, 50, 30});
    inputs.push_back(vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    inputs.push_back(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    for (int tc = 0; tc < inputs.size(); tc++) {
        vector<int> v = inputs[tc];
        Node *head = makeLinkedList(v);

        mergeSort(&head);
        v = toVector(head);
        cout << "mergeSort() : ";
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}
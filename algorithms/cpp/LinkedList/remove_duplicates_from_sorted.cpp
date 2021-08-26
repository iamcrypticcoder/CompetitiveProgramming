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

vector<int> toVector(Node* head) {
    vector<int> ret;
    Node *ptr = head;
    while (NULL != ptr) {
        ret.push_back(ptr->val);
        ptr = ptr->next;
    }
    return ret;
}

void removeDuplicates(Node* head) {
    if (NULL == head) return;
    Node* ptr = head;
    while (NULL != ptr) {
        int val = ptr->val;
        while (NULL != ptr->next && val == ptr->next->val)
            ptr->next = ptr->next->next;
        ptr = ptr->next;
    }
}

// https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
int main() {
    vector<int> list1 {11, 11, 11, 21, 43, 43, 60};

    Node* head1 = makeLinkedList(list1);
    removeDuplicates(head1);
    vector<int> v = toVector(head1);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
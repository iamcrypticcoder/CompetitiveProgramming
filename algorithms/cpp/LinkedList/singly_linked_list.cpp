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

Node *head, *tail;
int size;

void initLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

// Complexity: O(1)
bool insertAtFirst(int val) {
    Node* newNode = new Node(val);
    if (NULL == head) {
        head = newNode;
        tail = newNode;
        size++;
        return true;
    }

    newNode->next = head;
    head = newNode;
    size++;
    return true;
}

// Complexity: O(1)
bool insertAtLast(int val) {
    Node* newNode = new Node(val);
    if (NULL == head) {
        head = newNode;
        tail = newNode;
        size++;
        return true;
    }
    tail->next = newNode;
    tail = tail->next;
    size++;
    return true;
}

// Complexity: O(pos)
// Position starts from 0
bool insertAtPos(int val, int pos) {
    Node* newNode = new Node(val);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        size++;
        return true;
    }

    pos = pos - 1;
    Node *ptr = head;
    while(pos > 0 && NULL != ptr) {
        ptr = ptr->next;
        pos--;
    }
    Node *tmp = ptr->next;
    ptr->next = newNode;
    newNode->next = tmp;
    size++;
    return true;
}

// Complexity: O(1)
bool removeAtFirst() {
    if (size == 0) return false;
    head = head->next;
    size--;
    return true;
}

// Complexity: O(size)
bool removeAtLast() {
    if (size == 0) return false;
    if (size == 1) {
        head = NULL;
        tail = NULL;
        size = 0;
        return true;
    }

    Node *ptr = head;
    while (NULL != ptr->next && NULL != ptr->next->next) {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    tail = ptr;
    size--;
    return true;
}

// Complexity: O(size)
// Position starts from 0
bool removeAtPos(int pos) {
    if (pos > size-1) return false;
    if (pos == 0) {
        head = head->next;
        size--;
        return true;
    }

    pos = pos - 1;
    Node *ptr = head;
    while (pos > 0 && NULL != ptr) {
        ptr = ptr->next;
        pos--;
    }
    ptr->next = ptr->next->next;
    size--;
    return true;
}



// Complexity: O(size)
void asArray(int ret[], int n) {
//    ret = (int*) (malloc(size * sizeof(int)));
//    n = size;
//    int i = 0;
//    Node* ptr = head;
//    while (NULL != ptr) {
//        ret[i] = ptr->val;
//        ptr = ptr->next;
//        i = i + sizeof (int);
//    }
}

vector<int> asVector() {
    vector<int> ret;
    Node *ptr = head;
    while (NULL != ptr) {
        ret.push_back(ptr->val);
        ptr = ptr->next;
    }
    return ret;
}


int main() {
    int arr[] = {10, 5, 6, 9, 20, 13, 1, 25};
    int cnt = sizeof(arr) / sizeof(arr[0]);

    initLinkedList();
    for (int i = 0; i < cnt; i++) {
        insertAtLast(arr[i]);
    }
    insertAtFirst(100);
    insertAtPos(200, 2);

    vector<int> v = asVector();
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    removeAtFirst();
    removeAtLast();
    removeAtPos(2);

    v = asVector();
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;



    return 0;
}
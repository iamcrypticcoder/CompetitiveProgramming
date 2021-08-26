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

int getMiddle_Method_1(Node *head) {
    if (NULL == head) return INT_MIN;
    Node *ptr = head;
    int c = 0;
    while (NULL != ptr) {
        c++;
        ptr = ptr->next;
    }
    c = c / 2;
    ptr = head;
    while (c > 0) {
        c--;
        ptr = ptr->next;
    }
    return ptr->val;
}

// Complexity: O(n)
int getMiddle_Method_2(Node *head) {
    if (NULL == head) return INT_MIN;
    Node *slow = head, *fast = head;
    while (NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

int getMiddle_Method_3(Node *head) {
    if (NULL == head) return INT_MIN;
    Node *mid = head, *ptr = head;
    int count = 0;

    while (NULL != ptr) {
        if (count & 1) mid = mid->next;
        count++;
        ptr = ptr->next;
    }
    return mid->val;
}



// Complexity: O(size)
vector<int> asVector() {
    vector<int> ret;
    Node *ptr = head;
    while (NULL != ptr) {
        ret.push_back(ptr->val);
        ptr = ptr->next;
    }
    return ret;
}

// https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
int main() {
//    int arr1[] = {0};
//    int arr2[] = {0, 1};
//    int arr3[] = {0, 1, 2};
//    int arr4[] = {0, 1, 2, 3};

    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{0});
    inputs.push_back(vector<int>{0, 1});
    inputs.push_back(vector<int>{0, 1, 2});
    inputs.push_back(vector<int>{0, 1, 2, 3});

    for (int tc = 0; tc < inputs.size(); tc++) {
        vector<int> v = inputs[tc];
        initLinkedList();
        for (int i = 0; i < v.size(); i++) {
            insertAtLast(v[i]);
        }
        cout << "tc = " << tc << endl;
        cout << "getMiddle_Method_1() : " << getMiddle_Method_1(head) << endl;
        cout << "getMiddle_Method_2() : " << getMiddle_Method_2(head) << endl;
        cout << "getMiddle_Method_3() : " << getMiddle_Method_3(head) << endl;
        cout << endl;
    }

//    initLinkedList();
//    int cnt = sizeof(arr1) / sizeof(arr1[0]);
//    for (int i = 0; i < cnt; i++) {
//        insertAtLast(arr1[i]);
//    }
//
//    cout << "getMiddle_Method_1() : " << getMiddle_Method_1(head) << endl;
//    cout << "getMiddle_Method_2() : " << getMiddle_Method_2(head) << endl;
//    cout << "getMiddle_Method_3() : " << getMiddle_Method_3(head) << endl;
//
//    int cnt = sizeof(arr) / sizeof(arr[0]);
//
//    initLinkedList();
//    for (int i = 0; i < cnt; i++) {
//        insertAtLast(arr[i]);
//    }
//
//    cout << getMiddle() << endl;
//
//    vector<int> v = asVector();
//    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
//    cout << endl;

    return 0;
}
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

// Return middle element value
// http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
// Complexity: O(n)
int getMiddle() {
    if (NULL == head) return -1;
    Node *slow = head;
    Node *fast = head->next;
    while (NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
void pairWiseSwap() {
    Node *ptr = head;
    while (NULL != ptr) {
        // Swap values of ptr and ptr.next
        int t = ptr->val;
        ptr->val = ptr->next->val;
        ptr->next->val = t;
        ptr = ptr->next->next;
    }
}

// Is Palindrome
// Given a linked list, check if it is a palindrome in terms of values
// Ex: 0 -> 1 -> 2 -> 1 -> 0
// Ex: 0 -> 1 -> 2 -> 2 -> 1 -> 0
// Ex: 1 -> 2 -> 3 -> 3 -> 2 -> 1
bool isPalindrome(Node* head) {
    Node *slow = head;
    Node *fast = head;
    stack<int> stack;

    while (NULL != fast && NULL != fast->next) {
        stack.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    // Has odd number of element
    if (NULL != fast) {
        slow = slow->next;
    }

    while (NULL != slow) {
        int top = stack.top();
        stack.pop();

        if (top != slow->val) {
            return false;
        }
        slow = slow->next;
    }
    return true;
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


int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int cnt = sizeof(arr) / sizeof(arr[0]);

    initLinkedList();
    for (int i = 0; i < cnt; i++) {
        insertAtLast(arr[i]);
    }

    cout << getMiddle() << endl;

    pairWiseSwap();
    vector<int> v = asVector();
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}
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
void asArray(int *ret, int *n) {
    ret = (int*) (malloc(size * sizeof(int)));
    *n = size;
    int i = 0;
    Node* ptr = head;
    while (NULL != ptr) {
        ret[i] = ptr->val;
        ptr = ptr->next;
        i = i + sizeof (int);
    }
}


int main() {
    insertAtFirst(1);
    insertAtLast(2);
    insertAtLast(3);
    insertAtLast(3);
    insertAtLast(2);
    insertAtLast(1);

    cout << isPalindrome(head) << endl;

    return 0;
}
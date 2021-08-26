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
// Is Palindrome
// Given a linked list, check if it is a palindrome in terms of values
// Ex: 0
// Ex: 0 -> 0
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

// https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
int main() {
    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{0});
    inputs.push_back(vector<int>{0, 0});
    inputs.push_back(vector<int>{0, 1, 2, 1, 0});
    inputs.push_back(vector<int>{0, 1, 2, 2, 1, 0});
    inputs.push_back(vector<int>{1, 2, 3, 3, 2, 1});
    inputs.push_back(vector<int>{0, 1});
    inputs.push_back(vector<int>{0, 1, 2});

    for (int tc = 0; tc < inputs.size(); tc++) {
        Node *head = makeLinkedList(inputs[tc]);
        cout << "isPalindrome() : " << isPalindrome(head) << endl;
    }

    return 0;
}
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
    int key;
    Node* parent = NULL;
    Node* left = NULL;
    Node* right = NULL;

    Node() {}
    Node(int key) {
        this->key = key;
    }
    Node(Node* parent, int key) {
        this->parent = parent;
        this->key = key;
    }
};

void printVector(string title, vector<int> v) {
    cout << title << ": ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

void leftView(Node* n, vector<int> &list) {
    if (NULL == n) return;

    list.push_back(n->key);

    if (NULL != n->left)
        leftView(n->left, list);
    else if (NULL != n->right)
        leftView(n->right, list);
}

void leftViewReverse(Node* n, vector<int> &list) {
    if (NULL == n) return;

    if (NULL != n->left)
        leftViewReverse(n->left, list);
    else if (NULL != n->right)
        leftViewReverse(n->right, list);
    list.push_back(n->key);
}

void rightView(Node* n, vector<int> &list) {
    if (NULL == n) return;

    list.push_back(n->key);
    if (NULL != n->right)
        rightView(n->right, list);
    else if (NULL != n->left)
        rightView(n->left, list);
}

void topView(Node* n, vector<int>& list) {
    leftViewReverse(n, list);
    rightView(n, list);
}

void bottomView(Node* n, vector<int> &list) {
    if (NULL == n) return;

    bottomView(n->left, list);
    if (NULL == n->left && NULL == n->right)
        list.push_back(n->key);
    bottomView(n->right, list);
}

int main() {
    Node* root = new Node(NULL, 1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);

    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);

    root->right->left = new Node(root->right, 6);
    root->right->right = new Node(root->right, 7);

    root->left->left->left = new Node(root->left->left, 8);
    root->left->left->right = new Node(root->left->left, 9);

    root->left->right->left = new Node(root->left->right, 10);

    /**
    *            1
    *         /     \
    *        2       3
    *      /   \   /   \
    *     4    5  6    7
    *    / \    \
    *   8   9   10
    *
    *   Result: 1 2 4 8 9 10 6 7 3
    */

    vector<int> v;
    leftView(root, v);
    printVector("Left View", v);

    v.clear();
    rightView(root, v);
    printVector("Right View", v);

    v.clear();
    topView(root, v);
    printVector("Top View", v);

    v.clear();
    bottomView(root, v);
    printVector("Bottom View", v);

}

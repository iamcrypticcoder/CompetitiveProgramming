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

void findLeftNodes(Node* n, vector<int> &list) {
    if (NULL == n) return;

    list.push_back(n->key);

    if (NULL != n->left)
        findLeftNodes(n->left, list);
    else if (NULL != n->right)
        findLeftNodes(n->right, list);
}

void findLeafNodes(Node* n, vector<int> &list) {
    if (NULL == n) return;

    findLeafNodes(n->left, list);
    if (NULL == n->left && NULL == n->right)
        list.push_back(n->key);
    findLeafNodes(n->right, list);
}

void findRightNodes(Node* n, vector<int> &list) {
    if (NULL == n) return;

    if (NULL != n->right)
        findRightNodes(n->right, list);
    else if (NULL != n->left)
        findRightNodes(n->left, list);
    list.push_back(n->key);
}

vector<int> findBoundaryNodes(Node* root) {
    // Find all left side nodes
    vector<int> list;
    findLeftNodes(root, list);

    // Last element will be added again. That's why deleting it
    if (list.size() > 0) list.pop_back();

    // Find leaf nodes
    findLeafNodes(root, list);

    // Last element will be added again. That's why deleting it
    if (list.size() > 0) list.pop_back();

    // Find all right nodes
    findRightNodes(root, list);

    // Last element is actually root element. That's why deleting it
    if (list.size() > 0) list.pop_back();

    return list;
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

    vector<int> list = findBoundaryNodes(root);
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
}

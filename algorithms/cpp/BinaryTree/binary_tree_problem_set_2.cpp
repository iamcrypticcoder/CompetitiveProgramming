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

void preOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    list.push_back(n->key);
    preOrderRecursive(n->left, list);
    preOrderRecursive(n->right, list);
}
vector<int> preOrderRecursive(Node *root) {
    vector<int> list;
    preOrderRecursive(root, list);
    return list;
}

void inOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    inOrderRecursive(n->left, list);
    list.push_back(n->key);
    inOrderRecursive(n->right, list);
}
vector<int> inOrderRecursive(Node *root) {
    vector<int> list;
    inOrderRecursive(root, list);
    return list;
}

void postOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    postOrderRecursive(n->left, list);
    postOrderRecursive(n->right, list);
    list.push_back(n->key);
}
vector<int> postOrderRecursive(Node *root) {
    vector<int> list;
    postOrderRecursive(root, list);
    return list;
}

int findDepth(Node* n) {
    if (NULL == n) return 0;
    int ret = 0;
    while (NULL != n->left) {
        ret++;
        n = n->left;
    }
    return ret;
}

/**
 * Check perfect binary tree
 * https://www.geeksforgeeks.org/check-weather-given-binary-tree-perfect-not/
 * @return
 */
bool isPerfectBinaryTree(Node* n, int level, int depth) {
    if (NULL == n->left && NULL != n->right) return false;
    if (NULL != n->left && NULL == n->right) return false;

    if (NULL == n->left && NULL == n->right)
        return (level == depth);

    return
    isPerfectBinaryTree(n->left, level+1, depth) &&
    isPerfectBinaryTree(n->right, level+1, depth);
}

/**
 * Given a binary tree, check whether it is a mirror of itself.
 * https://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/
 */
bool isMirror(Node* n1, Node* n2) {
    if (NULL == n1 && NULL == n2) return true;

    if (n1 && n2 && n1->key == n2->key)
        return isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    return false;
}
bool isSymmetric(Node* root) {
    return isMirror(root, root);
}

/**
 * Root to leaf paths sum
 * https://www.youtube.com/watch?v=bNgfwQspr10
 * @return
 */
void rootToLeafPathSum(Node* n, int number, int &sum) {
    if (NULL == n) return;

    number = number * 10 + n->key;

    if (NULL == n->left && NULL == n->right) {
        sum += number;
        return;
    }

    rootToLeafPathSum(n->left, number, sum);
    rootToLeafPathSum(n->right, number, sum);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);
    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);

//      1
//    /   \
//   2     3
//  / \
// 4   5

    Node* root2 = new Node(1);
    root2->left = new Node(root2, 2);
    root2->right = new Node(root2, 3);
    root2->left->left = new Node(root2->left, 4);
    root2->left->right = new Node(root2->left, 5);
    root2->right->left = new Node(root2->right, 6);
    root2->right->right = new Node(root2->right, 7);

//      1
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7

    Node* root3 = new Node(1);
    root3->left = new Node(root3, 2);
    root3->right = new Node(root3, 2);
    root3->left->left = new Node(root3->left, 3);
    root3->left->right = new Node(root3->left, 4);
    root3->right->left = new Node(root3->right, 4);
    root3->right->right = new Node(root3->right, 3);

//      1
//    /   \
//   2     2
//  / \   / \
// 3   4 4   3


    int depth = findDepth(root);
    cout << "isPerfectBinaryTree() : " << isPerfectBinaryTree(root, 0, depth) << endl;
    depth = findDepth(root2);
    cout << "isPerfectBinaryTree() : " << isPerfectBinaryTree(root2, 0, depth) << endl;

    cout << "isSymmetric() : " << isSymmetric(root) << endl;
    cout << "isSymmetric() : " << isSymmetric(root3) << endl;

    int sum = 0;
    rootToLeafPathSum(root, 0, sum);
    cout << "rootToLeafPathSum() : " << sum << endl;
    sum = 0;
    rootToLeafPathSum(root2, 0, sum);
    cout << "rootToLeafPathSum() : " << sum << endl;
}
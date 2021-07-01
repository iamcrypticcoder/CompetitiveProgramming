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
    Node *left = NULL, *right = NULL;

    Node() {}
    Node(int key) {
        this->key = key;
    }
};

Node *root;
int keyCount;

void bstInit() {
    root = NULL;
    keyCount = 0;
}
Node* inorderSuccessor(Node* node) {
    Node* current = node;
    while(NULL != current->left) current = current->left;
    return current;
}
Node* insertNode(Node* node, int key) {
    if (NULL == node) return new Node(key);
    if (key < node->key) node->left = insertNode(node->left, key);
    else node->right = insertNode(node->right, key);
    return node;
}
Node* searchNode(Node* node, int key) {
    if (NULL == node || key == node->key) return node;
    if (key < node->key) searchNode(node->left, key);
    else searchNode(node->right, key);
    return node;
}
Node* deleteNode(Node* node, int key) {
    if (NULL == node) return node;
    if (key < node->key) node->left = deleteNode(node->left, key);
    else if (key > node->key) node->right = deleteNode(node->right, key);
    else {
        // Node with one child or no child
        if (NULL == node->left) return node->right;
        if (NULL == node->right) return node->left;

        Node* temp = inorderSuccessor(node->right);
        node->key = temp->key;

        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}
void preOrderTraverse(Node* node) {
    if (NULL == node) return;
    cout << node->key << " ";
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}
void inOrderTraverse(Node* node) {
    if (NULL == node) return;
    inOrderTraverse(node->left);
    cout << node->key << " ";
    inOrderTraverse(node->right);
}

// Complexity: O(lg N)
void insertKey(int key) {
    root = insertNode(root, key);
}

// Complexity: O(lg N)
bool searchKey(int key) {
    return (NULL != searchNode(root, key));
}

// Complexity: O(lg N)
void deleteKey(int key) {
    deleteNode(root, key);
}

/**
 * Given a BST node, get height of the node.
 * Here height of leaf node considered as 0
 */
int getHeight(Node* n) {
    if (NULL == n) return -1;
    return max(getHeight(n->left), getHeight(n->right)) + 1;
}

/**
 * Given a BST root node, check is the BST balanced or not
 * Complexity - O(n lg n)
 * @return
 */
bool isBalanced(Node* root) {
    if (NULL == root) return true;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    if (abs(lh - rh) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}


int checkHeight(Node* n) {
    if (n == NULL) return -1;

    int lh = checkHeight(n->left);
    if (lh == INT_MIN) return INT_MIN;

    int rh = checkHeight(n->right);
    if (rh == INT_MIN) return INT_MIN;

    int diff = abs(lh - rh);
    if (diff > 1) return INT_MIN;
    else return max(lh, rh) + 1;
}

/**
 * Given a BST root node, check is the BST balanced or not
 * Complexity - O(n)
 * @return
 */
bool isBalancedOptimized(Node* n) {
    return checkHeight(n) != INT_MIN;
}


int main() {
    int keys1[] = {50, 25, 75, 13, 37, 100, 7, 125};
    int keys2[] = {50, 25, 75, 13, 37, 100, 7};
    int cnt1 = sizeof keys1 / sizeof (int);
    int cnt2 = sizeof keys2 / sizeof (int);

    bstInit();
    for (int i = 0; i < cnt1; i++)
        insertKey(keys1[i]);

    cout << "isBalanced() : " << isBalanced(root) << endl;
    cout << "isBalancedOptimized() : " << isBalancedOptimized(root) << endl;

    bstInit();
    for (int i = 0; i < cnt2; i++)
        insertKey(keys2[i]);

    cout << "isBalanced() : " << isBalanced(root) << endl;
    cout << "isBalancedOptimized() : " << isBalancedOptimized(root) << endl;
}


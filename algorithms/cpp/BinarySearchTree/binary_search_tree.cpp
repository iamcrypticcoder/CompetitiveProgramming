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
Node* minValueNode(Node* n) {
    if (NULL == n) return NULL;

    while(NULL != n && NULL != n->left)
        n = n->left;
    return n;
}
int minNodeValue(Node* n) {
    if (NULL == n) return INT_MIN;
    while (NULL != n && NULL != n->left)
        n = n->left;
    return n->key;
}
int maxNodeValue(Node* n) {
    if (NULL == n) return INT_MAX;
    while (NULL != n && NULL != n->right)
        n = n->right;
    return n->key;
}

Node* insertNode(Node* n, int key) {
    if (NULL == n) return new Node(key);
    if (key < n->key) n->left = insertNode(n->left, key);
    else n->right = insertNode(n->right, key);
    return n;
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

        Node* temp = minValueNode(node->right);
        node->key = temp->key;

        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}
Node* insertNodeIterative(Node* root, int key) {
    Node* ptr = root;
    Node* parent = NULL;
    while (NULL != ptr) {
        parent = ptr;
        if (key > ptr->key) {
            ptr = ptr->right;
        }
        else if (key < ptr->key) {
            ptr = ptr->left;
        }
    }
    Node* newNode = new Node(key);
    if (NULL == parent) return newNode;
    if (key < parent->key) parent->left = newNode;
    else parent->right = newNode;
    return root;
}

bool searchNodeIterative(Node* root, int key) {
    Node* ptr = root;
    while (NULL != ptr) {
        if (key < ptr->key) ptr = ptr->left;
        else if (key > ptr->key) ptr = ptr->right;
        else return true;
    }
    return false;
}

Node* deleteNodeIterative(Node* node, int key) {
    return NULL;
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
    keyCount++;
}

// Complexity: O(lg N)
bool searchKey(int key) {
    return (NULL != searchNode(root, key));
}

// Complexity: O(lg N)
void deleteKey(int key) {
    deleteNode(root, key);
    keyCount--;
}

/**
 * Check weather a binary tree is BST or not
 * Call with root and INT_MIN and INT_MAX
 * @param node
 * @param minValue
 * @param maxValue
 */
bool isBST(Node* node, int minValue, int maxValue) {
    if (NULL == node) return true;
    if (node->key < minValue || node->key > maxValue) return false;
    return (isBST(node->left, minValue, node->key-1) && isBST(node->right, node->key+1, maxValue));
}

/**
 * Given a sorted array with unique integers make BST with minimal height
 * @return
 */
Node* createMinimalBST(int arr[], int left, int right) {
    if (left > right) return NULL;
    int mid = (left + right) / 2;
    Node* n = new Node(arr[mid]);
    n->left = createMinimalBST(arr, left, mid-1);
    n->right = createMinimalBST(arr, mid+1, right);
    return n;
}
Node* createMinimalBST(int arr[], int cnt) {
    return createMinimalBST(arr, 0, cnt-1);
}

int main() {
    int keys[] = {8, 3, 10, 1, 6, 4, 7, 14, 13};
    int cnt = sizeof keys / sizeof (int);
    cout << cnt << endl;

    bstInit();
    cout << "Insert:" << endl;
    for (int i = 0; i < cnt; i++) {
        root = insertNodeIterative(root, keys[i]);
    }

    cout << "" << minNodeValue(root) << endl;
    cout << "" << maxNodeValue(root) << endl;

    preOrderTraverse(root);
    cout << endl;
    inOrderTraverse(root);
    cout << endl;

    cout << "Search:" << endl;
    for (int i = 0; i < cnt; i++) {
        cout << searchKey(keys[i]) << " ";
    }
    cout << endl;

    cout << "Delete:" << endl;
    deleteKey(6);
    deleteKey(14);

    preOrderTraverse(root);
    cout << endl;
    inOrderTraverse(root);
    cout << endl;

    cout << "Search:" << endl;
    for (int i = 0; i < cnt; i++) {
        cout << searchKey(keys[i]) << " ";
    }
    cout << endl;

    cout << "Create minimal BST:" << endl;
    int arr[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    cnt = sizeof arr / sizeof (int);
    Node* root = createMinimalBST(arr, cnt);
    preOrderTraverse(root);
    cout << endl;

    return 0;
}


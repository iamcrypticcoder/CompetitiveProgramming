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

void inOrderRecursive(Node* n, vector<Node*> &list) {
    if (NULL == n) return;
    inOrderRecursive(n->left, list);
    list.push_back(n);
    inOrderRecursive(n->right, list);
}
vector<Node*> inOrderRecursive(Node *root) {
    vector<Node*> list;
    inOrderRecursive(root, list);
    return list;
}

Node* inorderSuccessor(Node* n) {
    if (NULL == n) return NULL;

    if (NULL != n->right) {
        Node* t = n->right;
        while (NULL != t->left) t = t->left;
        return t;
    } else {
        Node* t1 = n;
        Node* t2 = n->parent;
        while (NULL != t2 && t1 != t2->left) {
            t1 = t2;
            t2 = t2->parent;
        }
        return t2;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);
    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);
    root->right->left = new Node(root->right, 6);
    root->right->right = new Node(root->right, 7);

//      1
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7

    vector<Node*> list;

    list = inOrderRecursive(root);
    cout << "Inorder Recursive: ";
    for (int i = 0; i < list.size(); i++)
        cout << list[i]->key << " ";
    cout << endl;

    cout << "Inorder Successors: ";
    for (int i = 0; i < list.size(); i++) {
        Node *s = inorderSuccessor(list[i]);
        if (NULL == s) cout << "NULL";
        else cout << s->key << " ";
    }
    cout << endl;
}
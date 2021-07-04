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

vector<int> preOrderIterative(Node *root) {
    vector<int> list;
    stack<Node*> stack;
    stack.push(root);
    while (!stack.empty()) {
        Node* n = stack.top();
        stack.pop();
        list.push_back(n->key);
        if (NULL != n->right) stack.push(n->right);
        if (NULL != n->left) stack.push(n->left);
    }
    return list;
}

vector<int> inOrderIterative(Node *root) {
    vector<int> list;
    stack<Node*> stack;
    Node *current = root;
    stack.push(current);
    while (NULL != current->left) {
        current = current->left;
        stack.push(current);
    }

    while (!stack.empty()) {
        current = stack.top();
        stack.pop();
        list.push_back(current->key);
        if (NULL != current->right) {
            current = current->right;
            stack.push(current);
            while (NULL != current->left) {
                current = current->left;
                stack.push(current);
            }
        }
    }
    return list;
}

vector<int> postOrderIterative1(Node* root) {
    vector<int> list;
    stack<Node*> s1, s2;

    s1.push(root);
    while (!s1.empty()) {
        Node* n = s1.top(); s1.pop();
        s2.push(n);
        if (NULL != n->left) s1.push(n->left);
        if (NULL != n->right) s1.push(n->right);
    }

    while (!s2.empty()) {
        list.push_back(s2.top()->key);
        s2.pop();
    }
    return list;
}

// Using only one stack
// https://www.geeksforgeeks.org/iterative-postorder-traversal-set-3/?ref=rp
vector<int> postOrderIterative2(Node* root) {
    vector<int> list;
    stack<pair<Node*, int>> stack;

    stack.push(make_pair(root, 0));

    while (!stack.empty()) {
        pair<Node*, int> p = stack.top(); stack.pop();
        if (p.second == 2) {
            list.push_back(p.first->key);
            continue;
        }
        stack.push(make_pair(p.first, p.second+1));
        if (p.second == 0) {
            if (NULL != p.first->left) stack.push(make_pair(p.first->left, 0));
        } else {
            if (NULL != p.first->right) stack.push(make_pair(p.first->right, 0));
        }
    }
    return list;
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);
    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);
    root->right->left = new Node(root->right, 6);
    root->right->right = new Node(root->right, 7);

    vector<int> list;

    list = preOrderRecursive(root);
    cout << "Preorder Recursive: ";
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    list = preOrderIterative(root);
    cout << "Preorder Iterative: ";
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    list = inOrderRecursive(root);
    cout << "Inorder Recursive: ";
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    list = inOrderIterative(root);
    cout << "Inorder Iterative: ";
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    list = postOrderRecursive(root);
    cout << "Postorder Recursive: ";
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    list = postOrderIterative1(root);
    cout << "Postorder Iterative 1: ";
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    list = postOrderIterative2(root);
    cout << "Postorder Iterative 2: ";
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;
}
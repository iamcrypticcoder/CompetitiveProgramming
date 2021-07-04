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

bool findPath(Node* node, int n, vector<int> &path) {
    if (NULL == node) return false;
    path.push_back(node->key);
    if (node->key == n) return true;
    if (NULL != node->left && findPath(node->left, n, path)) return true;
    if (NULL != node->right && findPath(node->right, n, path)) return true;
    path.pop_back();
    return false;
}

int findLCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;
    if (findPath(root, n1, path1) == false) {
        cout << "n1 isn't exist in tree" << endl;
        return -1;
    }
    if (findPath(root, n2, path2) == false) {
        cout << "n2 isn't exist in tree" << endl;
        return -1;
    }

    int len = min(path1.size(), path2.size());
    int i = 0;
    while (i < len) {
        if (path1[i] != path2[i]) break;
        i++;
    }
    return path1[i-1];
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);
    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);
    root->right->left = new Node(root->right, 6);
    root->right->right = new Node(root->right, 7);

    cout << "findLCA() : " << findLCA(root, 4, 5) << endl;
    cout << "findLCA() : " << findLCA(root, 4, 6) << endl;
    cout << "findLCA() : " << findLCA(root, 3, 7) << endl;
    cout << "findLCA() : " << findLCA(root, 5, 5) << endl;
    cout << "findLCA() : " << findLCA(root, 1, 1) << endl;

}
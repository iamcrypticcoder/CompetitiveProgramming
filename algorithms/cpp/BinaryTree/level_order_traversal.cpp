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

/**
 * Given a binary tree, return level order traversal list
 * Complexity: O(n)
 */
vector<int> levelOrderTraverse(Node* root) {
    vector<int> list;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* n = q.front(); q.pop();
        list.push_back(n->key);
        if (NULL != n->left) q.push(n->left);
        if (NULL != n->right) q.push(n->right);
    }
    return list;
}

/**
 * Given a binary tree, return reverse level order traversal list
 * @return
 */
vector<int> reverseLevelOrderTraversal(Node* root) {
    vector<int> ret;
    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while (!q.empty()) {
        Node* n = q.front(); q.pop();
        s.push(n);

        if (NULL != n->right) q.push(n->right);
        if (NULL != n->left) q.push(n->left);
    }

    while (!s.empty()) {
        ret.push_back(s.top()->key);
        s.pop();
    }
    return ret;
}

int treeHeight(Node* n) {
    if (NULL == n) return 0;
    return max(treeHeight(n->left), treeHeight(n->right)) + 1;
}

vector<vector<int>> levelOrderList(Node* root) {
    if (NULL == root)
        return vector<vector<int>>();

    vector<vector<int>> ret;
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        if (size > 0) {
            ret.push_back(vector<int>());
        }
        while (size > 0) {
            Node* n = Q.front(); Q.pop();
            ret[ret.size()-1].push_back(n->key);
            if (n->left) Q.push(n->left);
            if (n->right) Q.push(n->right);
            size--;
        }
    }
    return ret;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);
    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);
    root->right->left = new Node(root->right, 6);
    root->right->right = new Node(root->right, 7);

    cout << "Level Order Traversal: " << endl;
    vector<int> list = levelOrderTraverse(root);
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    cout << "Reverse Level Order Traversal: " << endl;
    list = reverseLevelOrderTraversal(root);
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    cout << "Level Order List: " << endl;
    vector<vector<int>> levels = levelOrderList(root);
    for (int i = 0; i < levels.size(); i++) {
        cout << "Level " << i << ": ";
        for (int j = 0; j < levels[i].size(); j++)
            cout << levels[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

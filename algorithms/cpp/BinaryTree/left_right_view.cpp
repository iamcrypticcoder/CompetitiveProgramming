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

void findLeftView(Node* n, int level, int &maxLevel, vector<int> &list) {
    if (NULL == n) return;

    if (level > maxLevel) {
        list.push_back(n->key);
        maxLevel = level;
    }

    findLeftView(n->left, level+1, maxLevel, list);
    findLeftView(n->right, level+1, maxLevel, list);
}

vector<int> generateLeftView(Node* root) {
    vector<int> ret;
    int maxLevel = 0;
    findLeftView(root, 1, maxLevel, ret);
    return ret;
}


void findRightView(Node* n, int level, int &maxLevel, vector<int> &list) {
    if (NULL == n) return;

    if (level > maxLevel) {
        list.push_back(n->key);
        maxLevel = level;
    }

    findRightView(n->right, level+1, maxLevel, list);
    findRightView(n->left, level+1, maxLevel, list);
}

vector<int> generateRightView(Node* root) {
    vector<int> ret;
    int maxLevel = 0;
    findRightView(root, 1, maxLevel, ret);
    return ret;
}

// http://www.geeksforgeeks.org/print-left-view-binary-tree/
// https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
int main() {
    Node* root = new Node(1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);
    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);
    root->right->left = new Node(root->right, 6);
    root->right->right = new Node(root->right, 7);

    cout << "Left View : ";
    vector<int> list = generateLeftView(root);
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;

    cout << "Right View : ";
    list = generateRightView(root);
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;
}

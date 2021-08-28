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
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    Node *left = NULL, *right = NULL;

    Node() {}
    Node(int key) {
        this->key = key;
    }
};

vector<int> inorderTraverse(Node* root) {
    vector<int> ret;
    stack<Node*> st;
    Node *ptr = root;
    st.push(ptr);
    while (NULL != ptr->left) {
        ptr = ptr->left;
        st.push(ptr);
    }

    while (!st.empty()) {
        ptr = st.top(); st.pop();
        ret.push_back(ptr->key);
        if (NULL != ptr->right) {
            ptr = ptr->right;
            st.push(ptr);
            while (NULL != ptr->left) {
                ptr = ptr->left;
                st.push(ptr);
            }
        }
    }
    return ret;
}

void binaryTreeToBST(Node* root) {
    // Inorder traverse
    vector<int> list = inorderTraverse(root);
    // Sort the list
    sort(list.begin(), list.end());

    // Again inorder traverse and modify node val from list
    int index = 0;
    stack<Node*> st;
    Node *ptr = root;
    st.push(ptr);
    while (NULL != ptr->left) {
        ptr = ptr->left;
        st.push(ptr);
    }

    while (!st.empty()) {
        ptr = st.top(); st.pop();
        ptr->key = list[index++];
        if (NULL != ptr->right) {
            ptr = ptr->right;
            st.push(ptr);
            while (NULL != ptr->left) {
                ptr = ptr->left;
                st.push(ptr);
            }
        }
    }
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(4);

    binaryTreeToBST(root);
    vector<int> list = inorderTraverse(root);
    for (int x : list) cout << x << " ";
    cout << endl;

    return 0;
}


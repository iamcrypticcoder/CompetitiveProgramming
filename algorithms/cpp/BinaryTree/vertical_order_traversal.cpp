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

void printVector(string title, vector<int> v) {
    cout << title << ": ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

void traverseRecursive(Node* n, int& mostLeft, int& mostRight, int vValue,
                       unordered_map<int, vector<int>>& map) {
    if (NULL == n) return;

    mostLeft = min(mostLeft, vValue);
    mostRight = max(mostRight, vValue);

    if (map.find(vValue) == map.end())
        map[vValue] = vector<int>();
    map[vValue].push_back(n->key);

    if (n->left)
        traverseRecursive(n->left, mostLeft, mostRight, vValue-1, map);
    if (n->right)
        traverseRecursive(n->right, mostLeft, mostRight, vValue+1, map);
}

vector<vector<int>> verticalOrder(Node* n) {
    if (NULL == n) return vector<vector<int>>();

    unordered_map<int, vector<int>> map;
    int mostLeft = 0, mostRight = 0;
    traverseRecursive(n, mostLeft, mostRight, 0, map);
    cout << mostLeft << " " << mostRight << endl;

    vector<vector<int>> ret;
    for (int i = mostLeft; i <= mostRight; i++)
        ret.push_back(map[i]);
    return ret;
}


int main() {

    string arr[] = {"abc", "efgf", "sdfsdfsdfsdfdsf"};
    for (string s : arr) {

    }
    int c = sizeof(arr) / sizeof (arr[0]);
    cout << c << endl;

    Node* root = new Node(NULL, 1);
    root->left = new Node(root, 2);
    root->right = new Node(root, 3);

    root->left->left = new Node(root->left, 4);
    root->left->right = new Node(root->left, 5);

    root->right->left = new Node(root->right, 6);
    root->right->right = new Node(root->right, 7);

    root->right->right->left = new Node(root->left->left, 8);
    root->right->right->right = new Node(root->left->left, 9);


    /**
    *            1
    *         /     \
    *        2       3
    *      /   \   /   \
    *     4    5  6    7
    *                 / \
    *                8   9
    *
    */

    vector<vector<int>> ret = verticalOrder(root);
    for (auto v : ret)
        printVector("", v);
}

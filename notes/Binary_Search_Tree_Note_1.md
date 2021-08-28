
## BASIC PROBLEMS

1. BST Basic Implementation : Insert, Search, Delete
2. BST Iterative Insert, Search, Delete
3. BST Find Min/Max Value
4. BST Check Validity
5. Sorted Array to Balanced BST
6. Normal BST to Balanced BST
7. BST Count nodes of a given range
8. Binary Tree to BST
9. BST Find LCA
10. BST K'th Largest Value
11. BST Floor and Ceil of given key


### 1. BST Implementation : Insert, Search, Delete:
BST basic implementation with insert, search and delete functionalities:

**Code:**
```cpp
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
```

### 2. BST Iterative Insert, Search, Delete:

Implement iterative version of insert, search and delete.

**Code:**
```cpp
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
   // TODO
}

```

### 3. BST Find Min/Max Value: 

Example is given below:
```
       8
	   /   \
	  3     10
	 / \      \
  1   6      14
      / \    /
     4   7  13

Min Value = 1
Max Value = 14
```

**Code:**
```cpp
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
```


### 4. BST Check validity:

Check weather a binary tree is BST or not.

**Code:**
```cpp
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
```


### 5. Sorted Array to Balanced BST:

Given a sorted array with unique integers make BST with minimal height
```
Input: [1, 3, 4, 6, 7, 8, 10, 13, 14]
Output:
        7
	   /    \
	  3      10
	 / \    /  \
  1   4  8    13
          \      \
           6     14
```

**Code:**
```cpp
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
```

### 6. Normal BST to Balanced BST:

Example is given below:
```
          4                             4
        /   \                        /    \
       3     5                      2      6
      /       \         --->      /  \    /  \
     2         6                 1    3  5    7 
    /           \
   1             7 
```

**Solution:** 
```
1. Inorder traverse the given BST to get sorted list.
2. Make a balanced BST from the sorted list.
```

### 7. BST Count nodes of a given range:

Example is given below:
```
        7
	   /    \
	  3      10
	 / \    /  \
  1   4  8    13
          \      \
           6      14
 
Input: [1, 14]  Output: 9
Input: [0, 0]   Output: 0
Input: [15, 15] Output: 0
Input: [5, 10]  Output: 4
Input: [4, 4]   Output: 1
```

**Code:**
```cpp
int countNodes(Node* n, int low, int high) {
    if (NULL == n) return 0;

    // If low and high are equal and matched to low and high
    if (low == high && n->key == low)
        return 1;

    // If node val is less then the given range
    if (n->key < low)
        return countNodes(n->right, low, high);

    // If node val is more then the given range
    if (n->key > high)
        return countNodes(n->left, low, high);

    // If node val lies inside range
    return 1 + countNodes(n->left, low, high) +
               countNodes(n->right, low, high);
}
```

### 8. Binary Tree to BST:
Example is given below:
```
Input:
       10
	   /    \
	  2      7
	 / \ 
  8   4
 
Output:
       8
	   /    \
	  4      10
	 / \ 
  2   7
```

**Code:**
```cpp
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
```

### 9. BST Find LCA:
Example is given below:
```
Input:
        8
	   /    \
	  4      10
	 / \ 
  2   7

n1 = 2
n2 = 7

Output: 4

```

**Code:**
```cpp
/**
 * Given a BST (with all unique value), Finds LCA of key n1 and n2
 */
Node* findLCA(Node* n, int n1, int n2) {
    if (NULL == n) return n;
    if (n1 < n->key && n2 < n->key) return findLCA(n->left, n1, n2);
    else if (n1 > n->key && n2 > n->key) return findLCA(n->right, n1, n2);
    return n;
}
```

### 10. BST K'th Largest Value:
Example is given below:
```
        7
	   /    \
	  3      10
	 / \    /  \
  1   4  8    13
          \     \
           6     14

K = 1, Output: 14
K = 5, Output: 7
```

**Code:**
```cpp
/**
 * Given a BST (with all unique value), find k-th largest value
 * Idea : Reverse in-order traversal because we know inorder traversal gives us sorted array
 * @return
 */
int kthLargest(Node* n, int k, int &cnt) {
    if (NULL == n) return INT_MIN;

    int r = kthLargest(n->right, k, cnt);
    if (r != INT_MIN) return r;

    cnt++;
    if (k == cnt) return n->key;

    int l = kthLargest(n->left, k, cnt);
    if (l != INT_MIN) return l;

    return INT_MIN;
}
```


### 11. BST Floor and Ceil of given key:
Example is given below:
```
          8
        /   \    
      4      12
    /  \    /  \
   2    6  10   14

Key: 11  Floor: 10  Ceil: 12
Key: 1   Floor: -1  Ceil: 2
Key: 6   Floor: 6   Ceil: 6
Key: 15  Floor: 14  Ceil: -1

```

**Code:**
```cpp
int floor(Node* n, int key) {
    if (NULL == n) return -1;
    if (key == n->key) return key;

    if (key < n->key)
        return floor(n->left, key);

    int f = floor(n->right, key);
    return (f != -1 && f <= key) ? f : n->key;
}

int ceil(Node* n, int key) {
    if (NULL == n) return -1;
    if (n->key == key) return key;

    if (key > n->key)
        return ceil(n->right, key);

    int c = ceil(n->left, key);
    return (c != -1 && c >= key) ? c : n->key;
}
```




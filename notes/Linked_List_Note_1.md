## BASIC PROBLEMS

1. Singly Linked List
2. Circular Singly Linked List
3. Reverse Singly Linked List
4. Reverse in Group 
5. Rotate Linked List
6. Find Middle Element
7. Nth Node from End
8. Detect/Remove Cycle Loop
9. Palindrome Check
10. Merge Sorted Linked List
11. Merge Sort Singly Linked List
11. Doubly Linked List in CPP (DLL)



### 1. Singly Linked List:

**Code:**

```cpp
struct Node {
    int val;
    Node *next = NULL;
    Node();
    Node(int a) : val(a) {}
};

Node *head, *tail;
int size;

void initLinkedList() {
    head = tail = NULL;
    size = 0;
}

// Complexity: O(1)
bool insertAtFirst(int val) {
    Node* newNode = new Node(val);
    if (NULL == head) {
        head = tail = newNode;
        size++;
        return true;
    }
    newNode->next = head;
    head = newNode;
    size++;
    return true;
}

// Complexity: O(1)
bool insertAtLast(int val) {
    Node* newNode = new Node(val);
    if (NULL == head) {
        head = tail = newNode;
        size++;
        return true;
    }
    tail->next = newNode;
    tail = tail->next;
    size++;
    return true;
}

// Complexity: O(pos)
// Position starts from 0
bool insertAtPos(int val, int pos) {
    Node* newNode = new Node(val);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        size++;
        return true;
    }

    pos = pos - 1;
    Node *ptr = head;
    while(pos > 0 && NULL != ptr) {
        ptr = ptr->next;
        pos--;
    }
    Node *tmp = ptr->next;
    ptr->next = newNode;
    newNode->next = tmp;
    size++;
    return true;
}

// Complexity: O(size)
bool removeAtLast() {
    if (NULL == head) return false;
    if (head == tail) {
        head = tail = NULL;
        size = 0;
        return true;
    }

    Node *ptr = head;
    while (NULL != ptr->next && NULL != ptr->next->next) {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    tail = ptr;
    size--;
    return true;
}

// Complexity: O(size)
// Position starts from 0
bool removeAtPos(int pos) {
    if (pos > size-1) return false;
    if (pos == 0) {
        head = head->next;
        size--;
        return true;
    }

    pos = pos - 1;
    Node *ptr = head;
    while (pos > 0 && NULL != ptr) {
        ptr = ptr->next;
        pos--;
    }
    ptr->next = ptr->next->next;
    size--;
    return true;
}

vector<int> asVector() {
    vector<int> ret;
    Node *ptr = head;
    while (NULL != ptr) {
        ret.push_back(ptr->val);
        ptr = ptr->next;
    }
    return ret;
}

int main() {
    int arr[] = {10, 5, 6, 9, 20, 13, 1, 25};
    int cnt = sizeof(arr) / sizeof(arr[0]);

    initLinkedList();
    for (int i = 0; i < cnt; i++) {
        insertAtLast(arr[i]);
    }
    insertAtFirst(100);
    insertAtPos(200, 2);

    vector<int> v = asVector();
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    removeAtFirst();
    removeAtLast();
    removeAtPos(2);

    v = asVector();
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    
    return 0;
}
```



### 2. Circular Singly Linked List:

**Code:**

```cpp
struct Node {
    int val;
    Node *next = NULL;
    Node();
    Node(int a) : val(a) {}
};

Node *last;
int size;

void initLinkedList() {
    last = NULL;
    size = 0;
}

// Complexity: O(1)
void insertAtFirst(int val) {
    if (NULL == last) {
        last = new Node(val);
        last->next = last;
        return;
    }
    Node *newNode = new Node(val);
    Node *next = last->next;
    last->next = newNode;
    newNode->next = next;
}

// Complexity: O(1)
void insertAtLast(int val) {
    if (NULL == last) {
        last = new Node(val);
        last->next = last;
        return;
    }
    Node *newNode = new Node(val);
    Node *next = last->next;
    last->next = newNode;
    newNode->next = next;
    last = newNode;
}

int main() {
    int arr[] = {10, 5, 6, 9, 20, 13, 1, 25};
    int cnt = sizeof(arr) / sizeof(arr[0]);

    initLinkedList();
    for (int i = 0; i < cnt; i++) {
        insertAtFirst(arr[i]);
    }

    vector<int> v = asVector();
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}
```



### 3. Reverse Singly Linked List:

```cpp
struct Node {
    int val;
    Node *next = NULL;
    Node();
    Node(int a) : val(a) {}
};

Node* makeLinkedList(vector<int> v) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < v.size(); i++) {
        int val = v[i];
        if (NULL == head) {
            head = new Node(val);
            tail = head;
            continue;
        }
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}

// Return reversed linked list head
// Complexity : O(n)
Node* reverseLinkedList(Node* head) {
    if (NULL == head) return NULL;
    Node *ptr = head;
    Node *prev = NULL, *next = NULL;
    while (NULL != ptr) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
    return head;
}

Node* reverseLinkedListRecur(Node* prev, Node* ptr) {
    Node *next = ptr->next;
    ptr->next = prev;
    if (NULL == next) {
        return ptr;
    }
    return reverseLinkedListRecur(ptr, next);
}
```



### 4. Reverse in Group:

Given a singly linked list, you have to reverse every `k` items. 

**Example:**

```
Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, K = 3
Output: 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 8 -> 7
```

**Code:**

```cpp
struct Node {
    int val;
    Node *next = NULL;
    Node();
    Node(int a) : val(a) {}
};

// Time: O(n)
Node* reverseInGroupsRecur(Node* head, int k) {
    if (NULL == head) return NULL;
    Node *ptr = head, *prev = NULL, *next = NULL;
    int count = 0;
    while (NULL != ptr && count < k) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
        count++;
    }

    if (NULL != next)
        head->next = reverseInGroupsRecur(next, k);

    return prev;
}

// Time: O(n)
// Space: O(n)
Node* reverseInGroups_UsingStack(Node* head, int k)  {
    if (NULL == head) return NULL;
    Node *nHead = NULL;
    Node *nTail = NULL;
    Node *ptr = head;
    stack<Node*> s;

    while (NULL != ptr) {
        int count = 0;
        while (NULL != ptr && count < k) {
            s.push(ptr);
            ptr = ptr->next;
            count++;
        }

        while (!s.empty()) {
            if (NULL == nHead) {
                nHead = nTail = s.top();
                s.pop();
            } else {
                nTail->next = s.top();
                nTail = nTail->next;
                s.pop();
            }
        }
    }
    nTail->next = NULL;
    return nHead;
}

// Time: O(n)
Node* reverseInGroups(Node* head, int k) {
    if (NULL == head) return NULL;
    Node *ret = NULL;
    Node *tHead = NULL, *tTail = NULL, *prevGroupTail = NULL;
    Node *ptr = head;
    int c;

    while (NULL != ptr) {
        c = 0;
        tHead = tTail = NULL;
        while (NULL != ptr && c < k) {
            c++;
            if (NULL == tHead) {
                tHead = tTail = ptr;
            } else {
                tTail->next = ptr;
                tTail = tTail->next;
            }
            ptr = ptr->next;
        }

        tTail->next = NULL;
        Node *revHead = reverseLinkedList(tHead);
        // For first group
        if (NULL == prevGroupTail) {
            ret = revHead;
        } else {
            // Link to previous group
            prevGroupTail->next = revHead;
        }
        prevGroupTail = tHead;
    }
    return ret;
}

int main() {
    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{0});
    inputs.push_back(vector<int>{0, 1});
    inputs.push_back(vector<int>{0, 1, 2});
    inputs.push_back(vector<int>{0, 1, 2, 3});
    inputs.push_back(vector<int>{0, 1, 2, 3, 4, 5});
    inputs.push_back(vector<int>{0, 1, 2, 3, 4, 5, 6, 7});

    for (int tc = 0; tc < inputs.size(); tc++) {
        vector<int> v;
        Node *head;

        cout << "reverseInGroupsRecur() : ";
        head = makeLinkedList(inputs[tc]);
        Node *rev = reverseInGroupsRecur(head, 2);
        v = toVector(rev);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;

        cout << "reverseLinkedListRecur() : ";
        head = makeLinkedList(inputs[tc]);
        rev = reverseInGroups_UsingStack(head, 2);
        v = toVector(rev);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;

        cout << "reverseInGroups() : ";
        head = makeLinkedList(inputs[tc]);
        rev = reverseInGroups(head, 2);
        v = toVector(rev);
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl << endl;
    }

    return 0;
}
```



### 5. Rotate Linked List:

Rotate the linked list counter clockwise by `K` nodes. 

**Code:**

```cpp
struct Node {
    int val;
    Node *next = NULL;
    Node();
    Node(int a) : val(a) {}
};

// Time: O(n)
void rorateLinkedList(Node **headRef, int k) {
    if (NULL == *headRef || k == 0) return;
    Node *head = *headRef;
    Node *ptr = head;
    int c = 1;
    while (c < k && NULL != ptr) {
        ptr = ptr->next;
        c++;
    }
    // If reach at end node or beyond, no need to rotate
    if (NULL == ptr || NULL == ptr->next) return;

    Node *next = ptr->next;
    ptr->next = NULL;
    ptr = next;
    while (NULL != ptr->next)
        ptr = ptr->next;
    ptr->next = head;
    *headRef = next;
}
```



### 6. Find Middle Element:

```
Input: { 1 }
Output: 1
Input: { 1, 2 }
Output: 2
Input: { 1 2 3 }
Output: 2
Input: { 1 2 3 4 }
Output: 3
```

**Code:**

```cpp
// Complexity: O(n)
int getMiddle_Method_1(Node *head) {
    if (NULL == head) return INT_MIN;
    Node *ptr = head;
    int c = 0;
    while (NULL != ptr) {
        c++;
        ptr = ptr->next;
    }
    c = c / 2;
    ptr = head;
    while (c > 0) {
        c--;
        ptr = ptr->next;
    }
    return ptr->val;
}

// Complexity: O(n)
int getMiddle_Method_2(Node *head) {
    if (NULL == head) return INT_MIN;
    Node *slow = head, *fast = head;
    while (NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

int getMiddle_Method_3(Node *head) {
    if (NULL == head) return INT_MIN;
    Node *mid = head, *ptr = head;
    int count = 0;

    while (NULL != ptr) {
        if (count & 1) mid = mid->next;
        count++;
        ptr = ptr->next;
    }
    return mid->val;
}
```



### 7. Nth Node from End:

**Code:**

```cpp
// Time: O(n)
Node* nthNodeFromEnd(Node *head, int n) {
    if (n == 0) return NULL;

    Node* slow = head;
    Node *fast = head;
    while (n > 0 && NULL != fast) {
        fast = fast->next;
        n--;
    }

    if (NULL == fast) {
        if (n == 0) return head;
        if (n  > 0) return NULL;
    }

    while (NULL != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```



### 8. Detect/Remove Cycle Loop:

**Code:**

```cpp
// Time complexity : O(n)
// Auxiliary Space : O(n)
bool detectLoop_UsingHash(Node *head) {
    unordered_set<Node*> s;
    Node *ptr = head;
    while (NULL != ptr) {
        if (s.find(ptr) != s.end())
            return true;
        s.insert(ptr);
        ptr = ptr->next;
    }
    return false;
}

// Time complexity : O(n)
// Auxiliary Space : O(1)
bool detectLoop_UsingFloyd(Node *head) {
    Node *slow = head, *fast = head;
    while (NULL != slow && NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// Time complexity : O(n)
// Auxiliary Space : O(n)
bool detectLoop_UsingTempNode(Node *head) {
    Node *ptr = head;
    Node *dummy = new Node(INT_MIN);
    while (NULL != ptr) {
        if (ptr->next == dummy)
            return true;

        Node *next = ptr->next;
        ptr->next = dummy;
        ptr = next;
    }
    return false;
}
```



### 9. Palindrome Check:

Given a linked list, check if it is a palindrome in terms of values

**Example:**

```
Input: 0
Output: True
Input: 0 -> 0
Output: True
Input: 0 -> 1 -> 2 -> 1 -> 0
Output: True
Input: 0 -> 1 -> 2 -> 2 -> 1 -> 0
Output: True
Input: 1 -> 2 -> 3 -> 3 -> 2 -> 1
Output: True
```

**Code:**

```cpp
bool isPalindrome(Node* head) {
    Node *slow = head;
    Node *fast = head;
    stack<int> stack;

    while (NULL != fast && NULL != fast->next) {
        stack.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    // Has odd number of element
    if (NULL != fast) {
        slow = slow->next;
    }

    while (NULL != slow) {
        int top = stack.top();
        stack.pop();

        if (top != slow->val) {
            return false;
        }
        slow = slow->next;
    }
    return true;
}
```



### 10. Merge Sorted Linked List:

**Code:**

```cpp
Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = new Node(INT_MIN);
    Node* tail = head;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while (NULL != ptr1 && NULL != ptr2) {
        if (ptr1->val < ptr2->val) {
            tail->next = ptr1;
            ptr1 = ptr1->next;
        } else {
            tail->next = ptr2;
            ptr2 = ptr2->next;
        }
        tail = tail->next;
    }
    if (NULL != ptr1) tail->next = ptr1;
    if (NULL != ptr2) tail->next = ptr2;
    return head->next;
}
```



### 11. Merge Sort Singly Linked List:

**Code:**

```cpp
void splitHalf(Node *head, Node **left, Node **right) {
    Node *slow = head, *fast = head->next;

    while (NULL != fast && NULL != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = new Node(INT_MIN);
    Node* tail = head;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while (NULL != ptr1 && NULL != ptr2) {
        if (ptr1->val < ptr2->val) {
            tail->next = ptr1;
            ptr1 = ptr1->next;
        } else {
            tail->next = ptr2;
            ptr2 = ptr2->next;
        }
        tail = tail->next;
    }
    if (NULL != ptr1) tail->next = ptr1;
    if (NULL != ptr2) tail->next = ptr2;
    return head->next;
}

void mergeSort(Node **headRef) {
    Node *head = *headRef;
    Node *left, *right;

    if (NULL == head || NULL == head->next)
        return;

    splitHalf(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = mergeLinkedList(left, right);
}
```



### 12. Doubly Linked List (DLL) in CPP:

In C++ STL library, `list<typedef>` represents a doubly linked list.

Link : https://en.cppreference.com/w/cpp/container/list




## BASIC PROBLEMS

1. Maximum/Minimum Depth
2. Pre Order Traversal
3. In Order Traversal
4. Post Order Traversal
5. Level Order Traversal
6. Reverse Level Order Traversal
7. Level Order Spiral Traversal
8. Boundary Nodes Traversal
9. Same Tree
10. Symmetric Tree
11. Path Sum
12. Maximum Path Sum
13. Check Balanced Binary Tree
14. Lowest Common Ancestor
15. Longest Path from Root to Leaf
16. Longest Path from Leaf to Leaf


### 1. Maximum/Minimum Depth:

Find maximum and minimum depth of binary tree. Example:

```
    3
   / \
  9  20
    /  \
   15   7
   
Maximum Depth = 3
Minimum Depth = 2  


    1
   / \
  1   2
  
Maximum Depth = 2
Minimum Depth = 2    
```  

**Code:**

```java
public int maxDepth(TreeNode root) {
    if (null == root) return 0;
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
}

public int minDepth(TreeNode root) {
    if (null == root) return 0;
    if (null == root.left && null == root.right) return 1;
    int min = Integer.MAX_VALUE;
    if (null != root.left) min = Math.min(min, minDepth(root.left));
    if (null != root.right) min = Math.min(min, minDepth(root.right));
    return 1 + min;
}

public class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
}
```

### 2. Pre Order Traversal:

**Recursive:**

```java
public void preOrderRecursive(TreeNode node, List<Integer> list) {
	if(null == node) return;
	list.add(node.val);
	preOrderRecursive(node.left, list);
	preOrderRecursive(node.right, list);
}
```

**Iterative:**

```java
public List<Integer> preOrderIterative(TreeNode root) {
    List<Integer> list = new ArrayList<>();
    Stack<TreeNode> nodeStack = new Stack<>();

    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode node = nodeStack.pop();
        list.add(node.val);

        if (null != node.right) nodeStack.push(node.right);
        if (null != node.left) nodeStack.push(node.left);
    }
    return list;
}
```

### 3. In Order Traversal:

**Recursive:**

```java
public void inOrderRecursive(TreeNode node, List<Integer> list) {
    if(null == node) return;
    inOrderRecursive(node.left, list);
    list.add(node.val);
    inOrderRecursive(node.right, list);
}
```

**Iterative:**

```java
public List<Integer> inOrderIterative(TreeNode root) {
    List<Integer> list = new ArrayList<>();
    Stack<TreeNode> nodeStack = new Stack<>();
    TreeNode current = root;
    nodeStack.push(current);
    while (null != current.left) {
        current = current.left;
        nodeStack.push(current);
    }

    while(!nodeStack.empty()) {
        current = nodeStack.pop();
        list.add(current.val);

        if (null != current.right) {
            current = current.right;
            nodeStack.push(current);
            while (null != current.left) {
                current = current.left;
                nodeStack.push(current);
            }
        }
    }

    return list;
}
```


### 4. Post Order Traversal:

**Recursive:**

```java
public void postOrderRecursive(TreeNode node, List<Integer> list) {
    if (null == node) return;
    postOrderRecursive(node.left, list);
    postOrderRecursive(node.right, list);
    list.add(node.val);
}
```

**Iterative:**

```java
// Using two stacks
public List<Integer> postOrderIterative1(TreeNode root) {
    List<Integer> ret = new ArrayList<>();
    Stack<TreeNode> s1 = new Stack<>();
    Stack<TreeNode> s2 = new Stack<>();

    s1.push(root);
    while (!s1.isEmpty()) {
        TreeNode node = s1.pop();
        s2.push(node);
        if (null != node.left) s1.push(node.left);
        if (null != node.right) s1.push(node.right);
    }

    while (!s2.isEmpty())
        ret.add(s2.pop().val);

    return ret;
}

// Using only one stack
// https://www.geeksforgeeks.org/iterative-postorder-traversal-set-3/?ref=rp
public List<Integer> postOrderIterative2(TreeNode root) {
    List<Integer> ret = new ArrayList<>();
    Stack<Pair> stack = new Stack<>();

    stack.push(new Pair(root, 0));

    while (!stack.isEmpty()) {
        Pair p = stack.pop();
        if (p.code == 2) {
            ret.add(p.node.val);
            continue;
        }
        stack.push(new Pair(p.node, p.code+1));
        if (p.code == 0) {
            if (null != p.node.left) stack.push(new Pair(p.node.left, 0));
        } else {
            if (null != p.node.right) stack.push(new Pair(p.node.right, 0));
        }
    }

    return ret;
}

static class Pair {
    TreeNode node;
    int code;  // 0 -  Left element, 1 -  Right element, 2 -  Node element
    public Pair(TreeNode node, int code) {
        this.node = node;
        this.code = code;
    }
}
```


### 5. Level Order Traversal:

**Example:**

```
    3
   / \
  9  20
    /  \
   15   7
   
Level 1 Nodes: 3
Level 2 Nodes: 9 20
Level 3 Nodes: 15 7
```

**Code:**

```java
public class LevelOrderTraverseDemo {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.right = new TreeNode(3);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        List<List<Integer>> levelNodes = new ArrayList<>();
        levelOrderRecur(root, levelNodes, 0);
        for (int i = 0; i < levelNodes.size(); i++)
            System.out.println(levelNodes.get(i).toString());

        List<Integer> list = levelOrderUsingQueue(root);
        System.out.println(list.toString());
    }
    
    // Complexity: O(n)
    static List<Integer> levelOrderUsingQueue(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        Queue<TreeNode> Q = new LinkedList<>();

        if (null != root) Q.add(root);

        while (!Q.isEmpty()) {
            TreeNode node = Q.poll();
            ret.add(node.val);

            if (null != node.left) Q.add(node.left);
            if (null != node.right) Q.add(node.right);
        }
        return ret;
    }
    
    static void levelOrderRecur(TreeNode node, List<List<Integer>> levelNodes, int level) {
        if (null == node) return;

        // If new level discovered
        if (level > levelNodes.size()-1) {
            List<Integer> list = new ArrayList<>();
            list.add(node.val);
            levelNodes.add(list);
        } else {
            levelNodes.get(level).add(node.val);
        }

        levelOrderRecur(node.left, levelNodes, level + 1);
        levelOrderRecur(node.right, levelNodes, level + 1);
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```

### 6. Reverse Level Order Traversal:

**Main Idea:** Need to print nodes from most depth nodes reversely. But we have to start our node traversal from root. So while traversing from root, put nodes into a stack one after one. Then print the stack. Stack will give you nodes in reverse order.

**Code:**

```java
// Reverse level order traversal
// Complexity: Time - O(n), Space - O(n)
static List<Integer> reverseLevelOrder(TreeNode root) {
    List<Integer> ret = new ArrayList<>();
    Queue<TreeNode> Q = new LinkedList<>();
    Stack<TreeNode> S = new Stack<>();

    if (null != root) Q.add(root);
    while (!Q.isEmpty()) {
        TreeNode node = Q.poll();
        S.push(node);

        if (null != node.left) Q.add(node.left);
        if (null != node.right) Q.add(node.right);
    }

    while (!S.isEmpty()) {
        TreeNode node = S.pop();
        ret.add(node.val);
    }

    return ret;
}
```

### 7. Level Order Spiral Traversal:

One level from left to right, next level traverse from right to left and so on.

**Example:**

```
             1
           /   \
	  2     3
	 / \   / \
	4   5 6   7
	  
Spiral Level Order Traversal: 1 3 2 4 5 6 7
Or: 1 2 3 7 6 5 4
```


**Code:**

```java
public class LevelOrderSpiralTraverse {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        System.out.println(levelOrderSpiralTraverse(root));
    }

    static List<Integer> levelOrderSpiralTraverse(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();

        if (null != root) s1.push(root);

        // If any one of the stacks aren't empty
        while (!s1.isEmpty() || !s2.isEmpty()) {
            while (!s1.isEmpty()) {
                TreeNode node = s1.pop();
                ret.add(node.val);
                if (null != node.left) s2.push(node.left);
                if (null != node.right) s2.push(node.right);
            }
            while (!s2.isEmpty()) {
                TreeNode node = s2.pop();
                ret.add(node.val);
                if (null != node.right) s1.push(node.right);
                if (null != node.left) s1.push(node.left);
            }
        }
        return ret;
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```

### 8. Boundary Nodes Traversal:

Example:

```

          1
       /     \
      2       3
    /   \   /   \
   4    5  6    7
  / \    \
 8   9   10

Result: 1 2 4 8 9 10 6 7 3

```

**Code:**

```java
public class BoundaryNodesDemo {
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);

        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        root.left.left.left = new TreeNode(8);
        root.left.left.right = new TreeNode(9);

        root.left.right.left = new TreeNode(10);

        List<Integer> list = findBoundaryNodes(root);
        System.out.println(list.toString());
    }

    static List<Integer> findBoundaryNodes(TreeNode root) {
        // Find all left side nodes
        List<Integer> list = new ArrayList<>();

        findLeftNodes(root, list);
        // Last element will be added again. That's why deleting it
        if (list.size() > 0) list.remove(list.size()-1);

        // Find leaf nodes
        findLeafNodes(root, list);
        // Last element will be added again. That's why deleting it
        if (list.size() > 0) list.remove(list.size()-1);

        // Find all right nodes
        findRightNodes(root, list);
        // Last element is actually root element. That's why deleting it
        if (list.size() > 0) list.remove(list.size()-1);

        return list;
    }

    static void findLeftNodes(TreeNode node, List<Integer> list) {
        if (null == node) return;
        list.add(node.val);
        if (null != node.left)
            findLeftNodes(node.left, list);
        else if (null != node.right)
            findLeftNodes(node, list);
    }

    static void findLeafNodes(TreeNode node, List<Integer> list) {
        if (null == node) return;
        if (null == node.left && null == node.right)
            list.add(node.val);
        findLeafNodes(node.left, list);
        findLeafNodes(node.right, list);
    }

    static void findRightNodes(TreeNode node, List<Integer> list) {
        if (null == node) return;
        if (null != node.right)
            findRightNodes(node.right, list);
        else if (null != node.left)
            findRightNodes(node.left, list);
        list.add(node.val);
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```

### 9. Same Tree:

**Example:**

```
      1         1
     / \       / \
    2   3     2   3

   Output: true
   

      1         1
     /           \
    2             2

   Output: false
```


**Code:**

```java
public class SameTreeCheckDemo {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println(isSameTree(root, root));

        TreeNode p = new TreeNode(1);
        p.left = new TreeNode(2);
        TreeNode q = new TreeNode(1);
        q.right = new TreeNode(2);
        System.out.println(isSameTree(p, q));
    }

    static boolean isSameTree(TreeNode p, TreeNode q) {
        if (null == p && null == q) return true;

        if (null == p && null != q) return false;
        if (null != p && null == q) return false;
        if (p.val != q.val) return false;

        boolean ret = isSameTree(p.left, q.left);
        ret = ret && isSameTree(p.right, q.right);

        return ret;
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```

### 10. Symmetric Tree:


A symmetric tree is look like same when shown in mirror. 

**Example:**

```
    1
   / \
  2   2
 / \ / \
3  4 4  3

Output: true

    1
   / \
  2   2
   \   \
   3    3
   
Output: false
```

**Code:**

```
public boolean isSymmetric(TreeNode root) {
    if (null == root) return true;
    
    Queue<TreeNode> left = new LinkedList<>();
    Queue<TreeNode> right = new LinkedList<>();
    
    left.add(root.left);
    right.add(root.right);
    while (!left.isEmpty() && !right.isEmpty()) {
        TreeNode l = left.poll();
        TreeNode r = right.poll();
        
        if (null != l && null != r) {
            if (l.val != r.val) return false;
            left.add(l.left);
            left.add(l.right);
            right.add(r.right);
            right.add(r.left);
        }
        else if (null != l && null == r) 
            return false;
        else if (null == l && null != r)
            return false;
        
    }
    
    if (!left.isEmpty() || !right.isEmpty()) return false;
    
    return true;
}
```


### 11. Path Sum:

Given a sum `S`, find a path from root to leaf such such that sum of each node value equals to `S`. 

**Example:**

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

S = 22

Output: true
Path: 5 + 4 + 11 + 2 = 22
```


**Code:**

```java

public static void main(String... args) {
    solve(root, 0, S);
}

static boolean solve(TreeNode node, int curSum, int sum) {
    if (null == root) return false;
    boolean isLeaf = (null == node.left && null == node.right);
    if (isLeaf && curSum + node.val == sum) return true;
    
    if (null != node.left) 
        if (solve(node.left, curSum + node.val, sum)) return true;
    if (null != node.right) 
        if (solve(node.right, curSum + node.val, sum)) return true;
    return false;
}
```

### 12. Maximum Path Sum:

**Example:**

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

5 + 4 + 11 + 7 = 27
5 + 4 + 11 + 2 = 22
5 + 8 + 13 = 26
5 + 8 + 4 + 1 = 18

Answer: 5 + 4 + 11 + 7 = 27
```

**Code:**

```java
public class MaximumPathSum {

    static int maxSum;
    static List<Integer> resultPath;

    public static void main(String[] args) {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(4);
        root.right = new TreeNode(8);

        root.left.left = new TreeNode(11);
        root.left.left.left = new TreeNode(7);
        root.left.left.right = new TreeNode(2);

        root.right.left = new TreeNode(13);
        root.right.right = new TreeNode(4);
        root.right.right.right = new TreeNode(1);

        List<Integer> curPath = new ArrayList<>();
        resultPath = new ArrayList<>();
        maxSum = Integer.MIN_VALUE;
        maximumSumPath(root, 0, curPath);

        System.out.println("Max Path Sum = " + maxSum);
        System.out.println(resultPath.toString());
    }

    static void maximumSumPath(TreeNode node, int curSum, List<Integer> curPath) {
        if (null == node) return;
        if (isLeaf(node)) {
            if (curSum + node.val > maxSum) {
                maxSum = curSum + node.val;
                resultPath.clear();
                resultPath.addAll(curPath);
                resultPath.add(node.val);
            }
            return;
        }

        curPath.add(node.val);
        maximumSumPath(node.left, curSum + node.val, curPath);
        maximumSumPath(node.right, curSum + node.val, curPath);
        curPath.remove(curPath.size()-1);
    }

    static boolean isLeaf(TreeNode node) {
        return (null == node.left && null == node.right);
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```


### 13. Check Balanced Binary Tree:

In a balanced binary depth of left subtree and right subtree has no difference greater than 1.

**Example:**

```
    3
   / \
  9  20
    /  \
   15   7
   
Output: true


       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
 
Output: true 
```

**Code:**

```java
public boolean isBalanced(TreeNode root) {
    if (null == root) return true;
    boolean ret = true;
    if (null != root.left) ret = ret && isBalanced(root.left);
    if (null != root.right) ret = ret && isBalanced(root.right);
    
    if (false == ret) return false;
    
    int l = (null == root.left ? 0 : depth(root.left));
    int r = (null == root.right ? 0 : depth(root.right));
    return (Math.abs(l - r) <= 1);
}

public int depth(TreeNode node) {
    if (null == node) return 0;
    return 1 + Math.max(depth(node.left), depth(node.right));
}
```

### 14. Lowest Common Ancestor:

**Code:**

```java
static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    List<TreeNode> path1 = new ArrayList<>();
    List<TreeNode> path2 = new ArrayList<>();
    
    System.out.println(p.val + " " + q.val);
    
    findPath(root, p, path1);
    findPath(root, q, path2);
    
    System.out.println(path1.size());
    System.out.println(path2.size());
    
    int i, len = Math.min(path1.size(), path2.size());
    for (i = 0; i < len; i++) {
        if (path1.get(i) != path2.get(i)) break;
    }
    return path1.get(i-1);
}
    
static boolean findPath(TreeNode root, TreeNode node, List<TreeNode> list) {
    if (null == root) return false;
    list.add(root);
    if (root == node) return true;
    if (null != root.left && findPath(root.left, node, list)) return true;
    if (null != root.right && findPath(root.right, node, list)) return true;
    list.remove(list.size()-1);
    return false;
}
```

### 15. Longest Path from Root to Leaf:

**Example:**

```
   			1
   		  /  \
   		 2    3
   		/
   	  3
   	   \
   	    4 

Output: 1 2 3 4
```

**Main Idea 1:** We can find node with maximum level which is the answer node leaf. To keep path using a list `curPath` in which element will be added when going down and removed when returning back. When we get a max level node save the `curPath` into `resultPath`.

**Main Idea 2:** Alternatively we can think longest path will be max of longest path of left subtree and right subtree plus parent node.

**Code:**

```java
public class LongestPathFromRoot {

    static int maxLevel;
    static List<Integer> resultPath;

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(3);
        root.left.left.right = new TreeNode(4);

        List<Integer> curPath = new ArrayList<>();
        resultPath = new ArrayList<>();
        maxLevel = Integer.MIN_VALUE;
        longestPath(root, curPath, 1);

        System.out.println("Max Path Length = " + maxLevel);
        System.out.println(resultPath.toString());

        List<Integer> ret = longestPath(root);
        System.out.println(ret.toString());
    }

    // Complexity: O(n)
    // Implementation using external static variable
    static void longestPath(TreeNode node, List<Integer> curPath, int level) {
        if (null == node) return;
        if (isLeaf(node)) {
            if (level > maxLevel) {
                maxLevel = level;
                resultPath.clear();
                resultPath.addAll(curPath);
                resultPath.add(node.val);
            }
            return;
        }

        curPath.add(node.val);
        longestPath(node.left, curPath, level + 1);
        longestPath(node.right, curPath, level + 1);
        curPath.remove(curPath.size()-1);
    }

    // No external variable used
    static List<Integer> longestPath(TreeNode node) {
        if (null == node) return new ArrayList<>();
        List<Integer> leftPath = longestPath(node.left);
        List<Integer> rightPath = longestPath(node.right);

        if (leftPath.size() >= rightPath.size()) leftPath.add(0, node.val);
        else rightPath.add(0, node.val);

        return leftPath.size() >= rightPath.size() ? leftPath : rightPath;
    }

    static boolean isLeaf(TreeNode node) {
        return (null == node.left && null == node.right);
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```


### 16. Longest Path from Leaf to Leaf:

**Example:**

Given a binary tree find longest path from one leaf to another leaf. the path shouldn't always go via root node. It could be any path from one node to another node.

```
			1
		/      \
	  2         3
	 / \
	4   5
   /   /
  8   10
      /
     11
     
Answer: 6
Path: 8 4 2 5 10 11
```

**Code:**

```java
public class LongestLeafToLeaf {

    static int result;
    static List<Integer> resultList;
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.left.left.left = new TreeNode(8);

        root.left.right.left = new TreeNode(10);
        root.left.right.left.left = new TreeNode(11);

        longestLeafToLeaf(root);
        System.out.println(result);
    }

    static int longestLeafToLeaf(TreeNode node) {
        if (null == node) return 0;
        int maxL = longestLeafToLeaf(node.left);
        int maxR = longestLeafToLeaf(node.right);
        if (maxL + maxR + 1 > result) result = maxL + maxR + 1;
        return Math.max(maxL, maxR) + 1;
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```

If the path is also required to print:

```java
static List<Integer> longestLeafToLeaf(TreeNode node) {
    if (null == node) return new ArrayList<>();
    List<Integer> listL = longestLeafToLeaf(node.left);
    List<Integer> listR = longestLeafToLeaf(node.right);

    if (listL.size() + listR.size() + 1 > resultList.size()) {
        resultList.clear();
        resultList.addAll(listL);
        resultList.add(node.val);
        List<Integer> rev = new ArrayList<>(listR);
        Collections.reverse(rev);
        resultList.addAll(rev);
    }

    if (listL.size() >= listR.size()) {
        listL.add(node.val);
    } else {
        listR.add(node.val);
    }

    return listL.size() >= listR.size() ? listL : listR;
}
```

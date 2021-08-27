
## SUM RELATED PROBLEMS

1. Sum of only left/right leaves
2. Maximum Path Sum between two leaves
3. Sum of heights of all individual nodes
4. Maximum level sum


### 3. Sum of only left/right leaves:

**Example:**

```
       9
     /   \
    8     6
   / \   /
  5   2 1
  
Sum of left leaves = 5 + 1 = 6
Sum of right leaves = 2
```

**Code:**

```java
public class SumOfLeftLeaves {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(9);
        root.left = new TreeNode(8);
        root.right = new TreeNode(6);

        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(2);

        root.right.left = new TreeNode(1);

        System.out.println("Left Leaves Sum = " + sumOfLeftLeaves(root, false));
        System.out.println("Right Leaves Sum = " + sumOfRightLeaves(root, false));
    }

    static int sumOfLeftLeaves(TreeNode node, boolean isLeftNode) {
        if (null == node) return 0;
        if (isLeaf(node) && isLeftNode) return node.val;

        int l = sumOfLeftLeaves(node.left, true);
        int r = sumOfLeftLeaves(node.right, false);
        return l + r;
    }

    static int sumOfRightLeaves(TreeNode node, boolean isRightNode) {
        if (null == node) return 0;
        if (isLeaf(node) && isRightNode) return node.val;

        int l = sumOfRightLeaves(node.left, false);
        int r = sumOfRightLeaves(node.right, true);
        return l + r;
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


### 4. Maximum Path Sum between two leaves:


**Example:**

```
         1
       /   \
      2     3
     / \
    4   5
   /   /
  8   10
      /
     11
     
Output: 8 + 4 + 2 + 5 + 10 + 11 = 40
```

**Code:**

```java
public class MaxPathSumBetweenLeaves {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        root.left.left.left = new TreeNode(8);

        root.left.right.left = new TreeNode(10);
        root.left.right.left.left = new TreeNode(11);

        System.out.println(maxPathSumBetweenLeaves(root));
    }

    static int maxPathSumBetweenLeaves(TreeNode root) {
        Result result = new Result();
        result.val = Integer.MIN_VALUE;
        recur(root, result);
        return result.val;
    }

    static int recur(TreeNode node, Result result) {
        if (null == node) return 0;
        if (isLeaf(node)) return node.val;
        int maxL = (null == node.left ? Integer.MIN_VALUE : recur(node.left, result));
        int maxR = (null == node.right ? Integer.MIN_VALUE : recur(node.right, result));
        if (maxL + maxR + node.val > result.val)
            result.val = maxL + maxR + node.val;
        return Math.max(maxL, maxR) + node.val;
    }

    static boolean isLeaf(TreeNode node) {
        return (null == node.left && null == node.right);
    }

    static class Result {
        int val = 0;
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```

### 5. Sum of heights of all individual nodes:

**Example:**

```
           1
	  /  \
	 2    3
	/ \
       4   5

Height of node 1 = 3
Height of node 2 = 2
Height of node 3 = 1
Height of node 4 and 5 = 1

Sum of heights = 3 + 2 + 1 + 1 + 1 = 8
```

**Code:**

```java
public class SumOfHeightsNodes {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.println(sumOfHeightsIndividualNodes(root));
    }

    static int sumOfHeightsIndividualNodes(TreeNode root) {
        Result result = new Result(0);
        solve(root, result);
        return result.val;
    }

    static int solve(TreeNode node, Result result) {
        if (null == node) return 0;
        if (isLeaf(node)) {
            result.val += 1;
            return 1;
        }

        int maxL = solve(node.left, result);
        int maxR = solve(node.right, result);
        int ret = Math.max(maxL, maxR) + 1;
        result.val += ret;

        return ret;
    }

    static boolean isLeaf(TreeNode node) {
        return (null == node.left && null == node.right);
    }
    
    static class Result {
        int val;
        Result(int val) {
            this.val = val;
        }
    }

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```

### 6. Maximum level sum:

**Example:**

```
                      4
                    /   \
                   2    -5
                  / \    /\
                -1   3 -2  6
                
                  Output: 6
 
Sum of level 1 nodes = 4
Sum of level 2 nodes = -3
Sum of level 3 nodes = 6
```

**Code:**

```java
public class MaximumLevelSum {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(-5);

        root.left.left = new TreeNode(-1);
        root.left.right = new TreeNode(3);

        root.right.left = new TreeNode(-2);
        root.right.right = new TreeNode(6);

        System.out.println(maximumLevelSum(root));
    }

    static int maximumLevelSum(TreeNode root) {
        int ret = Integer.MIN_VALUE;

        Queue<TreeNode> Q = new LinkedList<>();
        if (null != root) Q.add(root);

        while (!Q.isEmpty()) {
            // This is node count of current level
            int nodeCount = Q.size();
            int levelSum = 0;
            while (nodeCount > 0) {
                TreeNode node = Q.poll();
                levelSum += node.val;
                if (null != node.left) Q.add(node.left);
                if (null != node.right) Q.add(node.right);
                nodeCount--;
            }
            ret = Math.max(ret, levelSum);
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

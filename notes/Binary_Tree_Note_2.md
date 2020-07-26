## SUM RELATED PROBLEMS

1. Maximum Path Sum
2. Sum of Longest Path from Root to Leaf
3. Sum of only left/right leaves
4. Maximum Path Sum between two leaves
5. Sum of heights of all individual nodes
6. Maximum level sum


### 1. Maximum Path Sum

**Example:**

Find a path from root to leaf such that sum of node values will be maximum.

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

        System.out.println(maximumSumPath(root));
        
        List<Integer> path = new ArrayList<>();
        System.out.println(maximumSumPath(root, path));
        System.out.println(path.toString());
    }

    // This version don't use external variable
    // Also produce path values
    static int maximumSumPath(TreeNode node, List<Integer> path) {
        if (null == node) {
            return 0;
        }
        if (isLeaf(node)) {
            path.add(node.val);
            return node.val;
        }

        List<Integer> listL = new ArrayList<>();
        List<Integer> listR = new ArrayList<>();
        int maxL = (null == node.left ? Integer.MIN_VALUE : maximumSumPath(node.left, listL));
        int maxR = (null == node.right ? Integer.MIN_VALUE : maximumSumPath(node.right, listR));
        if (maxL >= maxR) {
            path.addAll(listL);
        } else {
            path.addAll(listR);
        }
        path.add(node.val);

        return Math.max(maxL, maxR) + node.val;
    }
    
    // This version don't use external variable, only calculates max value
    static int maximumSumPath(TreeNode node) {
        if (null == node) return 0;
        if (isLeaf(node)) return node.val;

        int maxL = (null == node.left ? Integer.MIN_VALUE : maximumSumPath(node.left));
        int maxR = (null == node.right ? Integer.MIN_VALUE : maximumSumPath(node.right));

        return Math.max(maxL, maxR) + node.val;
    }

    // This version of recursion using external variable
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


### 2. Sum of Longest Path from Root to Leaf:

Example:

```
   			1
   		  /  \
   		 2    3
   		/
   	  3
   	   \
   	    4 

Output: 1 2 3 4

Sum = 10
```

Code:

```java
public class SumOfLongestPath {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        root.left.left = new TreeNode(3);
        root.left.left.right = new TreeNode(4);

        List<Integer> ret = longestPath(root);
        System.out.println(ret.toString());
        int sum = 0;
        for (int x : ret) sum += x;
        System.out.println("Sum = " + sum);
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

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }
}
```

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
		/      \
	  2         3
	 / \
	4   5
   /   /
  8   10
      /
     11
     
Output: 8 + 4 + 2 + 5 + 10 + 11 = 40

```

**Code:**

```
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

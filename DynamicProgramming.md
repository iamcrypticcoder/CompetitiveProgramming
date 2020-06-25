# Dynamic Programming Problems

### 1. Maximum Subarray 1D

Given a 1D array, find subarray with maximum sum. Example:

```
Given 1D Array: 2 -3 5 1 -1 5 -1

Maximum Subarray: 5 1 -1 5

Sum: 10
```

DP with O(n^2) time complexity:

```java
static long maxSubArr1D(long[] A) {
    long ret = Long.MIN_VALUE;
    int L = A.length;

    long[] S = new long[L+1];         // Index from 1 for easy impl
    S[1] = A[0];
    for (int i = 2; i <= L; i++)
        S[i] = S[i-1] + A[i-1];

    for (int i = 1; i <= L; i++) {
        for (int j = i; j <= L; j++) {
            ret = Math.max(ret, S[j] - S[i-1]);
        }
    }
    return ret;
}
```

DP with Kadane O(n) time complexity:

```java
static long maxSubArr1D_Kadane(long[] A) {
    long maxSum = A[0];
    long curMax = A[0];

    for (int i = 1; i < A.length; i++) {
        curMax = Math.max(A[i], curMax + A[i]);
        maxSum = Math.max(maxSum, curMax);
    }
    return maxSum;
}
```

Test:

```java
public static void main(String[] args) {
    long arr1[] = new long[] {2, -3, 5, 1, -1, 5, -1};
    long arr2[] = new long[] {-2, -3, -5, -1, -1, -5, -1};
    long arr3[] = new long[] {-2, -3, -5, -1, -1, -5, -1, 0};

    System.out.println(maxSubArr1D(arr1));
    System.out.println(maxSubArr1D_Kadane(arr1));
    System.out.println(maxSubArr1D(arr2));
    System.out.println(maxSubArr1D_Kadane(arr2));
    System.out.println(maxSubArr1D(arr3));
    System.out.println(maxSubArr1D_Kadane(arr3));
}
```

### 2. Maximum Subarray 2D

Given a 2D array, find subarray with maximum sum. Example:

```
Given 2D Array: 0 -2 -7  0
                9  2 -6  2
               -4  1 -4  1
               -1  8  0 -2

Maximum Subarray:  9 2
                  -4 1
                  -1 8

Sum: 15
```

DP with O(n^4) time complexity:

```java
static long maxSubArr2D(long[][] A) {
    int R = A.length;
    int C = A[0].length;

    long[][] S = new long[R+1][C+1];        // Index from 1 for easy impl
    long ret = Long.MIN_VALUE;

    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) {
        S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i-1][j-1];
    }

    for (int i = 1; i <= R; i++) for (int j = 1; j <= C ; j++)
        for (int k = i; k <= R; k++) for (int l = j; l <= C ; l++) {
            long sum = S[k][l] - S[i-1][l] - S[k][j-1] + S[i-1][j-1];
            ret = Math.max(ret, sum);
        }

    return ret;
}
```


DP with Kadane O(n^3) time complexity:

```java
static long maxSubArr2D_Kadane(long[][] A) {
    int R = A.length;
    int C = A[0].length;

    long[][] S = new long[R+1][C+1];        // Index from 1 for easy impl
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            S[i][j] = S[i-1][j] + A[i-1][j-1];

    long maxSum = A[0][0];
    for (int i = 1; i <= R; i++) {
        for (int j = i; j <= R; j++) {
            long curMax = S[j][1] - S[i-1][1];
            for (int k = 2; k <= C; k++) {
                long val = S[j][k] - S[i-1][k];
                curMax = Math.max(val, curMax + val);
                maxSum = Math.max(maxSum, curMax);
            }
        }
    }
    return maxSum;
}
```

Test:

```java
public static void main(String[] args) {
    long[][] arr1 = new long[][] {
            { 0, -2, -7,  0},
            { 9,  2, -6,  2},
            {-4,  1, -4,  1},
            {-1,  8,  0, -2}
    };

    System.out.println(maxSubArr2D(arr1));
    System.out.println(maxSubArr2D_Kadane(arr1));
}
```

### 3. Longest Increasing Subsequence (LIS)

Given a 1D array, find the length of the longest subsequence of a given array such that all elements of the subsequence are sorted in increasing order. Example:

```
Given 1D Array: 10 22 9 33 21 50 41 60 80

LIS: 10 22 33 41 60 80

LIS Length: 6
```


Let `L[i]` denotes LIS length up to index `i`. Then recursive formula for `L[i]`:

```
L[i] = 1 + max(L[j]) where 0 < j < i and A[j] < A[i]
L[0] = 1 (Base Case)

Example: 10 22 9 33

L[3] = 1 + max(L[2], L[1], L[0]) = 3
L[2] = 1 + max(L[1], L[0]) = 1
L[1] = 1 + max(L[0]) = 2
L[0] = 1
```

Top-Down Solution:

```java
public class LIS {

    static int[] A, L, P;
    static int lisLen;
    static int lastIndex;

    public static void main(String[] args) {
        A = new int[] {10, 22, 9, 33, 21, 50, 41, 60, 80};
        System.out.println("LIS Len = " + lis());
        printSolution();

        A = new int[] {1, 2, 3, 4, 2, 1};
        System.out.println("LIS Len = " + lis());
        printSolution();
    }

    static void printSolution() {
        System.out.println("L = " + Arrays.toString(L));
        System.out.println("P = " + Arrays.toString(P));
        System.out.println("lastIndex = " + lastIndex);
        List<Integer> path = new ArrayList<>();
        makePath(lastIndex, path);
        System.out.println("Path = " + path.toString() + "\n");
    }

    static int lis() {
        L = new int[A.length];
        P = new int[A.length];
        Arrays.fill(L, -1);
        Arrays.fill(P, -1);
        lisLen = -1;
        lastIndex = -1;

        for (int i = A.length-1; i >= 0; i--) {
            int tmp = topDownLis(i);
            if (tmp > lisLen) {
                lisLen = topDownLis(i);
                lastIndex = i;
            }
        }
        return lisLen;
    }

    static int topDownLis(int i) {
        if (L[i] != -1) return L[i];
        if (i == 0) {
            L[0] = 1;
            return 1;
        }

        int maxLen = 0;
        for (int j = i-1; j >= 0; j--) {
            if (A[j] >= A[i]) continue;
            int tmp = topDownLis(j);
            if (tmp > maxLen) {
                maxLen = tmp;
                P[i] = j;
            }
        }

        L[i] = 1 + maxLen;
        return L[i];
    }

    static void makePath(int i, List<Integer> path) {
        if (P[i] != -1) makePath(P[i], path);
        path.add(i);
    }
}
```

Bottom-Up Solution:

```java
static int bottomUpLis() {
    L = new int[A.length];
    P = new int[A.length];
    L[0] = 1;
    P[0] = -1;
    lisLen = -1;
    lastIndex = -1;

    for (int i = 1; i < A.length; i++) {
        int maxLen = 0;
        for (int j = i-1; j >= 0; j--) {
            if (A[j] < A[i] && L[j] > maxLen) {
                maxLen = L[j];
                P[i] = j;
            }
        }
        L[i] = 1 + maxLen;
        if (L[i]  > lisLen) {
            lisLen = L[i];
            lastIndex = i;
        }
    }
    return lisLen;
}
```

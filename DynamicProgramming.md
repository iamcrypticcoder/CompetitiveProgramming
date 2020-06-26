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

### 4. Longest Common Subsequence (LCS)

Given 2 strings X and Y find longest common subsequence between them. Example:

```
X = "AGGTAB"
Y = "GXTXAYB"

LCS = "GTAB"
```

Let length of string `X` is `m` and length of `Y` is `n`. Let `LCS(X[0..m-1], Y[0..n-1])` be the length of LCS of given string X and Y. Then recursive formula for `LCS(X[0..m-1], Y[0..n-1])` will be:

```
LCS(X[0..m-1], Y[0..n-1]) = 1 + LCS(X[1..m-1], Y[1..n-1])                                  if X[0] == Y[0]
                          = max { LCS(X[0..m-1], Y[1..n-1]), LCS(X[1..m-1], Y[0..n-1]) }   if X[0] != Y[0]

Example:    X = "AGGTAB"    Y = "GXTXAYB"

Here, X[0] != Y[0]. So

LCS("AGGTAB", "GXTXAYB") = max { LCS("GGTAB", "GXTXAYB"), LCS("AGGTAB", "XTXAYB") } 
```

To build LCS string we have to keep indexes where character matched between two strings. To do this 2D `track` table is maintained ususally. Track table for example strings are following:

|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| 0 |   | G | X | T | X | A | Y | B |
| 1 | A |   |   |   |   |   |   |   |
| 2 | G |   |   |   |   |   |   |   |
| 3 | G | 1 | 3 |   |   |   |   |   |
| 4 | T |   |   | 1 | 3 |   |   |   |
| 5 | A |   |   |   |   | 1 | 3 |   |
| 6 | B |   |   |   |   |   |   | 1 |


Top-Down and Bottom-Up Solution:

```java
public class LCS {
    public static void main(String[] args) {
        System.out.println(findLCS("AGGTAB", "GXTXAYB"));
        System.out.println(findLCS("", ""));
        System.out.println(findLCS("A", "A"));
        System.out.println(findLCS("AB", "BA"));
    }

    static String s1, s2;
    static int[][] c;       // c[] is used to calculate the length.
    static int[][] track;   // b[] is used to trace the LCS. '3' denotes left, '2' denotes up, '1' denotes upper-left

    static String findLCS(String str1, String str2) {
        s1 = str1;
        s2 = str2;
        int m = s1.length(), n = s2.length();

        c = new int[m+1][n+1];
        track = new int[m+1][n+1];
        for (int[] row : c) Arrays.fill(row, -1);
        for (int[] row : track) Arrays.fill(row, -1);

        //topDownLCS(m, n);
        bottomUpLCS(m, n);
        StringBuilder sb = new StringBuilder();
        makeLCSString(m, n, sb);
        return sb.toString();
    }

    static void makeLCSString(int m, int n, StringBuilder sb) {
        if (m == 0 || n == 0) return;

        if (track[m][n] == 1) {
            makeLCSString(m-1, n-1, sb);
            sb.append(s1.charAt(m-1));
        } else if (track[m][n] == 2) {
            makeLCSString(m-1, n, sb);
        } else {
            makeLCSString(m, n-1, sb);
        }
    }

    static int topDownLCS(int m, int n) {
        if(c[m][n] != -1) return c[m][n];

        if(m == 0 || n == 0) return (c[m][n] = 0);

        if(s1.charAt(m-1) == s2.charAt(n-1)) {
            track[m][n] = 1;
            return c[m][n] = 1 + topDownLCS(m-1, n-1);
        }

        int maxVal = Math.max(topDownLCS(m-1, n), topDownLCS(m, n-1));
        if(maxVal == c[m-1][n]) track[m][n] = 2;
        else track[m][n] = 3;

        return (c[m][n] = maxVal);
    }

    static int bottomUpLCS(int m, int n) {
        for (int i = 0; i <= m; i++) c[i][0] = 0;
        for (int i = 0; i <= n; i++) c[0][i] = 0;

        for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
            if(s1.charAt(i-1) == s2.charAt(j-1)) {
                c[i][j] = c[i-1][j-1] + 1;
                track[i][j] = 1;                    // From upper-left
            } else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                track[i][j] = 2;                    // From north/up
            } else {
                c[i][j] = c[i][j-1];
                track[i][j] = 3;                    // From west/left
            }
        }
        
        return c[m][n];
    }
}
```





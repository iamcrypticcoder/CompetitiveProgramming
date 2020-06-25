


```java

public class MaxSubArr1D {

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

    static long maxSubArr1D_Kadane(long[] A) {
        long maxSum = A[0];
        long curMax = A[0];

        for (int i = 1; i < A.length; i++) {
            curMax = Math.max(A[i], curMax + A[i]);
            maxSum = Math.max(maxSum, curMax);
        }

        return maxSum;
    }

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
}
```

```java

public class MaxSubArray2D {

    public static void main(String[] args) {
        long[][] arr1 = new long[][] {
                {0,  -2, -7,  0},
                {9,   2, -6,  2},
                {-4,  1, -4,  1},
                {-1,  8,  0, -2}
        };

        System.out.println(maxSubArr2D(arr1));
        System.out.println(maxSubArr2D_Kadane(arr1));
    }

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
}
```

package com.mahbub.algorithm;

public class Median_Two_Sorted_Array_Demo {

    public static void main(String[] args) {
        int[] arr1 = new int[] {1, 3, 8, 9, 15};
        int[] arr2 = new int[] {7, 11, 18, 19, 21, 25};

        System.out.println(findMedianSortedArrays(arr1, arr2));

        arr1 = new int[] {1, 2, 3, 4, 5, 6};
        arr2 = new int[] {100, 101};

        System.out.println(findMedianSortedArrays(arr1, arr2));
    }

    static double findMedianSortedArrays(int[] arr1, int[] arr2) {
        if (arr1.length > arr2.length)
            return findMedianSortedArrays(arr2, arr1);

        int x = arr1.length;
        int y = arr2.length;

        int low = 0, high = x;
        while (low <= high) {
            int px = (low + high) / 2;              // Partition of X
            int py = (x + y + 1) / 2 - px;          // Partition of Y

            int leftX = (px == 0) ? Integer.MIN_VALUE : arr1[px-1];
            int rightX = (px == x) ? Integer.MAX_VALUE : arr1[px];

            int leftY = (py == 0) ? Integer.MIN_VALUE : arr2[py-1];
            int rightY = (py == y) ? Integer.MAX_VALUE : arr2[py];

            if (leftX <= rightY && leftY <= rightX) {
                if ((x + y) % 2 == 0)
                    return ((double)Math.max(leftX, leftY) + Math.min(rightX, rightY)) / 2;
                else
                    return Math.max(leftX, leftY);
            } else if (leftX > rightY) {
                high = px - 1;
            } else {
                low = px + 1;
            }
        }

        return Double.MIN_VALUE;
    }
}

package com.mahbub.algorithm;

import java.util.Arrays;

public class HeapSort_Demo {

    public static void main(String[] args) {
        int arr[] = new int[] {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
        arr = HeapSort.sortIncreasing(arr);
        System.out.println(Arrays.toString(arr));

        arr = HeapSort.sortDecreasing(arr);
        System.out.println(Arrays.toString(arr));
    }

    static class HeapSort {
        private static int heapArr[];
        private static int heapSize;

        // Complexity: O(n lg n)
        public static int[] sortDecreasing(int[] array) {
            heapArr = new int[array.length+1];
            for(int i = 0; i < array.length; i++) heapArr[i+1] = array[i];
            heapSize = array.length;
            buildMinHeap();
            for(int i = heapSize; i >= 2; i--) {
                int t = heapArr[i];
                heapArr[i] = heapArr[1];
                heapArr[1] = t;
                heapSize = heapSize - 1;
                minHeapify(1);
            }
            return heapArr;
        }

        // Complexity: O(n lg n)
        public static int[] sortIncreasing(int[] array) {
            heapArr = new int[array.length+1];
            for(int i = 0; i < array.length; i++) heapArr[i+1] = array[i];
            heapSize = array.length;
            buildMaxHeap();
            for(int i = heapSize; i >= 2; i--) {
                int t = heapArr[i];
                heapArr[i] = heapArr[1];
                heapArr[1] = t;
                heapSize = heapSize - 1;
                maxHeapify(1);
            }
            return heapArr;
        }

        private static void buildMinHeap() {
            for(int i = heapSize / 2; i >= 1; i--) {
                minHeapify(i);
            }
        }

        private static void buildMaxHeap() {
            for(int i = heapSize / 2; i >= 1; i--) {
                maxHeapify(i);
            }
        }

        // Complexity: O(lg n)
        private static void minHeapify(int parent) {
            int l = left(parent);
            int r = right(parent);
            int smallest = parent;
            if (l <= heapSize && heapArr[l] < heapArr[smallest]) smallest = l;
            if (r <= heapSize && heapArr[r] < heapArr[smallest]) smallest = r;
            if (smallest != parent) {
                int t = heapArr[parent];
                heapArr[parent] = heapArr[smallest];
                heapArr[smallest] = t;
                minHeapify(smallest);
            }
        }

        // Complexity: O(lg n)
        private static void maxHeapify(int parent) {
            int l = left(parent);
            int r = right(parent);
            int largest = parent;
            if (l <= heapSize && heapArr[l] > heapArr[largest]) largest = l;
            if (r <= heapSize && heapArr[r] > heapArr[largest]) largest = r;
            if (largest != parent) {
                int t = heapArr[parent];
                heapArr[parent] = heapArr[largest];
                heapArr[largest] = t;
                maxHeapify(largest);
            }
        }

        private static int parent(int i) {
            return (i / 2);
        }

        private static int left(int i) {
            return (2 * i);
        }

        private static int right(int i) {
            return (2 * i + 1);
        }
    }
}

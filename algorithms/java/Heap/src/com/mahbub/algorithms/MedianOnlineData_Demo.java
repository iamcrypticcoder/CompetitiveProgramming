package com.mahbub.algorithms;

public class MedianOnlineData_Demo {

    static BinaryHeap maxHeap = new BinaryHeap(100, false);
    static BinaryHeap minHeap = new BinaryHeap(100, true);

    public static void main(String args[]) {
        System.out.println(getMedian(5));
        System.out.println(getMedian(1));
        System.out.println(getMedian(10));
        System.out.println(getMedian(100));
        System.out.println(getMedian(9));
        System.out.println(getMedian(6));
        System.out.println(getMedian(7));
    }

    static double getMedian(int x) {
        if (maxHeap.heapSize == 0 && minHeap.heapSize == 0) {
            maxHeap.insertItem(x);
            return x;
        }

        int h1 = maxHeap.getPeek();
        int h2 = minHeap.getPeek();

        if (x <= h1) {
            maxHeap.insertItem(x);
            // Balance heaps
            if (maxHeap.heapSize - minHeap.heapSize == 2) {
                int tmp = maxHeap.extractMin();
                minHeap.insertItem(tmp);
            }
        } else if (x >= h2) {
            minHeap.insertItem(x);
            if (minHeap.heapSize - maxHeap.heapSize == 2) {
                int tmp = minHeap.extractMin();
                maxHeap.insertItem(tmp);
            }
        } else {
            if (maxHeap.heapSize <= minHeap.heapSize) maxHeap.insertItem(x);
            else minHeap.insertItem(x);
        }

        if (maxHeap.heapSize > minHeap.heapSize) return maxHeap.getPeek();
        if (maxHeap.heapSize < minHeap.heapSize) return minHeap.getPeek();

        return ((double)maxHeap.getPeek() + minHeap.getPeek()) / 2;
    }

    static class BinaryHeap {
        int heapArr[];              // Root node index is 1
        int heapSize;
        int capacity;
        boolean isMinHeap;

        BinaryHeap(int capacity, boolean isMinHeap) {
            this.capacity = capacity;
            heapArr = new int[capacity + 1];
            heapSize = 0;
            this.isMinHeap = isMinHeap;
        }

        // Complexity: O(lg n)
        public void insertItem(int item) {
            if(heapSize == capacity) return;
            heapSize++;
            heapArr[heapSize] = item;
            int currentNode = heapSize;
            int parentNode = parent(currentNode);

            while(currentNode != 1 && heapCondition(heapArr[currentNode], heapArr[parentNode])) {
                int t = heapArr[parentNode];
                heapArr[parentNode] = heapArr[currentNode];
                heapArr[currentNode] = t;
                currentNode = parentNode;
                parentNode = parent(currentNode);
            }
        }

        // Complexity: O(1)
        public int getPeek() {
            return heapArr[1];
        }

        // Complexity: O(lg n)
        public int extractMin() {
            if(heapSize == 0) return Integer.MAX_VALUE;
            if(heapSize == 1) {
                heapSize--;
                return heapArr[1];
            }

            int root = heapArr[1];
            heapArr[1] = heapArr[heapSize];
            heapSize--;
            minHeapify(1);

            return root;
        }

        private void minHeapify(int parent) {
            int l = left(parent);
            int r = right(parent);
            int smallest = parent;
            if (l <= heapSize && heapCondition(heapArr[l], heapArr[smallest])) smallest = l;
            if (r <= heapSize && heapCondition(heapArr[r], heapArr[smallest])) smallest = r;
            if (smallest != parent) {
                int t = heapArr[parent];
                heapArr[parent] = heapArr[smallest];
                heapArr[smallest] = t;
                minHeapify(smallest);
            }
        }

        private boolean heapCondition(int a, int b) {
            return isMinHeap ? a < b : b < a;
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

package com.mahbub.algorithm;

public class BinaryHeap_Demo {

    public static void main(String[] args) {
        BinaryMinHeap minHeap = new BinaryMinHeap(100);
        minHeap.insertItem(5);
        minHeap.insertItem(6);
        minHeap.insertItem(7);
        minHeap.insertItem(10);
        minHeap.insertItem(11);
        minHeap.insertItem(12);
        minHeap.insertItem(13);

        minHeap.printHeapArray();
        System.out.println();

        minHeap.extractMin();
        minHeap.printHeapArray();
        System.out.println();

        minHeap.decreaseItem(4, 2);
        minHeap.printHeapArray();
        System.out.println();

        minHeap.deleteItem(2);
        minHeap.printHeapArray();
        System.out.println();

    }

    static class BinaryMinHeap {
        int heapArr[];              // Root node index is 1
        int heapSize;
        int capacity;

        BinaryMinHeap(int capacity) {
            this.capacity = capacity;
            heapArr = new int[capacity+1];
            heapSize = 0;
        }

        // Complexity: O(lg n)
        public void insertItem(int item) {
            if(heapSize == capacity) return;
            heapSize++;
            heapArr[heapSize] = item;
            int currentNode = heapSize;
            int parentNode = parent(currentNode);

            while(currentNode != 1 && heapArr[parentNode] > heapArr[currentNode]) {
                int t = heapArr[parentNode];
                heapArr[parentNode] = heapArr[currentNode];
                heapArr[currentNode] = t;
                currentNode = parentNode;
                parentNode = parent(currentNode);
            }
        }

        // Complexity: O(lg n)
        public int getMin() {
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

        public void decreaseItem(int index, int newVal) {
            heapArr[index] = newVal;
            int parentNode = parent(index);
            while(index != 1 && heapArr[parentNode] > heapArr[index]) {
                int t = heapArr[parentNode];
                heapArr[parentNode] = heapArr[index];
                heapArr[index] = t;
                index = parentNode;
                parentNode = parent(index);
            }
        }

        // Complexity: O(lg n)
        public void deleteItem(int index) {
            // Assign lowest value possible so that it will reach to root
            decreaseItem(index, Integer.MIN_VALUE);
            // Then extract min will remove that item from heap tree. correct ?
            extractMin();
        }

        public void printHeapArray() {
            for(int i = 1; i <= heapSize; i++) {
                System.out.println(heapArr[i] + " ");
            }
        }

        private void minHeapify(int parent) {
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

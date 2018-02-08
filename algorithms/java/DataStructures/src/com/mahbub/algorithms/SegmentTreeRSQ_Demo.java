package com.mahbub.algorithms;


import java.util.ArrayList;
import java.util.List;

public class SegmentTreeRSQ_Demo {

    public static void main(String args[]) {

        int N = 7;
        int[] arr = new int[] { 8, 7, 3, 9, 5, 1, 10 };

        SegmentTreeRSQ tree = new SegmentTreeRSQ(arr);

        // Build whole tree if you want
        tree.build();
        System.out.println(tree.query(0, N-1));
        System.out.println(tree.query(2, 5));

        // Update single value
        tree.updateSingle(3, 10);
        System.out.println(tree.query(2, 5));

        // Update Range
        tree.updateRange(0, 2, 10);
        System.out.println(tree.query(2, 5));

        // Update Lazy and Query Lazy
        tree.updateRangeLazy(3, 5, 10);
        System.out.println(tree.query(2, 5));
    }


    static class SegmentTreeRSQ {
        int N, A[], st[], lazy[];

        public SegmentTreeRSQ(int array[]) {
            N = array.length;
            A = array;
            st = new int[3 * N];
            lazy = new int[3 * N];
        }

        public void build() {
            build(1, 0, N-1);
        }

        public int query(int i, int j) {
            return query(1, 0, N-1, i, j);
        }

        public void updateSingle(int pos, int val) {
            updateSingle(1, 0, N-1, pos, val);
        }

        public void updateRange(int pos1, int pos2, int val) {
            updateRange(1, 0, N-1, pos1, pos2, val);
        }

        public void updateRangeLazy(int pos1, int pos2, int val) {
            updateRangeLazy(1, 0, N-1, pos1, pos2, val);
        }

        public void queryLazy(int i, int j) {
            queryLazy(1, 0, N-1, i, j);
        }

        // Complexity: O(2n-1) = O(n)
        private void build(int p, int L, int R) {
            if (L == R) {
                st[p] = A[L];
                return;
            }

            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);

            st[p] = st[left(p)] + st[right(p)];
        }

        // Complexity: O(lg n)
        private int query(int p, int L, int R, int i, int j) {
            if (i > R || j < L) return -1;
            if (L >= i && R <= j) return st[p];

            int p1 = query(left(p), L, (L + R) / 2, i, j);
            int p2 = query(right(p), (L + R) / 2 + 1, R, i, j);

            if (p1 == -1) return p2;
            if (p2 == -1) return p1;

            return (p1 + p2);
        }

        // Complexity: O(lg n)
        private void updateSingle(int p, int L, int R, int pos, int val) {
            if (L == R) {
                A[pos] = st[p] = val;
                return;
            }
            int mid = (L + R) / 2;
            if (pos <= mid) updateSingle(left(p), L, mid, pos, val);
            else updateSingle(right(p), mid + 1, R, pos, val);

            st[p] = st[left(p)] + st[right(p)];
        }

        // Complexity: O(n)
        // Update value by val from pos1 to pos2 and modify whole tree
        void updateRange(int p, int L, int R, int pos1, int pos2, int val) {
            if (pos1 > R || pos2 < L) return;
            if (L == R) {
                A[L] = st[p] = val;
                return;
            }
            int mid = (L + R) / 2;
            updateRange(left(p), L, mid, pos1, pos2, val);
            updateRange(right(p), mid + 1, R, pos1, pos2, val);

            st[p] = st[left(p)] + st[right(p)];
        }

        // Update value of parent (p) from it's child
        void pushUp(int p) {
            st[p] = st[left(p)] + st[right(p)];
        }

        // Populate lazy value of parent (p) to it's child reset it's own lazy value
        void pushDown(int p, int L, int R) {
            if (lazy[p] == 0) return;

            int mid = (L + R) >> 1;
            st[left(p)] = (mid - L + 1) * lazy[p];
            st[right(p)] = (R - mid) * lazy[p];
            lazy[left(p)] = lazy[right(p)] = lazy[p];
            lazy[p] = 0;
        }

        // Complexity: O(n)
        // Update value by val from pos1 to pos2 and modify whole tree
        void updateRangeLazy(int p, int L, int R, int pos1, int pos2, int val) {
            if (pos1 > R || pos2 < L) return;		// Current segment is not within range [pos1 .. pos2]

            // If segment is fully within range
            if (L >= pos1 && R <= pos2) {
                st[p] = (R - L + 1) * val;
                if (L != R) lazy[p] = val;
                return;
            }

            pushDown(p, L, R);

            int mid = (L + R) >> 1;
            updateRangeLazy(left(p), L, mid, pos1, pos2, val);
            updateRangeLazy(right(p), mid + 1, R, pos1, pos2, val);
            pushUp(p);
        }

        // Complexity:
        // Query for Lazy Update
        int queryLazy(int p, int L, int R, int pos1, int pos2) {
            if (pos1 > R || pos2 < L) return 0;		// Current segment is not within range [pos1 .. pos2]

            // If segment is fully within range
            if (L >= pos1 && R <= pos2) return st[p];

            pushDown(p, L, R);

            int mid = (L + R) >> 1;
            int p1 = queryLazy(left(p), L, mid, pos1, pos2);
            int p2 = queryLazy(right(p), mid + 1, R, pos1, pos2);
            return (p1 + p2);
        }

        private static int left(int p) { return p << 1; }
        private static int right(int p) { return (p << 1) + 1; }
    }

}

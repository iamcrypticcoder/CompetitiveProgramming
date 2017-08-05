package com.mahbub.algorithm;

public class BinomialHeap_Demo {

    public static void main(String[] args) {
        BinomialMinHeap heap = new BinomialMinHeap();
        heap.insertKey(15);
        heap.insertKey(28);
        heap.insertKey(33);
        heap.insertKey(41);
        heap.display();

        System.out.println(heap.getMin().data);
        heap.extractMin();
        System.out.println(heap.getMin().data);
        BinomialMinHeap.Node n = heap.searchKey(41);
        heap.decreaseKey(n, 2);
        System.out.println(heap.getMin().data);

    }

    static class BinomialMinHeap {
        Node head;
        int heapSize;

        BinomialMinHeap() {
            head = null;
            heapSize = 0;
        }

        // Complexity: O(lg n)
        public void insertKey(int key) {
            Node temp = new Node(key, 0);
            head = union(head, temp);
        }

        // Complexity: O(lg n)
        public Node getMin() {
            Node ret = null;
            Node ptr = head;
            int min = Integer.MAX_VALUE;
            while(null != ptr) {
                if(ptr.data < min) {
                    min = ptr.data;
                    ret = ptr;
                }
                ptr = ptr.sibling;
            }
            return ret;
        }

        // Complexity: O(lg n)
        public Node extractMin() {
            Node h1 = null;
            Node t = null;
            Node x = head;
            if(null == x) {
                return null;
            }
            int min = x.data;
            Node p = x;
            while(null != p.sibling) {
                if(p.sibling.data < min) {
                    min = p.sibling.data;
                    t = p;
                    x = p.sibling;
                }
                p = p.sibling;
            }
            if(null == t && null == x.sibling) h1 = null;
            else if(null == t) h1 = x.sibling;
            else if(null == t.sibling) t = null;
            else t.sibling = x.sibling;

            if(null != x.child) {
                reverseList(x.child);
                x.child.sibling = null;
            }

            head = union(head, h1);
            return x;
        }

        // Complexity: O(lg n)
        public void decreaseKey(Node x, int key) {
            if(key > x.data) return;
            x.data = key;
            Node y = x;
            Node z = y.parent;
            while(null != z && y.data < z.data) {
                int t = y.data;
                y.data = z.data;
                z.data = t;
                y = z;
                z = y.parent;
            }
        }

        // Complexity: O(lg n)
        public void deleteKey(Node x) {
            decreaseKey(x, Integer.MIN_VALUE);
            extractMin();
        }

        public Node searchKey(int key) {
            return searchKey(head, key);
        }

        // Display binomial heap
        public void display() {
            if(null == head) {
                return;
            }
            System.out.println("The root nodes are: ");
            Node p = head;
            while(null != p) {
                System.out.print(p.data);
                if(null != p.sibling) System.out.print("-->");
                p = p.sibling;
            }
            System.out.println();
        }

        private Node union(Node h1, Node h2) {
            Node head1 = merge(h1, h2);
            if(null == head1) return head1;
            Node prev = null;
            Node x = head1;
            Node next = x.sibling;
            while(null != next) {
                if(x.degree != next.degree || (null != next.sibling && next.sibling.degree == x.degree)) {
                    prev = x;
                    x = next;
                    next = next.sibling;
                } else {
                    if(x.data <= next.data) {
                        x.sibling = next.sibling;
                        link(next, x);
                    } else {
                        if(null == prev) head1 = next;
                        else prev.sibling = next;
                        link(x, next);
                        x = next;
                    }
                }
                next = x.sibling;
            }
            return head1;
        }

        // Complexity: O(1)
        // It makes root2 the parent of root1
        private void link(Node root1, Node root2) {
            root1.parent = root2;
            root1.sibling = root2.child;
            root2.child = root1;
            root2.degree = root2.degree + 1;
        }

        private Node merge(Node h1, Node h2) {
            Node H;
            Node y, z, a, b;
            y = h1;
            z = h2;
            if(null != y) {
                if(null != z) {
                    if(y.degree <= z.degree) H = y;
                    else H = z;
                } else H = y;
            }
            else H = z;

            while(null != y && null != z) {
                if(y.degree < z.degree) y = y.sibling;
                else if(y.degree == z.degree) {
                    a = y.sibling;
                    y.sibling = z;
                    y = a;
                } else {
                    b = z.sibling;
                    z.sibling = y;
                    z = b;
                }
            }

            return H;
        }

        private void reverseList(Node x) {
            if(null != x.sibling) {
                reverseList(x.sibling);
                x.sibling.sibling = x;
            } else head = x;
        }

        private Node searchKey(Node H, int key) {
            Node x = H;
            Node p = null;
            if(x.data == key) {
                p = x;
                return p;
            }
            if(null != x.child && null == p)
                p = searchKey(x.child, key);
            if(null != x.sibling && null == p)
                p = searchKey(x.sibling, key);
            return p;
        }

        static class Node {
            int data, degree;
            Node parent, child, sibling;

            public Node() {}
            public Node(int data, int degree) {
                this.data = data;
                this.degree = degree;
            }
        }
    }
}

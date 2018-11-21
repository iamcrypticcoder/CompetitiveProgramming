package com.mahbub.algorithms;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by mahbub on 6/21/17.
 */
public class BinarySearchTree_Demo {

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        bst.insertKey(8);
        bst.insertKey(3);
        bst.insertKey(10);
        bst.insertKey(1);
        bst.insertKey(6);
        bst.insertKey(4);
        bst.insertKey(7);
        bst.insertKey(14);
        bst.insertKey(13);

        List<Integer> preOrderList = bst.preOrderTraverse();
        System.out.println(preOrderList.toString());

        System.out.println("Search 8: " + bst.searchKey(8));
        System.out.println("Search 3: " + bst.searchKey(3));
        System.out.println("Search 10: " + bst.searchKey(10));
        System.out.println("Search 100: " + bst.searchKey(100));

        bst.deleteKey(3);

        preOrderList = bst.preOrderTraverse();
        System.out.println(preOrderList.toString());
    }

    static class BinarySearchTree {
        private Node root;
        private int keyCount;
        private List<Integer> preOrderList;

        BinarySearchTree() {

        }

        public Node getRoot() {
            return root;
        }

        // Complexity: O(lg N)
        public void insertKey(int key) {
            root = insertNode(root, key);
        }

        // Complexity: O(lg N)
        public boolean searchKey(int key) {
            return (null != searchNode(root, key));
        }

        // Complexity: O(lg N)
        public void deleteKey(int key) {
            deleteNode(root, key);
        }

        /**
         * Check weather a binary tree is BST or not
         * Call with root and INT_MIN and INT_MAX
         * @param node
         * @param minValue
         * @param maxValue
         */
        public static boolean isBST(Node node, int minValue, int maxValue) {
            if (null == node) return true;
            if (node.key < minValue || node.key > maxValue) return false;
            return (isBST(node.left, minValue, node.key-1) && isBST(node.right, node.key+1, maxValue));
        }

        /**
         * Create BST from pre order traversal.
         * Set static var currentIndex to 0 before calling this method
         * @param preOrder
         * @param minValue
         * @param maxValue
         * @return Root node of BST
         */
        static int currentIndex;
        public static Node createBSTFromPreOrderTraversal(int[] preOrder, int minValue, int maxValue) {
            if (currentIndex >= preOrder.length) return null;

            int key = preOrder[currentIndex];

            // If key isn't in range of min and max value
            if (key <= minValue || key >= maxValue) return null;

            Node node = new Node(key);
            currentIndex = currentIndex + 1;

            node.left = createBSTFromPreOrderTraversal(preOrder, minValue, key);
            node.right = createBSTFromPreOrderTraversal(preOrder, key, maxValue);

            return node;
        }

        /**
         * Create BST from pre order traversal.
         * @param preOrder
         * @return Root node of BST
         */
        public static Node createBSTFromPreOrderTraversal(int[] preOrder) {
            Stack<Node> S = new Stack<>();
            Node root = new Node(preOrder[0]);
            S.push(root);

            for (int i = 1; i < preOrder.length; i++) {
                // It means this value should be placed in left subtree
                if (preOrder[i] < S.peek().key) {
                    S.peek().left = new Node(preOrder[i]);
                    S.push(S.peek().left);
                } else {
                    Node tmp = null;
                    while (!S.empty() && preOrder[i] > S.peek().key) {
                        tmp = S.pop();
                    }
                    tmp.right = new Node(preOrder[i]);
                    S.push(tmp.right);
                }
            }
            return root;
        }

        /**
         * Finds LCA of key n1 and n2
         * @param node
         * @param n1
         * @param n2
         * @return
         */
        public Node findLCA(Node node, int n1, int n2) {
            if (null == node) return node;
            if (node.key < n1 && node.key < n2) return findLCA(node.right, n1, n2);
            else if (node.key > n1 && node.key > n2) return findLCA(node.left, n1, n2);
            return node;
        }

        /**
         * Merge two BST with minimum space complexity.
         * @param root1
         * @param root2
         * @return Sorted list of merged BST
         */
        public static List<Integer> mergeBST(Node root1, Node root2) {
            List<Integer> retList = new ArrayList<>();
            Stack<Node> s1 = new Stack<>();
            Stack<Node> s2 = new Stack<>();
            Node node1 = root1, node2 = root2;

            while (null != node1 || null != node2 ||
                    !s1.isEmpty() || !s2.isEmpty()) {

                if (null != node1 || null != node2) {
                    if (null != node1) {
                        s1.push(node1);
                        node1 = node1.left;
                    }
                    if (null != node2) {
                        s2.push(node2);
                        node2 = node2.left;
                    }
                    continue;
                }

                if (s1.isEmpty()) {
                    while (!s2.isEmpty()) {
                        node2 = s2.pop();
                        retList.add(node2.key);
                    }
                    break;
                }

                if (s2.isEmpty()) {
                    while (!s1.isEmpty()) {
                        node1 = s1.pop();
                        retList.add(node1.key);
                    }
                    break;
                }

                node1 = s1.peek();
                node2 = s2.peek();

                if (node1.key < node2.key) {
                    retList.add(node1.key);
                    node1 = node1.right;
                    s1.pop();
                    node2 = null;
                } else {
                    retList.add(node2.key);
                    node2 = node2.right;
                    s2.pop();
                    node1 = null;
                }
            }

            return retList;
        }

        public List<Integer> inOrderTraverse() {
            List<Integer> list = new ArrayList<>();
            inOrderRecursive(root, list);
            return list;
        }

        public List<Integer> preOrderTraverse() {
            List<Integer> list = new ArrayList<>();
            preOrderRecursive(root, list);
            return list;
        }

        public List<Integer> postOrderTraverse() {
            List<Integer> list = new ArrayList<>();
            postOrderRecursive(root, list);
            return list;
        }

        private Node insertNode(Node node, int key) {
            if(null == node) return new Node(key);
            if(key < node.key) node.left = insertNode(node.left, key);
            else node.right = insertNode(node.right, key);
            return node;
        }

        private Node searchNode(Node node, int key) {
            if(null == node || node.key == key) return node;
            if(key < node.key) return searchNode(node.left, key);
            else return searchNode(node.right, key);
        }

        private Node deleteNode(Node node, int key) {
            if(null == node) return node;
            if (key < node.key) node.left = deleteNode(node.left, key);
            else if(key > node.key) node.right = deleteNode(node.right, key);
            else {
                // Node with one child or no child
                if (null == node.left) return node.right;
                if (null == node.right) return node.left;

                Node temp = inorderSuccessor(node.right);
                node.key = temp.key;

                node.right = deleteNode(node.right, temp.key);
            }
            return node;
        }

        private Node inorderSuccessor(Node node) {
            Node current = node;
            while(null != current.left) current = current.left;
            return current;
        }

        private void inOrderRecursive(Node node, List<Integer> list) {
            if(null == node) return;
            inOrderRecursive(node.left, list);
            list.add(node.key);
            inOrderRecursive(node.right, list);
        }

        private void preOrderRecursive(Node node, List<Integer> list) {
            if(null == node) return;
            list.add(node.key);
            preOrderRecursive(node.left, list);
            preOrderRecursive(node.right, list);
        }

        private void postOrderRecursive(Node node, List<Integer> list) {
            if (null == node) return;
            postOrderRecursive(node.left, list);
            postOrderRecursive(node.right, list);
            list.add(node.key);
        }
    }

    static class Node {
        int key;
        Node left, right;

        public Node() {

        }

        public Node(int key) {
            this.key = key;
        }
    }
}

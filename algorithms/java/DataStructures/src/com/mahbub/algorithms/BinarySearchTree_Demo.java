package com.mahbub.algorithms;

import java.util.ArrayList;
import java.util.List;

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
         * Call with root and INT_MIN
         * @param node
         * @param lastValue
         */
        public boolean isBST(Node node, int lastValue) {
            if(null == node) return true;
            isBST(node.left, lastValue);
            if(node.key < lastValue) return false;
            lastValue = node.key;
            isBST(node.right, lastValue);
            return true;
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

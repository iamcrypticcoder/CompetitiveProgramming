package com.mahbub.algorithms;

import java.util.*;

public class LevelOrderTraversal_Demo {

    public static void main(String args[]) {
        BinaryTree binaryTree = new BinaryTree();
        Node root = new Node(1);
        root.left = new Node(2);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        root.right = new Node(3);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        binaryTree.setRoot(root);

        System.out.print("Level Order Traversal: ");
        System.out.println(binaryTree.levelOrderTraverse().toString());

        System.out.print("Reverse Level Order Traversal Method 1: ");
        System.out.println(binaryTree.reverseLevelOrderTraversalMethod1().toString());

        System.out.print("Reverse Level Order Traversal Method 2: ");
        System.out.println(binaryTree.reverseLevelOrderTraversalMethod2().toString());
    }

    static class BinaryTree {
        Node root;
        int size;

        public BinaryTree() {
        }

        public BinaryTree(Node root, int sz) {
            this.root = root;
            size = sz;
        }

        public Node getRoot() { return root; }

        public void setRoot(Node root) { this.root = root; }

        // Complexity: O(n)
        public List<Integer> levelOrderTraverse() {
            List<Integer> list = new ArrayList<>();
            Queue<Node> Q = new LinkedList<>();
            Q.add(root);
            while(!Q.isEmpty()) {
                Node node = Q.poll();
                list.add(node.key);
                if(null != node.left) Q.add(node.left);
                if(null != node.right) Q.add(node.right);
            }
            return list;
        }

        // Complexity: O(n lg n) ~ O(n^2)
        public List<Integer> reverseLevelOrderTraversalMethod1() {
            List<Integer> list = new ArrayList<>();

            int height = findHeight(root);
            for(int i = height; i >= 1; i--) {
                findNodesAtLevel(root, i,list);
            }

            return list;
        }

        // Complexity: O(n)
        public List<Integer> reverseLevelOrderTraversalMethod2() {
            List<Integer> list = new ArrayList<>();

            Queue<Node> Q = new LinkedList<>();
            Stack<Integer> S = new Stack<>();

            Q.add(root);

            while (!Q.isEmpty()) {
                Node node = Q.poll();
                S.push(node.key);

                if (null != node.right) Q.add(node.right);
                if (null != node.left) Q.add(node.left);
            }

            while (!S.empty()) {
                list.add(S.peek());
                S.pop();
            }

            return list;
        }

        // Complexity: O(n)
        private void findNodesAtLevel(Node node, int level, List<Integer> list) {
            if (level == 1) {
                list.add(node.key);
                return;
            }

            if (null != node.left) findNodesAtLevel(node.left, level - 1, list);
            if (null != node.right) findNodesAtLevel(node.right, level -1, list);
        }

        // Complexity: O(n)
        private int findHeight(Node node) {
            if (null == node) return 0;

            int leftHeight = findHeight(node.left);
            int rightHeight = findHeight(node.right);

            return Math.max(leftHeight, rightHeight) + 1;
        }
    }

    static class Node {
        int key;
        Node left, right;

        public Node() {}

        public Node(int key) {
            this.key = key;
        }
    }
}

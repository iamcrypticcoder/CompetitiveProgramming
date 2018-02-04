package com.mahbub.algorithms;

import java.util.ArrayList;
import java.util.List;

public class MorrisTraversal_Demo {

    public static void main(String args[]) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.left.left = new Node(3);
        root.left.right = new Node(4);
        root.left.right.left = new Node(5);
        root.left.right.right = new Node(6);

        root.right = new Node(7);
        root.right.left = new Node(8);
        root.right.left.right = new Node(9);
        root.right.right = new Node(10);

        BinaryTree binaryTree = new BinaryTree();
        binaryTree.setRoot(root);

        List<Integer> list = binaryTree.morrisInorderTraverse();
        for (int x : list) System.out.print(x + " ");

    }

    static class BinaryTree {
        Node root;
        int keyCount;

        public BinaryTree() { }

        public Node getRoot() { return root; }

        public void setRoot(Node root) { this.root = root; }

        public List<Integer> morrisInorderTraverse() {
            List<Integer> list = new ArrayList<>();
            Node current = root;
            while (null != current) {
                // If left child not exist, add it into list
                if (null == current.left) {
                    list.add(current.key);
                    current = current.right;
                    continue;
                }

                // Find inorder predecessor
                Node predecessor = findInorderPredecessor(current);

                // First time need to link to current node as right node
                if (null == predecessor.right) {
                    predecessor.right = current;
                    current = current.left;
                } else {
                    // Cut link to current node
                    predecessor.right = null;
                    list.add(current.key);
                    current = current.right;
                }
            }

            return list;
        }

        private Node findInorderPredecessor(Node node) {
            Node temp = node.left;
            // node != temp.right <- this is an extra condition required for morris. Think about it.
            // When there is already a link to current node
            while (null != temp.right && node != temp.right) temp = temp.right;
            return temp;
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

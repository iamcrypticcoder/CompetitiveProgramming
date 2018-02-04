package com.mahbub.algorithms;

import java.util.ArrayList;
import java.util.List;

public class BoundaryNodes_Demo {

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

        List<Integer> list = binaryTree.findBoundaryNodes();
        for (int x : list) System.out.print(x + " ");

    }

    static class BinaryTree {
        Node root;
        int keyCount;

        public BinaryTree() {}

        public Node getRoot() { return root; }

        public void setRoot(Node root) { this.root = root; }

        public List<Integer> findBoundaryNodes() {
            // Find all left side nodes
            List<Integer> list = new ArrayList<>();
            findLeftNodes(root, list);

            // Last element will be added again. That's why deleting it
            if (list.size() > 0) list.remove(list.size()-1);

            // Find leaf nodes
            findLeafNodes(root, list);

            // Last element will be added again. That's why deleting it
            if (list.size() > 0) list.remove(list.size()-1);

            // Find all right nodes
            findRightNodes(root, list);

            // Last element is actually root element. That's why deleting it
            if (list.size() > 0) list.remove(list.size()-1);

            return list;
        }

        private void findLeftNodes(Node node, List<Integer> list) {
            if (null == node) return;

            list.add(node.key);

            if (null != node.left)
                findLeftNodes(node.left, list);
            else if (null != node.right)
                findLeftNodes(node, list);
        }

        private void findLeafNodes(Node node, List<Integer> list) {
            if (null == node) return;

            findLeafNodes(node.left, list);

            if (null == node.left && null == node.right) list.add(node.key);

            findLeafNodes(node.right, list);
        }

        private void findRightNodes(Node node, List<Integer> list) {
            if (null == node) return;

            if (null != node.right)
                findRightNodes(node.right, list);
            else if (null != node.left)
                findRightNodes(node.left, list);

            list.add(node.key);
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

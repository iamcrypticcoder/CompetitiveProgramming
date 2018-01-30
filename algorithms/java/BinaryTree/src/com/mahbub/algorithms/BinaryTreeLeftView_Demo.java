package com.mahbub.algorithms;

import java.util.ArrayList;
import java.util.List;

// http://www.geeksforgeeks.org/print-left-view-binary-tree/
public class BinaryTreeLeftView_Demo {
    private static int maxLevel;
    private static List<Integer> leftView;

    static void leftViewRecursion(Node root, int level) {
        if(null == root) return;
        if(level > maxLevel) {
            leftView.add(root.key);
            maxLevel = level;
        }

        leftViewRecursion(root.left, level+1);
        leftViewRecursion(root.right, level+1);
    }

    static List<Integer> generateleftView(Node root) {
        maxLevel = 0;
        leftView = new ArrayList<>();
        leftViewRecursion(root, 1);
        return leftView;
    }

    static class Node {
        int key;
        public Node left, right;

        Node(int key) {
            this.key = key;
        }
    }

    public static void main(String args[]) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        System.out.println("Left View: " + generateleftView(root));
    }
}

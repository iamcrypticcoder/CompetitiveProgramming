package com.mahbub.algorithms;

import java.util.*;

// http://www.geeksforgeeks.org/print-left-view-binary-tree/
// https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
public class BinaryTreeLeftView_Demo {
    private static int maxLevel;

    public static void main(String args[]) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        System.out.println("Left View: " + generateleftView(root));
        System.out.println("Right View: " + generateRightView(root));
    }

    static void rightViewRecursion(Node root, int level, List<Integer> rightView) {
        if (null == root) return;
        if (level > maxLevel) {
            rightView.add(root.key);
            maxLevel = level;
        }

        rightViewRecursion(root.right, level+1, rightView);
        rightViewRecursion(root.left, level+1, rightView);
    }

    static List<Integer> generateRightView(Node root) {
        maxLevel = 0;
        List<Integer> rightView = new ArrayList<>();
        rightViewRecursion(root, 1, rightView);
        return rightView;
    }

    static void leftViewRecursion(Node root, int level, List<Integer> leftView) {
        if(null == root) return;
        if(level > maxLevel) {
            leftView.add(root.key);
            maxLevel = level;
        }

        leftViewRecursion(root.left, level+1, leftView);
        leftViewRecursion(root.right, level+1, leftView);
    }

    static List<Integer> generateleftView(Node root) {
        maxLevel = 0;
        List<Integer> leftView = new ArrayList<>();
        leftViewRecursion(root, 1, leftView);
        return leftView;
    }

    static class Node {
        int key;
        public Node left, right;

        Node(int key) {
            this.key = key;
        }
    }
}

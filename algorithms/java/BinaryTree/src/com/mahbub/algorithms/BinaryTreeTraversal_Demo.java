package com.mahbub.algorithm;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class BinaryTreeTraversal_Demo {

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        Node root = tree.getRoot();
        root.data = 10;
        root.left = new Node(20);
        root.right = new Node(30);

        System.out.println(tree.inOrderTraverse().toString());
        System.out.println(tree.preOrderTraverse().toString());
        System.out.println(tree.postOrderTraverse().toString());

        int[] preOrder = new int[] { 10, 20, 40, 50, 30, 60, 70 };
        int[] inOrder = new int[] { 40, 20, 50, 10, 60, 30, 70 };
        int[] postOrder = new int[] { 40, 50, 20, 60, 70, 30, 10 };

        BinaryTree builtTree = BinaryTree.buildTreeFromPreOrderInOrder(preOrder, inOrder);
        System.out.println(builtTree.inOrderTraverse().toString());
        System.out.println(builtTree.preOrderTraverse().toString());
        System.out.println(builtTree.postOrderTraverse().toString());
        System.out.println(builtTree.levelOrderTraverse().toString());

        builtTree = BinaryTree.buildTreeFromPostOrderInOrder(postOrder, inOrder);
        System.out.println(builtTree.inOrderTraverse().toString());
        System.out.println(builtTree.preOrderTraverse().toString());
        System.out.println(builtTree.postOrderTraverse().toString());
        System.out.println(builtTree.levelOrderTraverse().toString());
    }

    static class BinaryTree {
        Node root;
        int size;

        static int preIndex;
        static int postIndex;

        public BinaryTree() {
            root = new Node();
            size = 1;
        }

        public BinaryTree(Node node, int sz) {
            root = node;
            size = sz;
        }

        public Node getRoot() {
            return root;
        }

        public static BinaryTree buildTreeFromPreOrderInOrder(int[] preOrder, int[] inOrder) {
            preIndex = 0;
            Node node = buildTreeFromPreOrderInOrder(preOrder, inOrder, 0, inOrder.length-1);
            BinaryTree tree = new BinaryTree(node, preOrder.length);
            return tree;
        }

        public static BinaryTree buildTreeFromPostOrderInOrder(int[] postOrder, int[] inOrder) {
            postIndex = postOrder.length-1;
            Node node = buildTreeFromPostOrderInOrder(postOrder, inOrder, 0, inOrder.length-1);
            BinaryTree tree = new BinaryTree(node, postOrder.length);
            return tree;
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

        public List<Integer> levelOrderTraverse() {
            List<Integer> list = new ArrayList<>();
            Queue<Node> Q = new LinkedList<Node>();
            Q.add(root);
            while(!Q.isEmpty()) {
                Node node = Q.poll();
                list.add(node.data);
                if(null != node.left) Q.add(node.left);
                if(null != node.right) Q.add(node.right);
            }
            return list;
        }

        private void inOrderRecursive(Node node, List<Integer> list) {
            if(null == node) return;
            inOrderRecursive(node.left, list);
            list.add(node.data);
            inOrderRecursive(node.right, list);
        }

        private void preOrderRecursive(Node node, List<Integer> list) {
            if(null == node) return;
            list.add(node.data);
            preOrderRecursive(node.left, list);
            preOrderRecursive(node.right, list);
        }

        private void postOrderRecursive(Node node, List<Integer> list) {
            if (null == node) return;
            postOrderRecursive(node.left, list);
            postOrderRecursive(node.right, list);
            list.add(node.data);
        }

        private static Node buildTreeFromPreOrderInOrder(int[] preOrder, int[] inOrder, int inStart, int inEnd)  {
            if(inStart > inEnd) return null;

            Node node = new Node(preOrder[preIndex++]);

            if(inStart == inEnd) return node;

            int pos = searchCharPos(inOrder, inStart, inEnd, node.data);

            node.left = buildTreeFromPreOrderInOrder(preOrder, inOrder, inStart, pos-1);
            node.right = buildTreeFromPreOrderInOrder(preOrder, inOrder, pos+1, inEnd);
            return node;
        }

        private static Node buildTreeFromPostOrderInOrder(int[] postOrder, int[] inOrder, int inStart, int inEnd) {
            if(inStart > inEnd) return null;

            Node node = new Node(postOrder[postIndex--]);

            if(inStart == inEnd) return node;

            int pos = searchCharPos(inOrder, inStart, inEnd, node.data);

            node.right = buildTreeFromPostOrderInOrder(postOrder, inOrder, pos+1, inEnd);
            node.left = buildTreeFromPostOrderInOrder(postOrder, inOrder, inStart, pos-1);
            return node;
        }

        private static int searchCharPos(int[] inOrder, int inStart, int inEnd, int value) {
            for(int i=inStart; i <= inEnd; i++)
                if(inOrder[i] == value) return i;
            return -1;
        }
    }

    static class Node {
        int data;
        Node left, right;

        public Node() {
            data = 0;
            left = right = null;
        }

        public Node(int d) {
            data = d;
            left = right = null;
        }
    }
}

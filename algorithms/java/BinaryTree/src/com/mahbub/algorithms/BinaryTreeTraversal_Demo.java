package com.mahbub.algorithms;

import java.util.*;

public class BinaryTreeTraversal_Demo {

    public static void main(String[] args) {
        BinaryTree binaryTree = new BinaryTree();
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        binaryTree.setRoot(root);

        System.out.print("Preorder Recursive: ");
        System.out.println(binaryTree.preOrderRecursive().toString());
        System.out.print("Inorder Recursive: ");
        System.out.println(binaryTree.inOrderRecursive().toString());
        System.out.print("Postorder Recursive: ");
        System.out.println(binaryTree.postOrderRecursive().toString());

        System.out.print("Preorder Iterative: ");
        System.out.println(binaryTree.preOrderIterative().toString());
        System.out.print("Inorder Iterative: ");
        System.out.println(binaryTree.inOrderIterative().toString());
        System.out.print("Postorder Iterative 1: ");
        System.out.println(binaryTree.postOrderIterative1().toString());
        System.out.print("Postorder Iterative 2: ");
        System.out.println(binaryTree.postOrderIterative2().toString());

        // Construct binary tree

        int[] preOrder = new int[] { 1, 2, 4, 5, 3, 6, 7 };
        int[] inOrder = new int[] { 4, 2, 5, 1, 6, 3, 7 };
        int[] postOrder = new int[] { 4, 5, 2, 6, 7, 3, 1 };

        BinaryTree builtTree = BinaryTree.buildTreeFromPreOrderInOrder(preOrder, inOrder);
        System.out.print("Pre Order : ");
        System.out.println(builtTree.preOrderRecursive().toString());
        System.out.print("In Order : ");
        System.out.println(builtTree.inOrderRecursive().toString());
        System.out.print("Post Order : ");
        System.out.println(builtTree.postOrderRecursive().toString());

        builtTree = BinaryTree.buildTreeFromPostOrderInOrder(postOrder, inOrder);
        System.out.print("Pre Order : ");
        System.out.println(builtTree.preOrderRecursive().toString());
        System.out.print("In Order : ");
        System.out.println(builtTree.inOrderRecursive().toString());
        System.out.print("Post Order : ");
        System.out.println(builtTree.postOrderRecursive().toString());
    }

    static class BinaryTree {
        Node root;
        int size;

        static int preIndex;
        static int postIndex;

        public BinaryTree() { }

        public BinaryTree(Node root, int sz) {
            this.root = root;
            size = sz;
        }

        public Node getRoot() { return root; }

        public void setRoot(Node root) { this.root = root; }

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

        public List<Integer> preOrderIterative() {
            List<Integer> list = new ArrayList<>();
            Stack<Node> nodeStack = new Stack<>();

            nodeStack.push(root);

            while (!nodeStack.empty()) {
                Node node = nodeStack.pop();
                list.add(node.key);

                if (null != node.right) nodeStack.push(node.right);
                if (null != node.left) nodeStack.push(node.left);
            }
            return list;
        }

        public List<Integer> inOrderIterative() {
            List<Integer> list = new ArrayList<>();
            Stack<Node> nodeStack = new Stack<>();
            Node current = root;
            nodeStack.push(current);
            while (null != current.left) {
                current = current.left;
                nodeStack.push(current);
            }

            while(!nodeStack.empty()) {
                current = nodeStack.pop();
                list.add(current.key);

                if (null != current.right) {
                    current = current.right;
                    nodeStack.push(current);
                    while (null != current.left) {
                        current = current.left;
                        nodeStack.push(current);
                    }
                }
            }

            return list;
        }

        // Using two stacks
        public List<Integer> postOrderIterative1() {
            List<Integer> ret = new ArrayList<>();
            Stack<Node> s1 = new Stack<>();
            Stack<Node> s2 = new Stack<>();

            s1.push(root);
            while (!s1.isEmpty()) {
                Node node = s1.pop();
                s2.push(node);
                if (null != node.left) s1.push(node.left);
                if (null != node.right) s1.push(node.right);
            }

            while (!s2.isEmpty())
                ret.add(s2.pop().key);

            return ret;
        }

        // Using only one stack
        // https://www.geeksforgeeks.org/iterative-postorder-traversal-set-3/?ref=rp
        public List<Integer> postOrderIterative2() {
            List<Integer> ret = new ArrayList<>();
            Stack<Pair> stack = new Stack<>();

            stack.push(new Pair(root, 0));

            while (!stack.isEmpty()) {
                Pair p = stack.pop();
                if (p.code == 2) {
                    ret.add(p.node.key);
                    continue;
                }
                stack.push(new Pair(p.node, p.code+1));
                if (p.code == 0) {
                    if (null != p.node.left) stack.push(new Pair(p.node.left, 0));
                } else {
                    if (null != p.node.right) stack.push(new Pair(p.node.right, 0));
                }
            }

            return ret;
        }

        public List<Integer> inOrderRecursive() {
            List<Integer> list = new ArrayList<>();
            inOrderRecursive(root, list);
            return list;
        }

        public List<Integer> preOrderRecursive() {
            List<Integer> list = new ArrayList<>();
            preOrderRecursive(root, list);
            return list;
        }

        public List<Integer> postOrderRecursive() {
            List<Integer> list = new ArrayList<>();
            postOrderRecursive(root, list);
            return list;
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

        private static Node buildTreeFromPreOrderInOrder(int[] preOrder, int[] inOrder, int inStart, int inEnd)  {
            if(inStart > inEnd) return null;

            Node node = new Node(preOrder[preIndex++]);

            if(inStart == inEnd) return node;

            int pos = searchCharPos(inOrder, inStart, inEnd, node.key);

            node.left = buildTreeFromPreOrderInOrder(preOrder, inOrder, inStart, pos-1);
            node.right = buildTreeFromPreOrderInOrder(preOrder, inOrder, pos+1, inEnd);
            return node;
        }

        private static Node buildTreeFromPostOrderInOrder(int[] postOrder, int[] inOrder, int inStart, int inEnd) {
            if(inStart > inEnd) return null;

            Node node = new Node(postOrder[postIndex--]);

            if(inStart == inEnd) return node;

            int pos = searchCharPos(inOrder, inStart, inEnd, node.key);

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

    static class Pair {
        Node node;
        int code;  // 0 -  Left element, 1 -  Right element, 2 -  Node element
        public Pair(Node node, int code) {
            this.node = node;
            this.code = code;
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

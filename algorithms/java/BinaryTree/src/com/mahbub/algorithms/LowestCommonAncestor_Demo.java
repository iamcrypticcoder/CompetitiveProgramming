package com.mahbub.algorithms;

import java.util.ArrayList;
import java.util.List;

public class LowestCommonAncestor_Demo {

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        System.out.println(findLCA(root, 4, 5));
        System.out.println(findLCA(root, 4, 6));
        System.out.println(findLCA(root, 3, 4));
        System.out.println(findLCA(root, 2, 4));

    }

    static int findLCA(Node root, int n1, int n2) {
        List<Integer> path1 = new ArrayList<>();
        List<Integer> path2 = new ArrayList<>();
        if(findPath(root, n1, path1) == false) {
            System.out.println("n1 isn't exist in tree");
            return -1;
        }
        if(findPath(root, n2, path2) == false) {
            System.out.println("n2 isn't exist in tree");
            return -1;
        }

        int i = 0;
        int len = Math.min(path1.size(), path2.size());
        for(i=0; i < len; i++) {
            if(path1.get(i) != path2.get(i)) break;
        }
        return path1.get(i-1);
    }

    static boolean findPath(Node node, int n, List<Integer> path) {
        if(null == node) return false;
        path.add(node.key);
        if(node.key == n) return true;
        if(null != node.left && findPath(node.left, n, path)) return true;
        if(null != node.right && findPath(node.right, n, path)) return true;
        path.remove(path.size()-1);
        return false;
    }

    static class Node {
        int key;
        public Node left, right;

        Node(int key) {
            this.key = key;
        }
    }
}

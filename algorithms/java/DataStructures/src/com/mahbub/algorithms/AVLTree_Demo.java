package com.mahbub.algorithms;

public class AVLTree_Demo {

    public static void main(String[] args) {
        /* Constructing tree given in the above figure */
        Node root = null;
        root = insertNode(root, 9);
        root = insertNode(root, 5);
        root = insertNode(root, 10);
        root = insertNode(root, 0);
        root = insertNode(root, 6);
        root = insertNode(root, 11);
        root = insertNode(root, -1);
        root = insertNode(root, 1);
        root = insertNode(root, 2);

        /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

        System.out.println("Pre order traversal of the constructed AVL tree is \n");
        preOrder(root);

        root = deleteNode(root, 10);

    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

        System.out.println("\nPre order traversal after deletion of 10 \n");
        preOrder(root);
    }

    static void preOrder(Node n) {
        if(n == null) return;
        System.out.print(n.key + " ");
        preOrder(n.left);
        preOrder(n.right);
    }

    static int height(Node node) {
        if (null == node) return 0;
        return node.height;
    }

    static int getBalance(Node node) {
        if (null == node) return 0;
        return height(node.left) - height(node.right);
    }

    static Node inorderSuccessor(Node node) {
        Node current = node;
        while(null != current.left) current = current.left;
        return current;
    }

    static Node rightRotate(Node z) {
        Node y = z.left;
        Node T3 = y.right;

        y.right = z;
        z.left = T3;

        z.height = Math.max(height(z.left), height(z.right)) + 1;
        y.height = Math.max(height(y.left), height(y.right)) + 1;

        return y;
    }

    static Node leftRotate(Node z) {
        Node y = z.right;
        Node T3 = y.left;

        y.left = z;
        z.right = T3;

        z.height = Math.max(height(z.left), height(z.right))+1;
        y.height = Math.max(height(y.left), height(y.right))+1;

        return y;
    }

    // Return new root node after balancing
    static Node insertNode(Node node, int key) {
        // Perform the normal BST rotation
        if (null == node) return new Node(key);

        if (key < node.key)
            node.left = insertNode(node.left, key);
        else
            node.right = insertNode(node.right, key);

        // Update height of this ancestor node
        node.height = Math.max(height(node.left), height(node.right)) + 1;

        // Get the balance factor of this ancestor node to check whether this node became unbalanced
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node.left.key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node.right.key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node.left.key)
        {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node.right.key)
        {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        // return the (unchanged) node pointer 
        return node;
    }

    // Return new root node after balancing 
    static Node deleteNode(Node node, int key) {
        if(null == node) return node;

        if(key < node.key) node.left = deleteNode(node.left, key);
        else if(key > node.key) node.right = deleteNode(node.right, key);
        else {
            if(node.left == null || node.right == null) {
                Node temp = (null != node.left) ? node.left : node.right;
                if(temp == null) node = null;
                else node = temp;     // Copy the contents of the non-empty child
            } else {
                // Node with two children
                Node temp = inorderSuccessor(node.right);
                node.key = temp.key;

                node.right = deleteNode(node.right, temp.key);
            }
        }

        if(node == null) return node;

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        node.height = Math.max(height(node.left), height(node.right)) + 1;

        // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
        // this node became unbalanced)
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && getBalance(node.left) >= 0)
            return rightRotate(node);

        // Left Right Case
        if (balance > 1 && getBalance(node.left) < 0)
        {
            node.left =  leftRotate(node.left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node.right) <= 0)
            return leftRotate(node);

        // Right Left Case
        if (balance < -1 && getBalance(node.right) > 0)
        {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }

    static class Node {
        int key;
        Node left, right;
        int height;

        Node() {}
        Node(int key) {
            this.key = key;
            this.height = 0;
        }
    }
}

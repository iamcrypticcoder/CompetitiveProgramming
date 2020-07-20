package com.mahbub.algorithm;

/**
 * Created by mahbub on 6/21/17.
 */
public class Trie_Demo {

    public static void main(String[] args) {
        Trie trie = new Trie();

        // Insert test
        trie.insertKey("my");
        trie.insertKey("max");
        trie.insertKey("man");
        trie.insertKey("many");

        // Search test
        System.out.println("Search my: " + String.valueOf(trie.searchKey("my")));
        System.out.println("Search max: " + String.valueOf(trie.searchKey("max")));
        System.out.println("Search man: " + String.valueOf(trie.searchKey("man")));
        System.out.println("Search many: " + String.valueOf(trie.searchKey("many")));
        System.out.println();

        // Remove test
        System.out.println("Delete ma: " + String.valueOf(trie.removeKey("ma")));
        System.out.println("Delete man: " + String.valueOf(trie.removeKey("man")));
        System.out.println("Delete many: " + String.valueOf(trie.removeKey("many")));
        System.out.println();

        System.out.println("Search my: " + String.valueOf(trie.searchKey("my")));
        System.out.println("Search max: " + String.valueOf(trie.searchKey("max")));
        System.out.println("Search man: " + String.valueOf(trie.searchKey("man")));
        System.out.println("Search many: " + String.valueOf(trie.searchKey("many")));
        System.out.println();
    }

    static class Trie {

        private TrieNode root;
        private int keyCount;

        public Trie() {
            root = new TrieNode(false);
            keyCount = 0;
        }

        // Complexity: O(length of key)
        public boolean insertKey(String key) {
            TrieNode node = root;

            char[] charArr = key.toCharArray();
            for (char ch : charArr) {
                TrieNode child  = node.children.get(ch);
                if (null == child) {
                    child = new TrieNode();
                    child.parent = node;
                    node.children.put(ch, child);
                }
                node = child;
            }
            node.isKey = true;
            return true;
        }

        // Complexity: O(length of key * alphabet size)
        public boolean removeKey(String key) {
            TrieNode node = root;

            char[] charArr = key.toCharArray();
            for (char ch : charArr) {
                TrieNode child = node.children.get(ch);
                if (null == child) return false;
                node = child;
            }

            // If the given key isn't a key
            if(!node.isKey) return false;

            // if key node has any other child mark isLeaf == false and return
            if(childCount(node) > 0) {
                node.isKey = false;
                return true;
            }

            // Going bottom to top checking is current node has any child.
            // If no child exist current node should be null
            for(int i = charArr.length-1; i >= 0; i--) {
                if(childCount(node) > 0) break;
                TrieNode parent = node.parent;
                parent.children.remove(charArr[i]);
                node = parent;
            }
            return true;
        }

        // Complexity: O(length of key)
        public boolean searchKey(String key) {
            TrieNode node = root;

            char[] charArr = key.toCharArray();
            for (char ch : charArr) {
                TrieNode child = node.children.get(ch);
                if (null == child) return false;
                node = child;
            }

            return node.isKey;
        }

        private static int childCount(TrieNode node) {
            return node.children.size();
        }
    }

    static class TrieNode {
        TrieNode parent;
        Map<Character, TrieNode> children;
        boolean isKey;

        public TrieNode() {
            children = new HashMap<>();
        }

        public TrieNode(boolean isKey) {
            children = new HashMap<>();
            this.isKey = isKey;
        }
    }

    /*
    static class TrieNode {
        public static final int ALPHABET_SIZE = 26;

        TrieNode parent;
        TrieNode childs[];
        boolean isKey;

        public TrieNode() {
            childs = new TrieNode[ALPHABET_SIZE];
        }

        public TrieNode(boolean isKey) {
            childs = new TrieNode[ALPHABET_SIZE];
            this.isKey = isKey;
        }
    }
     */
}

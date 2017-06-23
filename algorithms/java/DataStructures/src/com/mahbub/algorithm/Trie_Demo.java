package com.mahbub.algorithm;

/**
 * Created by mahbub on 6/21/17.
 */
public class Trie_Demo {

    public static void main(String[] args) {
        MTrie trie = new MTrie();

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

    static class MTrie {
        public static final int ALPHABET_SIZE = 26;

        private TrieNode root;
        private int keyCount;

        public MTrie() {
            root = new TrieNode(false);
            keyCount = 0;
        }

        // Complexity: O(length of key)
        public boolean insertKey(String key) {
            int keyLength = key.length();
            TrieNode node = root;

            for(int i=0; i < keyLength; i++) {
                int value = charValue(key.charAt(i));
                if(null == node.childs[value]) node.childs[value] = new TrieNode();
                node.childs[value].parent = node;
                node = node.childs[value];
            }

            node.isLeaf = true;
            return true;
        }

        // Complexity: O(length of key * alphabet size)
        public boolean removeKey(String key) {
            int keyLength = key.length();
            TrieNode node = root;

            for(int i=0; i < keyLength; i++) {
                int value = charValue(key.charAt(i));
                if(null == node.childs[value]) return false;
                node = node.childs[value];
            }

            // If the given key isn't a key
            if(!node.isLeaf) return false;

            // if key node has any other child mark isLeaf == false and return
            if(childCount(node) > 0) {
                node.isLeaf = false;
                return true;
            }

            // Going bottom to top checking is current node has any child.
            // If no child exist current node should be null
            for(int i = keyLength-1; i >= 0; i--) {
                if(childCount(node) > 0) break;
                TrieNode parent = node.parent;
                parent.childs[charValue(key.charAt(i))] = null;
                node = parent;
            }
            return true;
        }

        // Complexity: O(length of key)
        public boolean searchKey(String key) {
            int keyLength = key.length();
            TrieNode node = root;

            for(int i=0; i < keyLength; i++) {
                int value = charValue(key.charAt(i));
                if(null == node.childs[value]) return false;
                node = node.childs[value];
            }

            return node.isLeaf;
        }

        private static int charValue(char ch) {
            return ch - 'a';
        }

        private static int childCount(TrieNode node) {
            int ret = 0;
            for(int i = 0; i < ALPHABET_SIZE; i++)
                ret += (null == node.childs[i] ? 0 : 1);
            return ret;
        }
    }

    static class TrieNode {
        TrieNode parent;
        TrieNode childs[];
        boolean isLeaf;

        public TrieNode() {
            childs = new TrieNode[MTrie.ALPHABET_SIZE];
        }

        public TrieNode(boolean isLeaf) {
            childs = new TrieNode[MTrie.ALPHABET_SIZE];
            this.isLeaf = isLeaf;
        }
    }
}

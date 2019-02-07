package com.mahbub.algorithm;

import java.util.HashMap;
import java.util.Map;

public class Trie_Demo_2 {

    public static void main(String[] args) {
        Trie trie = new Trie();

        // Insert test
        trie.insert("my");
        trie.insert("max");
        trie.insert("man");
        trie.insert("many");

        // Search test
        System.out.println("Search my: " + String.valueOf(trie.search("my")));
        System.out.println("Search max: " + String.valueOf(trie.search("max")));
        System.out.println("Search man: " + String.valueOf(trie.search("man")));
        System.out.println("Search many: " + String.valueOf(trie.search("many")));
        System.out.println();

        // Remove test
        System.out.println("Delete ma: " + String.valueOf(trie.remove("ma")));
        System.out.println("Delete man: " + String.valueOf(trie.remove("man")));
        System.out.println("Delete many: " + String.valueOf(trie.remove("many")));
        System.out.println();

        System.out.println("Search my: " + String.valueOf(trie.search("my")));
        System.out.println("Search max: " + String.valueOf(trie.search("max")));
        System.out.println("Search man: " + String.valueOf(trie.search("man")));
        System.out.println("Search many: " + String.valueOf(trie.search("many")));
        System.out.println();
    }

    static class Trie {
        private TrieNode root;

        public Trie() {
            root = new TrieNode(false);
        }

        // Complexity: O(length of key)
        public boolean insert(String word) {
            int keyLength = word.length();
            TrieNode node = root;

            for (Character ch : word.toCharArray()) {
                if(!node.children.containsKey(ch)) {
                    TrieNode t = new TrieNode();
                    t.parent = node;
                    node.children.put(ch, t);
                }
                node = node.children.get(ch);
            }

            node.isWord = true;
            return true;
        }

        // Complexity: O(length of key * alphabet size)
        public boolean remove(String word) {
            TrieNode node = searchPrefix(word);

            if (null == node || !node.isWord) return false;

            if (node.children.size() > 0) {
                node.isWord = false;
                return true;
            }

            // Going bottom to top checking is current node has any child.
            // If no child exist current node should be null
            for (int i = word.length()-1; i > 0; i--) {
                if (node.children.size() > 0) break;
                node = node.parent;
                node.children.remove(word.charAt(i));
            }

            return true;
        }

        public TrieNode searchPrefix(String prefix) {
            TrieNode node = root;

            for (Character ch : prefix.toCharArray()) {
                if (!node.children.containsKey(ch)) return null;
                node = node.children.get(ch);
            }
            return node;
        }

        // Complexity: O(length of key)
        public boolean search(String word) {
            TrieNode node = searchPrefix(word);
            return (null != node && node.isWord);
        }

        // Search from given node
        public boolean search(TrieNode node, String word) {
            for (Character ch : word.toCharArray()) {
                if (!node.children.containsKey(ch)) return false;
                node = node.children.get(ch);
            }
            return (null != node && node.isWord);
        }
    }

    static class TrieNode {
        TrieNode parent;
        Map<Character, TrieNode> children;
        boolean isWord;

        public TrieNode() {
            this(false);
        }

        public TrieNode(boolean isWord) {
            children = new HashMap<>();
            this.isWord = isWord;
        }
    }
}

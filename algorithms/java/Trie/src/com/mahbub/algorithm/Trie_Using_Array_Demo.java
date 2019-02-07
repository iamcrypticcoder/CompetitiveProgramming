package com.mahbub.algorithm;

import java.util.Arrays;

public class Trie_Using_Array_Demo {

    public static void main(String args[]) {
        Trie trie = new Trie();

        trie.insertKey("abcd");
        trie.insertKey("abxy");
        trie.insertKey("xy");
        trie.insertKey("xyz");

        System.out.println("Found: " + trie.searchKey("abcd"));
        System.out.println("Found: " + trie.searchKey("xyz"));
        System.out.println("Found: " + trie.searchKey("xy"));

        System.out.println("Removed: " + trie.removeKey("ab"));
        System.out.println("Removed: " + trie.removeKey("abcd"));
        System.out.println("Removed: " + trie.removeKey("abcd"));
        System.out.println("Removed: " + trie.removeKey("xy"));

    }

    static class Trie {
        public static final int MAXS = 500;
        public static final int MAXC = 26;

        int[][] trie;
        boolean[] isKey;
        int states;
        private int keyCount;

        public Trie() {
            trie = new int[MAXS][MAXC];
            for (int i = 0; i < MAXS; i++) Arrays.fill(trie[i], -1);
            states = 1;
            isKey = new boolean[MAXS];
            keyCount = 0;
        }

        // Complexity: O(length of key)
        public boolean insertKey(String key) {
            int keyLength = key.length();
            int currentState = 0;

            for (int i = 0; i < keyLength; i++) {
                int ch = key.charAt(i) - 'a';
                if (trie[currentState][ch] == -1) trie[currentState][ch] = states++;
                currentState = trie[currentState][ch];
            }

            isKey[currentState] = true;
            return true;
        }

        // Complexity: O(length of key * alphabet size)
        public boolean removeKey(String key) {
            int keyLength = key.length();
            int currentState = 0;

            for (int i = 0; i < keyLength; i++) {
                int ch = key.charAt(i) - 'a';
                if (trie[currentState][ch] == -1) return false;
                currentState = trie[currentState][ch];
            }

            if (!isKey[currentState]) return false;

            isKey[currentState] = false;
            return true;
        }

        // Complexity: O(length of key)
        public boolean searchKey(String key) {
            int keyLength = key.length();
            int currentState = 0;

            for (int i = 0; i < keyLength; i++) {
                int ch = key.charAt(i) - 'a';
                if (trie[currentState][ch] == -1) return false;
                currentState = trie[currentState][ch];
            }

            return isKey[currentState];
        }

        private int childCount(int state) {
            int ret = 0;
            for(int i = 0; i < MAXC; i++)
                ret += (trie[state][i] == -1) ? 0 : 1;
            return ret;
        }
    }
}

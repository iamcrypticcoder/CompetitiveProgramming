package com.mahbub.algorithm;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Refs:
 * Picture Diagram of below link:
 * https://www.semanticscholar.org/paper/Efficient-String-Matching%3A-An-Aid-to-Bibliographic-Aho-Corasick/3547ac839d02f6efe3f6f76a8289738a22528442?tab=abstract
 * Implementation overview:
 * https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/
 */
public class AhoCorasick_Demo {

    static final int MAXS = 500;
    static final int MAXC = 26;

    static int[] out;
    static int[] f;
    static int[][] g;

    static int buildMatchingMachine(String keys[]) {
        out = new int[MAXS];
        g = new int[MAXS][MAXC];
        for (int i = 0; i < MAXS; i++) Arrays.fill(g[i], -1);

        int states = 1;

        for (int i = 0; i < keys.length; i++) {
            String key = keys[i];
            int currentState = 0;

            for (int j = 0; j < key.length(); j++) {
                int ch = key.charAt(j) - 'a';
                if (g[currentState][ch] == -1) g[currentState][ch] = states++;
                currentState = g[currentState][ch];
            }

            out[currentState] |= (1 << i);
        }

        // Initialize values in fail function
        f = new int[MAXS];
        Arrays.fill(f, -1);

        Queue<Integer> q = new LinkedList<>();

        for (int ch = 0; ch < MAXC; ch++) {
            if (g[0][ch] != -1) {
                f[g[0][ch]] = 0;
                q.offer(g[0][ch]);
            } else {
                g[0][ch] = 0;
            }
        }

        while (!q.isEmpty()) {
            int state = q.poll();

            for (int ch = 0; ch < MAXC; ch++) {
                if (g[state][ch] != -1) {
                    // Find failure state of removed state
                    int failure = f[state];

                    // Find the deepest node labeled by proper
                    // suffix of string from root to current
                    // state.
                    while (g[failure][ch] == -1)
                        failure = f[failure];

                    failure = g[failure][ch];
                    f[g[state][ch]] = failure;

                    // Merge output values
                    out[g[state][ch]] |= out[failure];

                    // Insert the next level node (of Trie) in Queue
                    q.offer(g[state][ch]);
                }
            }
        }

        return states;
    }

    static int findNextState(int currentState, char nextInput) {
        int answer = currentState;

        int ch = nextInput - 'a';
        while (g[answer][ch] == -1)
            answer = f[answer];

        return g[answer][ch];
    }

    static void searchWords(String keys[], String text) {
        buildMatchingMachine(keys);

        int currentState = 0;

        for (int i = 0; i < text.length(); i++) {
            currentState = findNextState(currentState, text.charAt(i));

            if (out[currentState] == 0) continue;

            for (int j = 0; j < keys.length; j++) {
                if ((out[currentState] & (1 << j)) != 0) {
                    System.out.printf("Word %s appears from %d to %d\n", keys[j], i - keys[j].length() + 1, i);
                }
            }
        }
    }

    public static void main(String[] args) {
        String keys[] = new String[] {"he", "she", "his", "hers"};
        String text = "ashishers";

        searchWords(keys, text);
    }
}
package com.mahbub.algorithm;

public class UtilityMethods_Demo {


    // O(n)
    // Given two strings check are they anagram
    static boolean isAnagram(String s1, String s2) {
        if (s1.length() != s2.length()) return false;

        int freq[] = new int[128];      // For all ASCII
        for (int i = 0; i < s1.length(); i++)
            freq[s1.charAt(i)]++;

        for (int i = 0; i < s2.length(); i++) {
            freq[s2.charAt(i)]--;
            if (freq[s2.charAt(i)] < 0) return false;
        }
        return true;
    }

    // O(n)
    // Given a string check is it a permutation of a palindrome,
    // Or, is it possible to make the string into a palindrome without modifying it.
    static boolean isPermutationOfPalindrome(String s) {
        int oddCount = 0;
        int freq[] = new int[26];
        for (int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            freq[idx]++;
            if (freq[idx] % 2 == 1) oddCount++;
            else oddCount--;
        }
        return (oddCount <= 1);
    }

    public static void main(String[] args) {
        System.out.println(isAnagram("abab", "aabb"));
        System.out.println(isPermutationOfPalindrome("ababac"));
    }
}

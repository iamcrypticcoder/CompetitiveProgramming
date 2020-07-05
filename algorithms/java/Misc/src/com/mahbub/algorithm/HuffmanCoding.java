package com.mahbub.algorithm;

import java.util.*;

public class HuffmanCoding {

    public static void main(String[] args) {
        String str = "I am cryptic coder";

        HuffmanNode root = buildTree(buildFreq(str));
        StringBuilder sb = new StringBuilder();
        Map<Character, String> codeMap = new HashMap<>();
        generateCodes(root, sb, codeMap);
        String encodedStr = encode(codeMap, str);
        System.out.println("Encoded String: " + encodedStr);
        String decodedStr = decode(root, encodedStr);
        System.out.println("Decoded String: " + decodedStr);
    }

    static class CharInfo {
        char ch;
        int freq;
        public CharInfo(char ch, int freq) {
            this.ch = ch;
            this.freq = freq;
        }
    }

    static class HuffmanNode {
        char ch;
        int data;
        HuffmanNode left, right;
        public HuffmanNode(char ch, int data) {
            this.ch = ch;
            this.data = data;
        }
    }

    static List<CharInfo> buildFreq(String s) {
        List<CharInfo> ret = new ArrayList<>();
        Map<Character, Integer> freq = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        for(Map.Entry<Character, Integer> entry : freq.entrySet())
            ret.add(new CharInfo(entry.getKey(), entry.getValue()));

        return ret;
    }

    static HuffmanNode buildTree(List<CharInfo> charInfoList) {
        PriorityQueue<HuffmanNode> q = new PriorityQueue<>(charInfoList.size(), (o1, o2) -> o1.data - o2.data);
        for (CharInfo charInfo : charInfoList) {
            q.add(new HuffmanNode(charInfo.ch, charInfo.freq));
        }

        HuffmanNode root = null;

        while (q.size() > 1) {
            HuffmanNode x = q.peek();
            q.poll();
            HuffmanNode y = q.peek();
            q.poll();

            HuffmanNode n = new HuffmanNode('#', x.data + y.data);
            n.left = x;
            n.right = y;

            root = n;

            q.add(n);
        }
        return root;
    }

    static void generateCodes(HuffmanNode node, StringBuilder sb, Map<Character, String> codeMap) {
        if (null == node) return;

        if (null == node.left && null == node.right) {
            codeMap.put(node.ch, sb.toString());
            return;
        }

        generateCodes(node.left, sb.append('0'), codeMap);
        if (sb.length() > 0) sb.deleteCharAt(sb.length()-1);
        generateCodes(node.right, sb.append('1'), codeMap);
        if (sb.length() > 0) sb.deleteCharAt(sb.length()-1);
    }

    static String encode(Map<Character, String> codeMap, String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++)
            sb.append(codeMap.get(str.charAt(i)));
        return sb.toString();
    }

    static String decode(HuffmanNode root, String encodedStr) {
        StringBuilder sb = new StringBuilder();

        HuffmanNode node = root;
        for (int i = 0; i < encodedStr.length(); i++) {
            if (encodedStr.charAt(i) == '0')  node = node.left;
            else node = node.right;

            if (null == node.left && null == node.right)  {
                sb.append(node.ch);
                node = root;
            }
        }
        return sb.toString();
    }
}

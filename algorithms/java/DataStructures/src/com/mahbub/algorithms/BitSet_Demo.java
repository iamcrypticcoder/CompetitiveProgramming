package com.mahbub.algorithms;

import java.util.BitSet;

public class BitSet_Demo {

    static class MyBitSet {
        int[] words;

        MyBitSet(int nbit) {
            words = new int[(nbit >> 5) + 1];
        }

        boolean get(int pos) {
            int wordNumber = (pos >> 5);    // Divide by 32
            int bitNumber = (pos & 0x1F);   // Remainder of 32
            return (words[wordNumber] & (1 << bitNumber)) != 0;
        }

        void set(int pos) {
            int wordNumber = (pos >> 5);
            int bitNumber = (pos & 0x1F);   // Remainder of 32
            words[wordNumber] |= (1 << bitNumber);
        }
    }

    static void myBitSetDemo() {
        MyBitSet set1 = new MyBitSet(10);
        set1.set(7);
        set1.set(8);

        System.out.println("My BitSet1: ");
        for(int i = 0; i < 10; i++) {
            System.out.print(set1.get(i)? "1 ": "0 ");
        }
    }

    static void builtinBitSetDemo() {
        // Built-in bitset
        BitSet set1 = new BitSet(10);
        BitSet set2 = new BitSet(10);

        for (int i = 0; i < 10; i++) {
            if((i % 2) == 0) set1.set(i);
            if((i % 3) != 0) set2.set(i);
        }

        System.out.println("Set1: ");
        for(int i = 0; i < 10; i++) {
            System.out.print(set1.get(i)? "1 ": "0 ");
        }
        System.out.println();

        System.out.println("Set2: ");
        for(int i = 0; i < 10; i++) {
            System.out.print(set2.get(i)? "1 ": "0 ");
        }

        System.out.println();

        set1.and(set2);

        System.out.println("b1 = b1 AND b2\nSet1: ");

        for(int i = 0; i < 10; i++) {
            System.out.print(set1.get(i)? "1 ": "0 ");
        }

        System.out.println();
        System.out.println("Set2: ");

        for(int i = 0; i < 10; i++) {
            System.out.print(set2.get(i)? "1 ": "0 ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        builtinBitSetDemo();

        myBitSetDemo();
    }
}

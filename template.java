package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class A {
    static final double EPS         = 1e-9f;
    static final double TO_DEG      = 57.29577951;

    // UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
    static int[] dx = { -1, 0, 1, 0, -1, 1,  1, -1 };
    static int[] dy = {  0, 1, 0,-1,  1, 1, -1, -1 };

    // Represents all moves of a knight in a chessboard
    static int[] dxKnightMove = { -1, -2, -2, -1,  1,  2, 2, 1 };
    static int[] dyKnightMove = {  2,  1, -1, -2, -2, -1, 1, 2 };

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static final int MAX = 100000;

    // Bitwise Operations
    public static final int ALL_BITS = (1 << 31) - 1;
    public static int NEG_BITS(int n) {
        return n ^ ALL_BITS;
    }
    public static boolean TEST_BIT(int n, int i) {
        return (n & (1 << i)) != 0;
    }
    public static int ON_BIT(int n, int i) {
        return n | (1 << i);
    }
    public static int OFF_BIT(int n, int i) {
        return n & NEG_BITS(1 << i);
    }
    public static int TOGGLE_BIT(int n, int i) {
        return n ^ (1 << 31);
    }
    public static boolean IS_POWER_TWO(int n) {
        return (n & (n - 1)) == 0;
    }
    public static int OFF_LOWEST_SET_BIT(int n) {
        return n & (n - 1);
    }
    public static int LOWEST_SET_BIT_POSITION(int n) {
        return n ^ (n & (n - 1));
    }
    public static int DEVIDE_BY_POWER_TWO(int n, int p) {
        return n & (p - 1);
    }
    public static int bitCountRange(int N, int l, int r) {
        int mask = ((1 << (r+1)) - 1) ^ ((1 << l) - 1);
        return Integer.bitCount(N & mask);
    }
    public static int getLeftmostBit(int N) {
        int m = 0;
        while (N > 1) {
            N = N >> 1;
            m++;
        }
        return m;
    }
    
    static long sqr(int x) { return x*x; }

    static int gcd(int a, int b) {
        while (b != 0) {
            b = b ^ a;
            a = a ^ b;
            b = b ^ a;
            a = a % b;
        }
        return a;
    }

    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    
    public static void main(String[] args) {
        Scanner scanner = inputFromSystem();

    }

    static Scanner inputFromFile() {
        try { return new Scanner(new FileInputStream("input.txt")); }
        catch (FileNotFoundException e) { e.printStackTrace(); }
        return null;
    }

    static Scanner inputFromSystem() {
        return new Scanner(System.in);
    }
}


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


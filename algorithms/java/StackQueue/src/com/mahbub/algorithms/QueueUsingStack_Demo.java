package com.mahbub.algorithms;

import java.util.LinkedList;
import java.util.Stack;

// Ref: http://www.geeksforgeeks.org/?p=5009
public class QueueUsingStack_Demo {

    public static void main(String[] args) {
        QueueUsingStack q = new QueueUsingStack();
        q.push(1);
        q.push(2);
        q.push(3);

        System.out.println(q.pop());
        System.out.println(q.pop());
        q.push(4);
        System.out.println(q.pop());
        System.out.println(q.pop());

        QueueUsingStack q2 = new QueueUsingStack();
        q2.push(1);
        q2.push(2);
        q2.push(3);

        System.out.println(q2.pop());
        System.out.println(q2.pop());
        q2.push(4);
        System.out.println(q2.pop());
        System.out.println(q2.pop());
    }

    static class QueueUsingStack {
        Stack<Integer> s1, s2;

        public QueueUsingStack() {
            s1 = new Stack<>();
            s2 = new Stack<>();
        }

        // Complexity: O(1)
        public void push(Integer x) {
            s1.push(x);
        }

        // Complexity: O(n)
        public Integer pop() {
            if (s1.empty()) return null;

            while (!s1.empty()) {
                s2.push(s1.pop());
            }

            Integer ret = s2.pop();

            while (!s2.empty()) {
                s1.push(s2.pop());
            }

            return ret;
        }

        // Complexity: O(n)
        public void push2(Integer x) {
            while (!s1.empty()) {
                s2.push(s1.pop());
            }

            s1.push(x);

            while (!s2.empty()) {
                s1.push(s2.pop());
            }
        }

        // Complexity: O(1)
        public Integer pop2() {
            return s1.pop();
        }
    }
}

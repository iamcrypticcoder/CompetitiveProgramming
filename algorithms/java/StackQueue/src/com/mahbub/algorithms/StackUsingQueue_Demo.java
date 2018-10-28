package com.mahbub.algorithms;


import java.util.LinkedList;
import java.util.Queue;

public class StackUsingQueue_Demo {

    public static void main(String[] args) {
        StackUsingQueue s = new StackUsingQueue();
        s.push(1);
        s.push(2);
        s.push(3);

        System.out.println(s.pop());
        System.out.println(s.pop());
        s.push(4);
        System.out.println(s.pop());
        System.out.println(s.pop());
    }

    static class StackUsingQueue {
        Queue<Integer> q1, q2;

        public StackUsingQueue() {
            q1 = new LinkedList<>();
            q2 = new LinkedList<>();
        }

        // Complexity: O(1)
        public void push(Integer x) {
            q1.offer(x);
        }

        // Complexity: O(n)
        public Integer pop() {
            if (q1.isEmpty()) return null;

            while (q1.size() > 1) {
                q2.offer(q1.poll());
            }

            Integer ret = q1.poll();

            // Add all elements back to q1, which is done by assigning
            q1 = q2;
            // q2 should be empty again.
            q2 = new LinkedList<>();

            return ret;
        }

        // Complexity: O(n)
        public void push2(Integer x) {
            q1.offer(x);
        }
    }
}

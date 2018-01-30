package com.mahbub.algorithms;

/**
 * Created by mahbub on 6/21/17.
 */
public class Stack_Demo {

    public static void main(String[] args) {
        Stack<String> stack = new Stack<>();
        stack.push("Mahbub");
        stack.push("Shareen");
        stack.push("Safwat");

        System.out.println(stack.itemCount);
        System.out.println(stack.isEmpty());
        System.out.println(stack.top());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.isEmpty());

    }

    public static class Stack<T> {
        private Node<T> top;
        public int itemCount;

        Stack() {
            top = null;
            itemCount = 0;
        }

        public void push(T item) {
            itemCount++;
            if(null == top) {
                top = new Node<T>(item);
                return;
            }
            Node<T> node  = new Node<T>(item);
            node.next = top;
            top = node;
        }

        public T pop() {
            if(null == top) return null;
            T item = top.data;
            top = top.next;
            itemCount--;
            return item;
        }

        public T top() {
            return top.data;
        }

        public boolean isEmpty() {
            return (null == top);
        }

        // Stack requires only singly linked list
        static class Node<T> {
            T data;
            Node<T> next;

            Node() {}
            Node(T data) { this.data = data; }
        }
    }
}

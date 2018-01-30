package com.mahbub.algorithms;

/**
 * Created by mahbub on 6/21/17.
 */
public class Queue_Demo {

    public static void main(String[] args) {


    }

    public static class Queue<T> {
        private Node<T> first, last;
        public int itemCount;

        Queue() {
            first = last = null;
            itemCount = 0;
        }

        public void push(T item) {
            itemCount++;
            if (null == first) {
                first = last = new Node<T>(item);
                return;
            }
            last.next = new Node<T>(item);
            last = last.next;
        }

        public T pop() {
            if(null == first) return null;
            itemCount--;
            T item = first.data;
            first = first.next;
            return item;
        }

        public T front() {
            return first.data;
        }

        public boolean isEmpty() {
            return (null == first);
        }


        static class Node<T> {
            T data;
            Node<T> next;

            Node() {}
            Node(T data) { this.data = data; }
        }
    }
}

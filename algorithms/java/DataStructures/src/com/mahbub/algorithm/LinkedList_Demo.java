package com.mahbub.algorithm;

import java.util.Arrays;

public class LinkedList_Demo {

    public static void main(String[] args) {
        LinkedList linkedList = new LinkedList();
        linkedList.insertAtFirst(20);
        linkedList.insertAtFirst(10);
        linkedList.insertAtLast(30);
        linkedList.insertAtLast(40);
        linkedList.insertAtPos(25, 2);
        linkedList.insertAtPos(50, 5);
        System.out.println(Arrays.toString(linkedList.asArray()));

        linkedList.removeAtFirst();
        System.out.println(Arrays.toString(linkedList.asArray()));

        linkedList.removeAtLast();
        System.out.println(Arrays.toString(linkedList.asArray()));

        linkedList.removeAtPos(2);
        System.out.println(Arrays.toString(linkedList.asArray()));
    }

    static class LinkedList {
        Node head, tail;
        int size;

        public LinkedList() {
            head = tail = null;
            size = 0;
        }

        // Complexity: O(1)
        public void insertAtFirst(int value) {
            Node newNode = new Node(value);
            if(null == head) {
                head = tail = newNode;
                size++;
                return;
            }
            newNode.next = head;
            head = newNode;
            size++;
        }

        // Complexity: O(1)
        public void insertAtLast(int value) {
            Node newNode = new Node(value);
            if(null == tail) {
                head = tail = newNode;
                size++;
                return;
            }
            tail.next = newNode;
            tail = newNode;
            size++;
        }

        // Complexity: O(pos)
        // Position starts from 0
        public void insertAtPos(int value, int pos) {
            Node newNode = new Node(value);
            if(pos == 0) {
                newNode.next = head;
                head = newNode;
                size++;
                return;
            }
            pos = pos - 1;
            Node ptr = head;
            while(pos > 0 && null != ptr) {
                ptr = ptr.next;
                pos--;
            }
            Node temp = ptr.next;
            ptr.next = newNode;
            newNode.next = temp;
            size++;
        }

        // Complexity: O(1)
        public boolean removeAtFirst() {
            if(size == 0) return false;
            head = head.next;
            size--;
            return true;
        }

        // Complexity: O(size)
        public boolean removeAtLast() {
            if(size == 0) return false;
            if(size == 1) {
                head = tail = null;
                size = 0;
                return true;
            }
            Node ptr = head;
            while(null != ptr.next.next) {
                ptr = ptr.next;
            }
            ptr.next = null;
            tail = ptr;
            size--;
            return true;
        }

        // Complexity: O(size)
        // Position starts from 0
        public boolean removeAtPos(int pos) {
            if(pos > size-1) return false;
            if(pos == 0) {
                head = head.next;
                size--;
                return true;
            }
            pos = pos - 1;
            Node ptr = head;
            while(pos > 0 && null != ptr) {
                ptr = ptr.next;
                pos--;
            }
            ptr.next = ptr.next.next;
            size--;
            return true;
        }

        // Complexity: O(size)
        public int[] asArray() {
            int[] arr = new int[size];
            Node ptr = head;
            int i = 0;
            while(null != ptr) {
                arr[i++] = ptr.data;
                ptr = ptr.next;
            }
            return arr;
        }
    }

    static class Node {
        protected int data;
        protected Node next;

        public Node() {
            data = 0;
            next = null;
        }

        public Node(int d) {
            data = d;
            next = null;
        }
    }
}

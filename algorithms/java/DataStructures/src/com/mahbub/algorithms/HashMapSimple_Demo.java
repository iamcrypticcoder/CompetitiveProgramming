package com.mahbub.algorithms;

public class HashMapSimple_Demo {

    public static void main(String args[]) {
        HashMapSimple hashMapSimple = new HashMapSimple();
        hashMapSimple.put("email", "mahbub.kuet@gmail.com");
        hashMapSimple.put("username", "iamcrypticcoder");
        hashMapSimple.put("designation", "Sr. Software Engineer");

        // Replace current value
        hashMapSimple.put("username", "another_username");

        System.out.println("email: " + hashMapSimple.get("email"));
        System.out.println("username: " + hashMapSimple.get("username"));
        System.out.println("designation: " + hashMapSimple.get("designation"));
    }


    static class HashMapSimple {
        public static final int BIG_PRIME = 101;
        public static final int BUCKET_SIZE = 8;
        Node[] buckets;

        public HashMapSimple() {
            buckets = new Node[BUCKET_SIZE];
        }

        // Complexity: O(1) ~ O(n)
        public boolean put(String key, String value) {
            int hash = calcHash(key);
            int bucketIndex = hash % BUCKET_SIZE;

            // No node available in this bucket
            if (null == buckets[bucketIndex]) {
                buckets[bucketIndex] = new Node(key, value);
                return true;
            }

            Node current = buckets[bucketIndex];

            // If duplicate key found in the first node replace by new value
            if (current.key.equals(key)) {
                current.value = value;
                return true;
            }

            // If duplicate key found in any node replace by new value
            boolean isReplaced = false;
            while (null != current.next) {
                if (current.key.equals(key)) {
                    current.value = value;
                    isReplaced = true;
                    break;
                }
                current = current.next;
            }

            // If not replaced add new node
            if (false == isReplaced)
                current.next = new Node(key, value);

            return true;
        }

        // Complexity: O(1) ~ O(n)
        public String get(String key) {
            int hash = calcHash(key);
            int bucketIndex = hash % BUCKET_SIZE;

            Node current = buckets[bucketIndex];

            while (null != current.next) {
                if (current.key.equals(key)) break;
            }

            return current.value;
        }

        // Complexity: O(1) ~ O(n)
        public boolean remove(String key) {
            int hash = calcHash(key);
            int bucketIndex = hash % BUCKET_SIZE;

            Node current = buckets[bucketIndex];
            Node prev = current;

            while (null != current.next) {
                if (current.key.equals(key)) break;
                prev = current;
                current = current.next;
            }

            // If matched to first node of linked list
            if (prev == current) {
                buckets[bucketIndex] = null;
                return true;
            }

            prev.next = current.next;
            return true;
        }

        private int calcHash(String str) {
            int sum = 0;
            for (int i=0; i < str.length(); i++)
                sum = (sum + (int)str.charAt(i)) % BIG_PRIME;
            return sum % BIG_PRIME;
        }
    }

    static class Node {
        String key, value;
        Node next;

        public Node(String key, String value) {
            this.key = key;
            this.value = value;
        }
    }
}

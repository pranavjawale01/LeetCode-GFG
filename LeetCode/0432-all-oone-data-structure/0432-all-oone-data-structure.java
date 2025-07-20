class AllOne {
    class Node {
        int count;
        Set<String> keys;
        Node prev, next;

        Node(int count) {
            this.count = count;
            this.keys = new HashSet<>();
        }
    }

    private Map<String, Node> keyMap;
    private Node head, tail;

    public AllOne() {
        keyMap = new HashMap<>();
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
    }

    private void addNodeAfter(Node prevNode, Node newNode) {
        newNode.next = prevNode.next;
        newNode.prev = prevNode;
        prevNode.next.prev = newNode;
        prevNode.next = newNode;
    }

    private void removeNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public void inc(String key) {
        if (!keyMap.containsKey(key)) {
            if (head.next == tail || head.next.count != 1) {
                addNodeAfter(head, new Node(1));
            }
            head.next.keys.add(key);
            keyMap.put(key, head.next);
        } else {
            Node curr = keyMap.get(key);
            int currCount = curr.count;
            curr.keys.remove(key);
            if (curr.next == tail || curr.next.count != currCount + 1) {
                addNodeAfter(curr, new Node(currCount + 1));
            }
            curr.next.keys.add(key);
            keyMap.put(key, curr.next);
            if (curr.keys.isEmpty()) {
                removeNode(curr);
            }
        }
    }

    public void dec(String key) {
        if (!keyMap.containsKey(key)) return;

        Node curr = keyMap.get(key);
        int currCount = curr.count;
        curr.keys.remove(key);

        if (currCount == 1) {
            keyMap.remove(key);
        } else {
            if (curr.prev == head || curr.prev.count != currCount - 1) {
                addNodeAfter(curr.prev, new Node(currCount - 1));
            }
            curr.prev.keys.add(key);
            keyMap.put(key, curr.prev);
        }

        if (curr.keys.isEmpty()) {
            removeNode(curr);
        }
    }

    public String getMaxKey() {
        if (tail.prev == head) {
            return "";
        }
        return tail.prev.keys.iterator().next();
    }

    public String getMinKey() {
        if (head.next == tail) {
            return "";
        }
        return head.next.keys.iterator().next();
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */











 // class AllOne {
//     private Map<String, Integer> countMap;
//     private TreeMap<Integer, Set<String>> countSet;

//     public AllOne() {
//         countMap = new HashMap<>();
//         countSet = new TreeMap<>();
//     }
    
//     public void inc(String key) {
//         int count = countMap.getOrDefault(key, 0);
//         countMap.put(key, count + 1);
        
//         if (count > 0) {
//             countSet.get(count).remove(key);
//             if (countSet.get(count).isEmpty()) {
//                 countSet.remove(count);
//             }
//         }
        
//         countSet.putIfAbsent(count + 1, new HashSet<>());
//         countSet.get(count + 1).add(key);
//     }
    
//     public void dec(String key) {
//         int count = countMap.get(key);
//         countSet.get(count).remove(key);
//         if (countSet.get(count).isEmpty()) {
//             countSet.remove(count);
//         }
        
//         if (count == 1) {
//             countMap.remove(key);
//         } else {
//             countMap.put(key, count - 1);
//             countSet.putIfAbsent(count - 1, new HashSet<>());
//             countSet.get(count - 1).add(key);
//         }
//     }
    
//     public String getMaxKey() {
//         return countSet.isEmpty() ? "" : countSet.lastEntry().getValue().iterator().next();
//     }
    
//     public String getMinKey() {
//         return countSet.isEmpty() ? "" : countSet.firstEntry().getValue().iterator().next();
//     }
// }

// /**
//  * Your AllOne object will be instantiated and called as such:
//  * AllOne obj = new AllOne();
//  * obj.inc(key);
//  * obj.dec(key);
//  * String param_3 = obj.getMaxKey();
//  * String param_4 = obj.getMinKey();
//  */
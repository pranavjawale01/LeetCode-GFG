/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node temp = head;
        Map<Node, Node> mp = new HashMap<>();
        while (temp != null) {
            Node newNode = new Node(temp.val);
            mp.put(temp, newNode);
            temp = temp.next;
        }
        temp = head;
        while (temp != null) {
            Node copyNode = mp.get(temp);
            copyNode.next = mp.get(temp.next);
            copyNode.random = mp.get(temp.random);
            temp = temp.next;
        }
        return mp.get(head);
    }
}
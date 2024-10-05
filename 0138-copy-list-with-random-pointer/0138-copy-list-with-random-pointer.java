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
        if (head == null) {
            return null;
        }

        Node curr = head;
        while (curr != null) {
            Node copy = new Node(curr.val);
            copy.next = curr.next;
            curr.next = copy;
            curr = copy.next;
        }

        curr = head;
        while (curr != null) {
            if (curr.random != null) {
                curr.next.random = curr.random.next;
            }
            curr = curr.next.next;
        }

        curr = head;
        Node newHead = head.next;
        Node copy = null;
        while (curr != null) {
            copy = curr.next;
            curr.next = copy.next;
            if (copy.next != null) {
                copy.next = copy.next.next;
            }
            curr = curr.next;
        }

        return newHead;
    }
}









// class Solution {
//     public Node copyRandomList(Node head) {
//         Node temp = head;
//         Map<Node, Node> mp = new HashMap<>();
//         while (temp != null) {
//             Node newNode = new Node(temp.val);
//             mp.put(temp, newNode);
//             temp = temp.next;
//         }
//         temp = head;
//         while (temp != null) {
//             Node copyNode = mp.get(temp);
//             copyNode.next = mp.get(temp.next);
//             copyNode.random = mp.get(temp.random);
//             temp = temp.next;
//         }
//         return mp.get(head);
//     }
// }
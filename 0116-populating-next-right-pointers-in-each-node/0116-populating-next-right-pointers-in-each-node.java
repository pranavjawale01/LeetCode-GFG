/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Node cur = root;
        Node nxt = (root != null) ? root.left : null;
        
        while (cur != null && nxt != null) {
            cur.left.next = cur.right;
            
            if (cur.next != null) {
                cur.right.next = cur.next.left;
            }
            
            cur = cur.next;
            
            if (cur == null) {
                cur = nxt;
                nxt = cur.left;
            }
        }
        
        return root;
    }
}
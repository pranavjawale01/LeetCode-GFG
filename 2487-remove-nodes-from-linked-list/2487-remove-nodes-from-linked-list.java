/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode reverse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode last = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return last;
    }
    public ListNode removeNodes(ListNode head) {
        head = reverse(head);
        int maxNode = -1;
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            maxNode = Math.max(maxNode, curr.val);
            if (curr.val < maxNode) {
                prev.next = curr.next;
                ListNode temp = curr;
                curr = curr.next;
                temp = null;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }
        return reverse(head);
    }
}
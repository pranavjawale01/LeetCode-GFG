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
    private int gcd(int a, int b) {
        while (a != 0) {
            int temp = a;
            a = b % a;
            b = temp;
        }
        return b;
    }
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode temp = head;
        while (temp != null && temp.next != null) {
            int a = temp.val;
            int b = temp.next.val;
            int gcd = gcd(a, b);
            ListNode newNode = new ListNode(gcd);
            newNode.next = temp.next;
            temp.next = newNode;
            temp = newNode.next;
        }
        return head;
    }
}
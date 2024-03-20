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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode left = null, right = list1;
        for (int i = 0; i <= b; i++) {
            if (i == a - 1) {
                left = right;
            }
            right = right.next;
        }
        left.next = list2;
        ListNode temp = list2;
        while (temp != null && temp.next != null) {
            temp = temp.next;
        }
        temp.next = right;
        return list1;
    }
}
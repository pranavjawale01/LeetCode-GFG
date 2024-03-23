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
    public void reorderList(ListNode head) {
        List<Integer> arr = new ArrayList<>();
        ListNode temp = head;
        while (temp != null) {
            arr.add(temp.val);
            temp = temp.next;
        }
        int n = arr.size();
        temp = head;
        int i = 0;
        while (temp != null && temp.next != null) {
            temp.val = arr.get(i);
            temp.next.val = arr.get(n - i - 1);
            temp = temp.next.next;
            i++;
        }
        if (n % 2 != 0) {
            temp.val = arr.get(n / 2);
        }
    }
}
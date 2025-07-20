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
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        Map<Integer, ListNode> mp = new HashMap<>();
        mp.put(0, dummy);
        int sum = 0;

        while (head != null) {
            sum += head.val;
            if (mp.containsKey(sum)) {
                int pSum = sum;
                ListNode start = mp.get(sum);
                ListNode temp  = start;
                while (temp != head) {
                    temp = temp.next;
                    pSum += temp.val;
                    if (temp != head) {
                        mp.remove(pSum);
                    }
                }
                start.next = head.next;
            } else {
                mp.put(sum, head);
            }
            head = head.next;
        }
        return dummy.next;
    }
}
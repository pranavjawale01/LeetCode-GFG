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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode prev = head;
        ListNode curr = head.next;
        int currPos = 1;
        int prevPos = 0;
        int firstPos = 0;
        int minDist = Integer.MAX_VALUE;
        while (curr != null && curr.next != null) {
            if ((curr.val < prev.val && curr.val < curr.next.val) || (curr.val > prev.val && curr.val > curr.next.val)) {
                if (prevPos == 0) {
                    prevPos = currPos;
                    firstPos = currPos;
                } else {
                    minDist = Math.min(minDist, currPos - prevPos);
                    prevPos = currPos;
                }
            }
            currPos++;
            prev = curr;
            curr = curr.next;
        }
        if (minDist == Integer.MAX_VALUE) {
            return new int[]{-1, -1};
        }
        return new int[]{minDist, prevPos - firstPos};
    }
}
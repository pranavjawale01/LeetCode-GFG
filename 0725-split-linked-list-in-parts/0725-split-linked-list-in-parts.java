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
    public ListNode[] splitListToParts(ListNode head, int k) {
        int len = 0;
        ListNode temp = head;
        while (temp != null) {
            temp = temp.next;
            len++;
        }

        int partSize = len / k;
        int extraNodes = len % k;

        ListNode[] result = new ListNode[k];
        temp = head;

        for (int i = 0; i < k; i++) {
            if (temp == null) break;
            result[i] = temp;

            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;

            for (int j = 1; j < currentPartSize; j++) {
                temp = temp.next;
            }

            ListNode nextPart = temp.next;
            temp.next = null;
            temp = nextPart;
        }

        return result;
    }
}
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode result = new ListNode(0);
        result.next = head;
        ListNode prevGrpEnd = result;
        ListNode curr = head;
        int length = 0;
        while(head != null)
        {
            length++;
            head = head.next;
        }
        head = result.next;
        for(int i=0;i<length/k;++i)
        {
            ListNode grpStart = prevGrpEnd.next;
            ListNode grpEnd = grpStart;
            ListNode next = null;
            for(int j=0;j<k;j++)
            {
                next = curr.next;
                curr.next = grpStart;
                grpStart = curr;
                curr = next;
            }
            prevGrpEnd.next = grpStart;
            grpEnd.next = curr;
            prevGrpEnd = grpEnd;
        }
        return result.next;
    }
}
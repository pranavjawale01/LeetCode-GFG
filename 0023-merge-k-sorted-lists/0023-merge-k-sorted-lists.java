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
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> q = new PriorityQueue<ListNode>((a,b)->a.val - b.val);
        for(ListNode l: lists) {
            if(l != null) {
                q.add(l);
            }
        }
        ListNode result = new ListNode(-1);
        ListNode ptr = result;
        while(!q.isEmpty()) {
            ptr.next = q.poll();
            ptr = ptr.next;
            if(ptr.next != null) {
                q.add(ptr.next);
            }
        }
        return result.next;
    }
}
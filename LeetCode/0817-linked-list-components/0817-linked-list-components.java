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
    public int numComponents(ListNode head, int[] nums) {
        int count = 0;
        Set<Integer> st = new HashSet<>();
        for (int num : nums) {
            st.add(num);
        }
        while (head != null) {
            boolean flag = false;
            while (head != null && st.contains(head.val)) {
                flag = true;
                head = head.next;
            }
            if (flag) {
                count++;
            }
            if (head != null) {
                head = head.next;
            }
        }
        return count;
    }
}
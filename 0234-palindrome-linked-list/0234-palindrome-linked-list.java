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

// using arraylist
class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> temp = new ArrayList<>();
        ListNode curr = head;
        while (curr != null) {
            temp.add(curr.val);
            curr = curr.next;
        }
        int i = 0, j = temp.size() - 1;
        while (i < j) {
            if (!temp.get(i).equals(temp.get(j))) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
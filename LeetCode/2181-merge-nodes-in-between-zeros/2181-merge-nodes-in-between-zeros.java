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
    public ListNode mergeNodes(ListNode head) {
        head = head.next;
        if (head == null) {
            return head;
        }
        ListNode temp = head;
        int sum = 0;
        while (temp != null && temp.val != 0) {
            sum += temp.val;
            temp = temp.next;
        }
        head.val = sum;
        head.next = mergeNodes(temp);
        return head;
    }
}








// /**
//  * Definition for singly-linked list.
//  * public class ListNode {
//  *     int val;
//  *     ListNode next;
//  *     ListNode() {}
//  *     ListNode(int val) { this.val = val; }
//  *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
//  * }
//  */
// class Solution {
//     public ListNode mergeNodes(ListNode head) {
//         ListNode ans = new ListNode(0);
//         ListNode temp = ans;
//         int sum = 0;
//         head = head.next;
//         while (head != null) {
//             if (head.val == 0) {
//                 temp.next = new ListNode(sum);
//                 temp = temp.next;
//                 sum = 0;
//             } else {
//                 sum += head.val;
//             }
//             head = head.next;
//         }
//         return ans.next;
//     }
// }
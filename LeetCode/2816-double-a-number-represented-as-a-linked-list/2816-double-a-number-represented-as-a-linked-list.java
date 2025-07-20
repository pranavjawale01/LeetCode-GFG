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
    public ListNode doubleIt(ListNode head) {
        if (head.val >= 5) {
            ListNode newHead = new ListNode(0);
            newHead.next = head;
            head = newHead;
        }
        ListNode curr = head;
        ListNode prev = null;
        while (curr != null) {
            int newVal = curr.val * 2;
            if (newVal < 10) {
                curr.val = newVal;
            } else if (prev != null) {
                curr.val = newVal % 10;
                prev.val += 1;
            } else {
                ListNode newHead = new ListNode(1);
                newHead.next = curr;
                curr.val = newVal % 10;
                head = newHead;
            }
            prev = curr;
            curr = curr.next;
        }
        return head;
    }
}


// class Solution {
//     public ListNode doubleIt(ListNode head) {
//         ListNode curr = head;
//         ListNode prev = null;

//         while (curr != null) {
//             int newVal = curr.val * 2;
//             if (newVal < 10) {
//                 curr.val = newVal;
//             } else if (prev != null) {
//                 curr.val = newVal % 10;
//                 prev.val += 1;
//             } else {
//                 ListNode newHead = new ListNode(1);
//                 newHead.next = curr;
//                 curr.val = newVal % 10;
//                 head = newHead;
//             }
//             prev = curr;
//             curr = curr.next;
//         }
//         return head;
//     }
// }




// class Solution {
//     public int solve(ListNode head) {
//         if (head == null) {
//             return 0;
//         }
//         int carry = solve(head.next);
//         int newVal = (head.val) * 2 + carry;
//         head.val = newVal % 10;
//         return newVal / 10;
//     }

//     public ListNode doubleIt(ListNode head) {
//         int lastCarry = solve(head);
//         if (lastCarry > 0) {
//             ListNode newHead = new ListNode(lastCarry);
//             newHead.next = head;
//             return newHead;
//         }
//         return head;
//     }
// }



// class Solution {
//     public ListNode reverse(ListNode head) {
//         if (head == null || head.next == null) {
//             return head;
//         }
//         ListNode last = reverse(head.next);
//         head.next.next = head;
//         head.next = null;

//         return last;
//     }

//     public ListNode doubleIt(ListNode head) {
//         head = reverse(head);
//         ListNode curr = head;
//         ListNode prev = null;
//         int carry = 0;
//         while (curr != null) {
//             int newValue = curr.val * 2 + carry;
//             curr.val = newValue % 10;
//             if (newValue >= 10) {
//                 carry = 1;
//             } else {
//                 carry = 0;
//             }
//             prev = curr;
//             curr = curr.next;
//         }
//         if (carry != 0) {
//             ListNode newHead = new ListNode(carry);
//             prev.next = newHead;
//         }
//         return reverse(head);
//     }
// }
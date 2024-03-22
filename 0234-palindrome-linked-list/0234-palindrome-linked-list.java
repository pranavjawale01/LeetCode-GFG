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

// using recusion

class Solution {
    ListNode curr;
    public boolean solve(ListNode head) {
        if (head == null) {
            return true;
        }
        if (!solve(head.next) || head.val != curr.val) {
            return false;
        }
        curr = curr.next;
        return true;
    }
    public boolean isPalindrome(ListNode head) {
        curr = head;
        return solve(head);
    }
}

// one pass solution
// class Solution {
//     public boolean isPalindrome(ListNode head) {
//         if (head == null || head.next == null) {
//             return true;
//         }
//         ListNode prev = null;
//         ListNode fast = head;
//         ListNode slow = head;
//         while (fast != null && fast.next != null) {
//             fast = fast.next.next;
//             ListNode temp = slow.next;
//             slow.next = prev;
//             prev = slow;
//             slow = temp;
//         }
//         if (fast != null) {
//             slow = slow.next;
//         } 
//         while (prev != null && slow != null) {
//             if (prev.val != slow.val) {
//                 return false;
//             }
//             prev = prev.next;
//             slow = slow.next;
//         }
//         return true;
//     }
// }

// // using two pass solution

// // class Solution {
// //     public ListNode reverseList(ListNode head) {
// //         if(head == null || head.next == null)
// //             return head;
// //         ListNode last = reverseList(head.next);
// //         head.next.next = head;
// //         head.next = null;
// //         return last;
// //     }

// //     public boolean isPalindrome(ListNode head) {
// //         if(head == null || head.next == null) {
// //             return true;
// //         }
// //         ListNode slow = head;
// //         ListNode fast = head;
// //         ListNode prev = null;
// //         while(fast != null && fast.next != null) {
// //             prev = slow;
// //             slow = slow.next;
// //             fast = fast.next.next;
// //         }
// //         ListNode revhead = reverseList(slow);
// //         prev.next = null;
// //         while(revhead != null && head != null) {
// //             if(revhead.val != head.val) {
// //                 return false;
// //             }
// //             revhead = revhead.next;
// //             head = head.next;
// //         }
// //         return true;
// //     }
// // }

// // // using arraylist
// // // class Solution {
// // //     public boolean isPalindrome(ListNode head) {
// // //         List<Integer> temp = new ArrayList<>();
// // //         ListNode curr = head;
// // //         while (curr != null) {
// // //             temp.add(curr.val);
// // //             curr = curr.next;
// // //         }
// // //         int i = 0, j = temp.size() - 1;
// // //         while (i < j) {
// // //             if (!temp.get(i).equals(temp.get(j))) {
// // //                 return false;
// // //             }
// // //             i++;
// // //             j--;
// // //         }
// // //         return true;
// // //     }
// // // }
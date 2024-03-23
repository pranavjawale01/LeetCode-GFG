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
    public void reorderList(ListNode head) {
        if (head == null || head.next == null)
            return;

        ListNode slow = head, fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode prev = null, curr = slow.next, next;
        slow.next = null; 
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        ListNode first = head, second = prev;
        while (first != null && second != null) {
            ListNode firstNext = first.next;
            ListNode secondNext = second.next;

            first.next = second;
            second.next = firstNext;

            first = firstNext;
            second = secondNext;
        }        
    }
}


// class Solution {
//     ListNode curr;

//     void solve(ListNode head) { 
//         if (head == null) {
//             return;
//         }
//         solve(head.next);
//         ListNode temp = curr.next;
//         if (temp == null) {
//             return;
//         } else if (head == curr) {
//             head.next = null;
//             return;
//         }
//         curr.next = head;
//         head.next = temp == head ? null : temp;
//         curr = temp;
//     }

//     public void reorderList(ListNode head) {
//         curr = head;
//         solve(head);
//     }
// }

// // class Solution {
// //     public void reorderList(ListNode head) {
// //         Stack<ListNode> st = new Stack<>();
// //         ListNode curr = head;
// //         while (curr != null) {
// //             st.add(curr);
// //             curr = curr.next;
// //         }
// //         curr = head;
// //         int n = st.size() / 2;
// //         while (n-- > 0) {
// //             ListNode tempNode = st.pop();

// //             ListNode temp = curr.next;
// //             curr.next = tempNode;
// //             tempNode.next = temp;
// //             curr = temp;
// //         }
// //         curr.next = null;
// //     }
// // }

// // // class Solution {
// // //     public ListNode reverse(ListNode head) {
// // //         if (head == null || head.next == null) {
// // //             return head;
// // //         }
// // //         ListNode last = reverse(head.next);
// // //         head.next.next = head;
// // //         head.next = null;
// // //         return last;
// // //     }
// // //     public void reorderList(ListNode head) {
// // //         if (head == null || head.next == null) {
// // //             return;
// // //         }
// // //         ListNode slow = head, fast = head;
// // //         while (fast != null && fast.next != null) {
// // //             slow = slow.next;
// // //             fast = fast.next.next;
// // //         }
// // //         ListNode rev = reverse(slow);
// // //         ListNode curr = head;
// // //         while (rev.next != null) {
// // //             ListNode tempcurr = curr.next;
// // //             curr.next = rev;

// // //             ListNode temprev = rev.next;
// // //             rev.next = tempcurr;

// // //             curr = tempcurr;
// // //             rev  = temprev;  
// // //         }        
// // //     }
// // // }

// // // // class Solution {
// // // //     public void reorderList(ListNode head) {
// // // //         List<Integer> arr = new ArrayList<>();
// // // //         ListNode temp = head;
// // // //         while (temp != null) {
// // // //             arr.add(temp.val);
// // // //             temp = temp.next;
// // // //         }
// // // //         int n = arr.size();
// // // //         temp = head;
// // // //         int i = 0;
// // // //         while (temp != null && temp.next != null) {
// // // //             temp.val = arr.get(i);
// // // //             temp.next.val = arr.get(n - i - 1);
// // // //             temp = temp.next.next;
// // // //             i++;
// // // //         }
// // // //         if (n % 2 != 0) {
// // // //             temp.val = arr.get(n / 2);
// // // //         }
// // // //     }
// // // // }
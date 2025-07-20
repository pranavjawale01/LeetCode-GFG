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
    public ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nxt = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    public ListNode removeNodes(ListNode head) {
        if (head == null) return null;
        
        head = reverse(head);
        Stack<Integer> st = new Stack<>();
        
        ListNode current = head;
        while (current != null) {
            if (st.isEmpty() || st.peek() <= current.val) {
                st.push(current.val);
            }
            current = current.next;
        }
        
        ListNode newHead = null;
        while (!st.isEmpty()) {
            ListNode temp = new ListNode(st.pop());
            temp.next = newHead;
            newHead = temp;
        }
        
        return reverse(newHead);
    }
}


// class Solution {
//     public ListNode removeNodes(ListNode head) {
//         ListNode curr = head;
//         Stack<ListNode> st = new Stack<>();
//         while (curr != null) {
//             st.push(curr);
//             curr = curr.next;
//         }
//         curr = st.pop();
//         int maxNode = curr.val;
//         ListNode resultHead = new ListNode(curr.val);
//         while (!st.empty()) {
//             curr = st.pop();
//             if (curr.val < maxNode) {
//                 continue;
//             } else {
//                 ListNode newNode = new ListNode(curr.val);
//                 newNode.next = resultHead;
//                 resultHead = newNode;
//                 maxNode = curr.val;
//             }
//         }
//         return resultHead;
//     }
// }



// class Solution {
//     public ListNode removeNodes(ListNode head) {
//         if (head == null || head.next == null) {
//             return head;
//         }
//         ListNode nextNode = removeNodes(head.next);
//         if (head.val < nextNode.val) {
//             head = null;
//             return nextNode;
//         }
//         head.next = nextNode;
//         return head;
//     }
// }



// class Solution {
//     ListNode reverse(ListNode head) {
//         if (head == null || head.next == null) {
//             return head;
//         }
//         ListNode last = reverse(head.next);
//         head.next.next = head;
//         head.next = null;
//         return last;
//     }
//     public ListNode removeNodes(ListNode head) {
//         head = reverse(head);
//         int maxNode = -1;
//         ListNode prev = null;
//         ListNode curr = head;
//         while (curr != null) {
//             maxNode = Math.max(maxNode, curr.val);
//             if (curr.val < maxNode) {
//                 prev.next = curr.next;
//                 ListNode temp = curr;
//                 curr = curr.next;
//                 temp = null;
//             } else {
//                 prev = curr;
//                 curr = curr.next;
//             }
//         }
//         return reverse(head);
//     }
// }
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
        

class Solution:
    def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        last = self.reverse(head.next)
        head.next.next = head
        head.next = None
        return last

    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = self.reverse(head)
        curr = head
        prev = None
        carry = 0
        while curr:
            newValue = curr.val * 2 + carry
            curr.val = newValue % 10
            carry = 1 if newValue >= 10 else 0
            prev = curr
            curr = curr.next
        if carry != 0:
            newHead = ListNode(carry)
            prev.next = newHead
        return self.reverse(head)
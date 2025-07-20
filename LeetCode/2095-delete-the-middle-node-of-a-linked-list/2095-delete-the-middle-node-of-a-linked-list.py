# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return None
        prev = None
        slow = head
        fast = head
        while fast.next and fast.next.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        if fast.next:
            prev = slow
            slow = slow.next
        prev.next = slow.next
        return head
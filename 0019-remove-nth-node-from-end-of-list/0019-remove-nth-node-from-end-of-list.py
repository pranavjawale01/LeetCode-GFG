# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = head
        for i in range(1, n+1):
            temp = temp.next
        if temp is None:
            return head.next
        prev = head
        while temp and temp.next:
            temp = temp.next
            prev = prev.next
        prev.next = prev.next.next
        return head

# class Solution:
#     def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
#         count = 0
#         temp = head
#         while temp:
#             count += 1
#             temp = temp.next
#         if count == n:
#             return head.next        
#         prev , temp = None, head
#         count -= n
#         while count > 0:
#             count -= 1
#             prev = temp
#             temp = temp.next
#         prev.next = temp.next
#         return head
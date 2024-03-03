# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        temp = head
        while temp:
            count += 1
            temp = temp.next
        if count == n:
            return head.next        
        prev , temp = None, head
        count -= n
        while count > 0:
            count -= 1
            prev = temp
            temp = temp.next
        prev.next = temp.next
        return head
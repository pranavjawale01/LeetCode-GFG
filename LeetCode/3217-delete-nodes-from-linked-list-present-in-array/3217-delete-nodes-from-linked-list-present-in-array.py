# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        st = set(nums)
        while head and head.val in st:
            head = head.next
        if head is None:
            return None
        prev = head
        temp = head.next

        while temp:
            if temp.val in st:
                prev.next = temp.next
            else:
                prev = temp
            temp = temp.next
        
        return head
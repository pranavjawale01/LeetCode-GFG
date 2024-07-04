# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        count = 0
        st = set(nums)
        while head:
            flag = False
            while head and head.val in st:
                flag = True
                head = head.next
            if flag:
                count += 1
            if head:
                head = head.next
        return count
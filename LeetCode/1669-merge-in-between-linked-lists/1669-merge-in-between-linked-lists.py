# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        left, right = None, list1
        for i in range(b+1):
            if i == a-1:
                left = right
            right = right.next
        left.next = list2
        temp = list2
        while temp and temp.next:
            temp = temp.next
        temp.next = right
        return list1
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = head.next
        if not head:
            return head
        temp = head
        sum = 0
        while temp and temp.val != 0:
            sum += temp.val
            temp = temp.next
        head.val = sum
        head.next = self.mergeNodes(temp)
        return head





# # Definition for singly-linked list.
# # class ListNode:
# #     def __init__(self, val=0, next=None):
# #         self.val = val
# #         self.next = next
# class Solution:
#     def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         ans = ListNode(0)
#         temp = ans
#         sum = 0
#         head = head.next
#         while head:
#             if head.val == 0:
#                 temp.next = ListNode(sum)
#                 temp = temp.next
#                 sum = 0
#             else:
#                 sum += head.val
#             head = head.next
#         return ans.next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head: return []
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        prev, curr = None, slow.next
        while curr:
            nextt = curr.next
            curr.next = prev
            prev = curr
            curr = nextt    
        slow.next = None

        left, right = head, prev
        while right:
            nextt = left.next
            left.next = right
            left = right
            right = nextt
        

# class Solution:
#     def solve(self, head: Optional[ListNode]) -> None:
#         if not head:
#             return
#         self.solve(head.next)
#         temp = self.curr.next
#         if not temp:
#             return
#         elif head == self.curr:
#             head.next = None
#             return
#         self.curr.next = head
#         head.next = None if temp == head else temp
#         self.curr = temp

#     def reorderList(self, head: Optional[ListNode]) -> None:
#         """
#         Do not return anything, modify head in-place instead.
#         """
#         self.curr = head
#         self.solve(head)
        
# # class Solution:
# #     def reorderList(self, head: Optional[ListNode]) -> None:
# #         """
# #         Do not return anything, modify head in-place instead.
# #         """
# #         st = []
# #         curr = head
# #         while curr:
# #             st.append(curr)
# #             curr = curr.next
# #         curr = head
# #         n = len(st) // 2
# #         for _ in range(n):
# #             tempNode = st.pop()
# #             temp = curr.next
# #             curr.next = tempNode
# #             tempNode.next = temp
# #             curr = temp
# #         if curr:
# #             curr.next = None
        
# # # class Solution:
# # #     def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:  
# # #         if not head or not head.next:
# # #             return head
# # #         last = self.reverse(head.next)  
# # #         head.next.next = head
# # #         head.next = None
# # #         return last

# # #     def reorderList(self, head: Optional[ListNode]) -> None:
# # #         """
# # #         Do not return anything, modify head in-place instead.
# # #         """
# # #         slow, fast = head, head
# # #         while fast and fast.next:
# # #             slow = slow.next
# # #             fast = fast.next.next
# # #         rev = self.reverse(slow)  
# # #         curr = head
# # #         while rev.next:
# # #             tempcurr = curr.next
# # #             curr.next = rev

# # #             temprev = rev.next
# # #             rev.next = tempcurr

# # #             curr = tempcurr
# # #             rev = temprev
        

# # # # class Solution:
# # # #     def reorderList(self, head: Optional[ListNode]) -> None:
# # # #         """
# # # #         Do not return anything, modify head in-place instead.
# # # #         """
# # # #         arr = []
# # # #         temp = head
# # # #         while temp:
# # # #             arr.append(temp.val)
# # # #             temp = temp.next
# # # #         i , n = 0, len(arr)
# # # #         temp = head
# # # #         while temp and temp.next:
# # # #             temp.val = arr[i]
# # # #             temp.next.val = arr[n - i - 1]
# # # #             temp = temp.next.next
# # # #             i += 1
# # # #         if n % 2 != 0:
# # # #             temp.val = arr[n//2]
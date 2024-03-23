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

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        rev = self.reverse(slow)  
        curr = head
        while rev.next:
            tempcurr = curr.next
            curr.next = rev

            temprev = rev.next
            rev.next = tempcurr

            curr = tempcurr
            rev = temprev
        

# class Solution:
#     def reorderList(self, head: Optional[ListNode]) -> None:
#         """
#         Do not return anything, modify head in-place instead.
#         """
#         arr = []
#         temp = head
#         while temp:
#             arr.append(temp.val)
#             temp = temp.next
#         i , n = 0, len(arr)
#         temp = head
#         while temp and temp.next:
#             temp.val = arr[i]
#             temp.next.val = arr[n - i - 1]
#             temp = temp.next.next
#             i += 1
#         if n % 2 != 0:
#             temp.val = arr[n//2]
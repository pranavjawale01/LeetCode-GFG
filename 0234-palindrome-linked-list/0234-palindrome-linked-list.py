# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

#one pass solution
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head
        prev = None
        while fast and fast.next:
            fast = fast.next.next
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp
        if fast:
            slow = slow.next
        while slow and prev:
            if prev.val != slow.val:
                return False
            prev = prev.next
            slow = slow.next
        return True

#two pass solution
# class Solution:
#     def reverse(head: Optional[ListNode]) -> Optional[ListNode]:
#         if head is None or head.next is None:
#             return head
#         last = Solution.reverse(head.next)
#         head.next.next = head
#         head.next = None
#         return last

#     def isPalindrome(self, head: Optional[ListNode]) -> bool:
#         if head is None or head.next is None:
#             return True
#         fast, slow, prev = head, head, None
#         while fast is not None and fast.next is not None:
#             prev = slow
#             slow = slow.next
#             fast = fast.next.next
#         rev = Solution.reverse(slow)
#         while rev and head:
#             if rev.val != head.val:
#                 return False
#             rev = rev.next
#             head = head.next
#         return True

# #using array
# # class Solution:
# #     def isPalindrome(self, head: Optional[ListNode]) -> bool:
# #         arr = []
# #         temp = head
# #         while temp:
# #             arr.append(temp.val)
# #             temp = temp.next
# #         return arr[::1] == arr[::-1]
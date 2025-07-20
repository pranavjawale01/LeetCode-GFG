# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.val >= 5:
            newHead = ListNode(0)
            newHead.next = head
            head = newHead
        curr = head
        prev = None

        while curr:
            newVal = curr.val * 2
            if newVal < 10:
                curr.val = newVal
            elif prev:
                curr.val = newVal % 10
                prev.val += 1
            else:
                newHead = ListNode(1)
                newHead.next = curr
                curr.val = newVal % 10
                head = newHead
            prev = curr
            curr = curr.next
        return head


# class Solution:
#     def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         curr = head
#         prev = None

#         while curr:
#             newVal = curr.val * 2
#             if newVal < 10:
#                 curr.val = newVal
#             elif prev:
#                 curr.val = newVal % 10
#                 prev.val += 1
#             else:
#                 newHead = ListNode(1)
#                 newHead.next = curr
#                 curr.val = newVal % 10
#                 head = newHead
#             prev = curr
#             curr = curr.next
#         return head


# class Solution:
#     def solve(self, head: Optional[ListNode]) -> int:
#         if not head:
#             return 0
#         carry = self.solve(head.next)
#         newVal = (head.val) * 2 + carry
#         head.val = newVal % 10
#         return newVal // 10
#     def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         lastCarry = self.solve(head)
#         if lastCarry > 0:
#             newHead = ListNode(lastCarry)
#             newHead.next = head
#             return newHead
#         return head       

      

# class Solution:
#     def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         if not head or not head.next:
#             return head
#         last = self.reverse(head.next)
#         head.next.next = head
#         head.next = None
#         return last

#     def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         head = self.reverse(head)
#         curr = head
#         prev = None
#         carry = 0
#         while curr:
#             newValue = curr.val * 2 + carry
#             curr.val = newValue % 10
#             carry = 1 if newValue >= 10 else 0
#             prev = curr
#             curr = curr.next
#         if carry != 0:
#             newHead = ListNode(carry)
#             prev.next = newHead
#         return self.reverse(head)
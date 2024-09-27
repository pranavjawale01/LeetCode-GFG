# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDifference(self, head1: ListNode, head2: ListNode) -> int:
        len1, len2 = 0, 0
        while head1:
            len1 += 1
            head1 = head1.next
        while head2:
            len2 += 1
            head2 = head2.next
        return len1 - len2

    def getIntersectionNode(self, head1: ListNode, head2: ListNode) -> Optional[ListNode]:
        diff = self.getDifference(head1, head2)
        if diff < 0:
            while diff != 0:
                head2 = head2.next
                diff += 1
        else:
            while diff != 0:
                head1 = head1.next
                diff -= 1
        while head1 and head2:
            if head1 == head2:
                return head1
            head1 = head1.next
            head2 = head2.next
        return None









# class Solution:
#     def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
#         if not headA or not headB:
#             return None
        
#         pointerA, pointerB = headA, headB
        
#         while pointerA != pointerB:
#             pointerA = pointerA.next if pointerA else headB
#             pointerB = pointerB.next if pointerB else headA
        
#         return pointerA
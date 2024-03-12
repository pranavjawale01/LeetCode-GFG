# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        con_sum = 0
        dummy = ListNode(0)
        dummy.next = head
        mp = {}
        mp[0] = dummy

        while head:
            con_sum += head.val
            if con_sum in mp:
                start = mp[con_sum]
                temp = start
                p_sum = con_sum
                while temp != head:
                    temp = temp.next
                    p_sum += temp.val
                    if temp != head:
                        del mp[p_sum]
                start.next = head.next
            else:
                mp[con_sum] = head
            head = head.next
        return dummy.next
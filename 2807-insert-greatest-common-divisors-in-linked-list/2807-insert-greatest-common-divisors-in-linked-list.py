# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def gcd(self, a: int, b: int) -> int:
        while a != 0:
            a, b = b % a, a
        return b
        
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        
        while temp and temp.next:
            a = temp.val
            b = temp.next.val
            gcd_val = self.gcd(a, b)
            
            new_node = ListNode(gcd_val)
            new_node.next = temp.next
            temp.next = new_node
            
            temp = new_node.next
        
        return head
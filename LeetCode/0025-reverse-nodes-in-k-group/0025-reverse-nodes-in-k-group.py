# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        result = ListNode(0)
        result.next = head
        prev_group_end = result
        curr = head
        length = 0        
        temp = head

        while temp:
            length += 1
            temp = temp.next 
                   
        head = result.next

        for i in range(length // k):
            group_start = prev_group_end.next
            group_end = group_start
            next_node = None            

            for j in range(k):
                next_node = curr.next
                curr.next = group_start
                group_start = curr
                curr = next_node

            prev_group_end.next = group_start
            group_end.next = next_node
            prev_group_end = group_end  

        return result.next
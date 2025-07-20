# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        length = 0
        temp = head
        while temp:
            temp = temp.next
            length += 1
        
        part_size = length // k
        extra_nodes = length % k
        
        result = []
        temp = head
        
        for i in range(k):
            if not temp:
                result.append(None)
                continue
            
            current_part_head = temp
            current_part_size = part_size + (1 if extra_nodes > 0 else 0)
            extra_nodes -= 1
            
            for _ in range(current_part_size - 1):
                temp = temp.next
            
            next_part_head = temp.next
            temp.next = None
            temp = next_part_head
            
            result.append(current_part_head)
        
        return result
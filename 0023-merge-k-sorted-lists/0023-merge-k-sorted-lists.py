# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap, res = [], ListNode()
        for i, list in enumerate(lists):
            if list: 
                heappush(heap, (list.val, i, list))
        cur = res
        while heap:
            _, i, list = heappop(heap)
            if list.next:
                heappush(heap, (list.next.val, i, list.next))
            cur.next, cur = list, list
        return res.next
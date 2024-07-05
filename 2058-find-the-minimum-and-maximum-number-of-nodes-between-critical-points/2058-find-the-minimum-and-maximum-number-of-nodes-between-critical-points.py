# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        prev = head
        curr = head.next
        currPos = 1
        prevPos = 0
        firstPos = 0
        minDist = float('inf')
        while curr and curr.next:
            if (curr.val < prev.val and curr.val < curr.next.val) or (curr.val > prev.val and curr.val > curr.next.val):
                if prevPos == 0:
                    prevPos = currPos
                    firstPos = currPos
                else:
                    minDist = min(minDist, currPos - prevPos)
                    prevPos = currPos
            currPos += 1
            prev = curr
            curr = curr.next
        if minDist == float('inf'):
            return [-1, -1]
        return [minDist, prevPos - firstPos]
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        arr = [[-1 for _ in range(n)] for _ in range(m)]
        left, right, top, bottom = 0, n - 1, 0, m - 1
        while left <= right and top <= bottom and head:
            for i in range(left, right+1):
                if head:
                    arr[top][i] = head.val
                    head = head.next
            top += 1
        
            for i in range(top, bottom+1):
                if head:
                    arr[i][right] = head.val
                    head = head.next
            right -= 1

            if top <= bottom:
                for i in range(right, left-1, -1):
                    if head:
                        arr[bottom][i] = head.val
                        head = head.next
                bottom -= 1
            
            if left <= right:
                for i in range(bottom, top-1, -1):
                    if head:
                        arr[i][left] = head.val
                        head = head.next
                left += 1
        return arr
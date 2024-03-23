# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        arr = []
        temp = head
        while temp:
            arr.append(temp.val)
            temp = temp.next
        i , n = 0, len(arr)
        temp = head
        while temp and temp.next:
            temp.val = arr[i]
            temp.next.val = arr[n - i - 1]
            temp = temp.next.next
            i += 1
        if n % 2 != 0:
            temp.val = arr[n//2]
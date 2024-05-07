# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev

    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        
        head = self.reverse(head)
        st = []
        current = head
        while current:
            if not st or st[-1].val <= current.val:
                st.append(current)
            current = current.next
        
        newHead = None
        while st:
            temp = ListNode(st.pop().val)
            temp.next = newHead
            newHead = temp
        
        return self.reverse(newHead)



# class Solution:
#     def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         if not head:
#             return None
#         curr = head
#         st = []
#         while curr:
#             st.append(curr)
#             curr = curr.next
#         curr = st.pop()
#         maxNode = curr.val
#         resultHead = ListNode(curr.val)
#         while st:
#             curr = st.pop()
#             if curr.val < maxNode:
#                 continue
#             else:
#                 newNode = ListNode(curr.val)
#                 newNode.next = resultHead
#                 resultHead = newNode
#                 maxNode = curr.val
#         return resultHead



# class Solution:
#     def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         if not head or not head.next:
#             return head
#         nextNode = self.removeNodes(head.next)
#         if head.val < nextNode.val:
#             return nextNode
#         head.next = nextNode
#         return head
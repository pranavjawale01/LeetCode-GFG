# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        curr = head
        st = []
        while curr:
            st.append(curr)
            curr = curr.next
        curr = st.pop()
        maxNode = curr.val
        resultHead = ListNode(curr.val)
        while st:
            curr = st.pop()
            if curr.val < maxNode:
                continue
            else:
                newNode = ListNode(curr.val)
                newNode.next = resultHead
                resultHead = newNode
                maxNode = curr.val
        return resultHead



# class Solution:
#     def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         if not head or not head.next:
#             return head
#         nextNode = self.removeNodes(head.next)
#         if head.val < nextNode.val:
#             return nextNode
#         head.next = nextNode
#         return head
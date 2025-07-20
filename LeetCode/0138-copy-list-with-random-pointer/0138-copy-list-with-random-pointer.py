"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        curr = head
        while curr:
            copy = Node(curr.val)
            copy.next = curr.next
            curr.next = copy
            curr = copy.next

        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next

        curr = head
        new_head = head.next
        copy = None
        while curr:
            copy = curr.next
            curr.next = copy.next
            if copy.next:
                copy.next = copy.next.next
            curr = curr.next

        return new_head



# class Solution:
#     def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
#         if not head:
#             return None

#         temp = head
#         mp = {}

#         while temp:
#             newNode = Node(temp.val)
#             mp[temp] = newNode
#             temp = temp.next

#         temp = head
#         while temp:
#             copyNode = mp[temp]
#             copyNode.next = mp.get(temp.next)
#             copyNode.random = mp.get(temp.random)
#             temp = temp.next

#         return mp[head]
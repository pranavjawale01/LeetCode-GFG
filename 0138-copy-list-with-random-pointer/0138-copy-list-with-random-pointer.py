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

        temp = head
        mp = {}

        while temp:
            newNode = Node(temp.val)
            mp[temp] = newNode
            temp = temp.next

        temp = head
        while temp:
            copyNode = mp[temp]
            copyNode.next = mp.get(temp.next)
            copyNode.random = mp.get(temp.random)
            temp = temp.next

        return mp[head]
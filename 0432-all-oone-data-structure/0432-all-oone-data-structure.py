class Node:
    def __init__(self, count: int):
        self.count = count
        self.keys = set()
        self.prev = None
        self.next = None


class AllOne:
    def __init__(self):
        self.head = Node(0)
        self.tail = Node(0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.key_map = {}

    def _add_node_after(self, prev_node: Node, new_node: Node):
        new_node.next = prev_node.next
        new_node.prev = prev_node
        prev_node.next.prev = new_node
        prev_node.next = new_node

    def _remove_node(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def inc(self, key: str) -> None:
        if key not in self.key_map:
            if self.head.next == self.tail or self.head.next.count != 1:
                self._add_node_after(self.head, Node(1))
            self.head.next.keys.add(key)
            self.key_map[key] = self.head.next
        else:
            curr = self.key_map[key]
            curr_count = curr.count
            curr.keys.remove(key)
            if curr.next == self.tail or curr.next.count != curr_count + 1:
                self._add_node_after(curr, Node(curr_count + 1))
            curr.next.keys.add(key)
            self.key_map[key] = curr.next
            if not curr.keys:
                self._remove_node(curr)

    def dec(self, key: str) -> None:
        if key not in self.key_map:
            return

        curr = self.key_map[key]
        curr_count = curr.count
        curr.keys.remove(key)

        if curr_count == 1:
            del self.key_map[key]
        else:
            if curr.prev == self.head or curr.prev.count != curr_count - 1:
                self._add_node_after(curr.prev, Node(curr_count - 1))
            curr.prev.keys.add(key)
            self.key_map[key] = curr.prev

        if not curr.keys:
            self._remove_node(curr)

    def getMaxKey(self) -> str:
        if self.tail.prev == self.head:
            return ""
        return next(iter(self.tail.prev.keys))

    def getMinKey(self) -> str:
        if self.head.next == self.tail:
            return ""
        return next(iter(self.head.next.keys))

        


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()

















# class AllOne:
#     def __init__(self):
#         self.myDict = {}

#     def inc(self, key: str) -> None:
#         if key in self.myDict:
#             self.myDict[key] += 1
#         else:
#             self.myDict[key] = 1

#     def dec(self, key: str) -> None:
#         if key in self.myDict:
#             if self.myDict[key] > 1:
#                 self.myDict[key] -= 1
#             else:
#                 self.myDict.pop(key)

#     def getMaxKey(self) -> str:
#         if not self.myDict:
#             return ""
#         maxVal = max(self.myDict.values())
#         for key in self.myDict.keys():
#             if self.myDict[key] == maxVal:
#                 return key

#     def getMinKey(self) -> str:
#         if not self.myDict:
#             return ""
#         minVal = min(self.myDict.values())
#         for key in self.myDict.keys():
#             if self.myDict[key] == minVal:
#                 return key




# # Your AllOne object will be instantiated and called as such:
# # obj = AllOne()
# # obj.inc(key)
# # obj.dec(key)
# # param_3 = obj.getMaxKey()
# # param_4 = obj.getMinKey()
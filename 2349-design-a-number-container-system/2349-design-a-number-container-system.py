class NumberContainers:

    def __init__(self):
        self.mpIdxNum = {}
        self.mpNumIdx = defaultdict(sortedcontainers.SortedSet)

    def change(self, index: int, number: int) -> None:
        if index in self.mpIdxNum:
            prevNumber = self.mpIdxNum[index]
            self.mpNumIdx[prevNumber].discard(index)
            if not self.mpNumIdx[prevNumber]:
                del self.mpNumIdx[prevNumber]

        self.mpIdxNum[index] = number
        self.mpNumIdx[number].add(index)

    def find(self, number: int) -> int:
        if number in self.mpNumIdx and self.mpNumIdx[number]:
            return next(iter(self.mpNumIdx[number]))
        return -1


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
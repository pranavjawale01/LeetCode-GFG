class RandomizedSet:
    def __init__(self):
        self.listV = []
        self.mp = {}

    def insert(self, val: int) -> bool:
        if val not in self.mp:
            self.listV.append(val)
            self.mp[val] = len(self.listV) - 1
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self.mp:
            lastElement = self.listV[-1]
            index = self.mp[val]
            self.listV[index] = lastElement
            self.mp[lastElement] = index
            self.listV.pop()
            del self.mp[val]
            return True
        return False

    def getRandom(self) -> int:
        n = len(self.listV)
        randomNumber = random.randint(0, n-1)
        return self.listV[randomNumber]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
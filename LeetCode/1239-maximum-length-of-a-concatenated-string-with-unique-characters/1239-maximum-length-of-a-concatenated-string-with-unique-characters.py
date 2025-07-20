class Solution:
    def maxLength(self, arr: List[str]) -> int:
        self.memory = {}

        def hasDuplicate(s1, s2):
            temp = s1 + s2
            charSet = set()
            for ch in temp:
                if ch in charSet:
                    return True
                charSet.add(ch)
            return False

        def recursive(arr, temp, i):
            if i >= len(arr):
                return len(temp)
            if temp in self.memory:
                return self.memory[temp]

            include, exclude = 0, 0
            if not hasDuplicate(temp, arr[i]):
                include = recursive(arr, temp + arr[i], i + 1)
            exclude = recursive(arr, temp, i + 1)

            self.memory[temp] = max(include, exclude)
            return self.memory[temp]

        temp = ""
        self.memory.clear()
        return recursive(arr, temp, 0)
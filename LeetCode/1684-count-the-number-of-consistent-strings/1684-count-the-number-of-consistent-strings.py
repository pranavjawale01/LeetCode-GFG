class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        mask = 0
        for c in allowed:
            mask |= 1 << (ord(c) - ord('a'))
        count = 0
        for s in words:
            flag = True
            for c in s:
                if (mask >> (ord(c) - ord('a')) & 1) == 0:
                    flag = False
                    break
            if flag:
                count += 1
        return count



# class Solution:
#     def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
#         st = set(allowed)
#         count = 0
#         for s in words:
#             flag = False
#             for c in s:
#                 if c not in st:
#                     flag = True
#                     break
#             if flag:
#                 continue
#             count += 1
#         return count
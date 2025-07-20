class Solution:
    def toLowerCase(self, s: str) -> str:
        char = []
        for c in s:
            char.append(c.lower())
        return ''.join(char)


# class Solution:
#     def toLowerCase(self, s: str) -> str:
#         return s.lower()
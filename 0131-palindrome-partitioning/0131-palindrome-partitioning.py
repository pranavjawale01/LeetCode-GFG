class Solution:
    def __init__(self):
        self.ans = []

    def is_palindrome(self, s: str) -> bool:
        return s == s[::-1]

    def solve(self, s: str, temp: List[str], start: int):
        if start == len(s):
            self.ans.append(list(temp))
            return
        
        for end in range(start, len(s)):
            substring = s[start:end + 1]
            if self.is_palindrome(substring):
                temp.append(substring)
                self.solve(s, temp, end + 1)
                temp.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.ans = []
        self.solve(s, [], 0)
        return self.ans
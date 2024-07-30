class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        count = 0
        stack = []
        
        for i in range(n):
            if stack and s[i] == 'a' and stack[-1] == 'b':
                stack.pop()
                count += 1
            else:
                stack.append(s[i])
        
        return count
class Solution:
    def reverseParentheses(self, s: str) -> str:
        def reverse(sub: list, start: int, end: int):
            while start < end:
                sub[start], sub[end] = sub[end], sub[start]
                start += 1
                end -= 1

        stack = []
        result = []
        for c in s:
            if c == '(':
                stack.append(len(result))
            elif c == ')':
                start = stack.pop()
                reverse(result, start, len(result) - 1)
            else:
                result.append(c)
        
        return ''.join(result)
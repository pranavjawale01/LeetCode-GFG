class Solution:
    def isValid(self, s: str) -> bool:
        slen = len(s)
        if slen % 2 != 0:
            return False

        stack = []
        for i in range(slen):
            current_char = s[i]
            if current_char == '(' or current_char == '{' or current_char == '[':
                stack.append(current_char)
            else:
                if not stack:
                    return False
                top = stack[-1]
                if (current_char == ')' and top != '(') or (current_char == '}' and top != '{') or (current_char == ']' and top != '['):
                    return False
                stack.pop()

        return not stack
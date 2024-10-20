class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        for c in expression:
            if c in 'tf!&|':
                stack.append(c)
            elif c == ')':
                has_true = False
                has_false = False
                
                while stack and stack[-1] not in '!&|':
                    val = stack.pop()
                    if val == 't':
                        has_true = True
                    elif val == 'f':
                        has_false = True
                
                op = stack.pop()
                if op == '!':
                    stack.append('f' if has_true else 't')
                elif op == '&':
                    stack.append('f' if has_false else 't')
                elif op == '|':
                    stack.append('t' if has_true else 'f')

        return stack[-1] == 't'
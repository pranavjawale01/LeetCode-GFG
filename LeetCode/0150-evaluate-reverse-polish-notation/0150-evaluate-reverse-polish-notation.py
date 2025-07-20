class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stk = []

        for i in range(len(tokens)):
            if tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/":
                operand2 = stk.pop()
                operand1 = stk.pop()
                if tokens[i] == "+":
                    stk.append(operand1 + operand2)
                elif tokens[i] == "-":
                    stk.append(operand1 - operand2)
                elif tokens[i] == "*":
                    stk.append(operand1 * operand2)
                elif tokens[i] == "/":
                    stk.append(int(operand1 / operand2))
            else:
                stk.append(int(tokens[i]))

        return stk[-1]
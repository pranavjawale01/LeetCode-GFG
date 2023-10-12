class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        keypad = {"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
        def backtracking(i,curStr):
            if len(curStr) == len(digits):
                res.append(curStr)
                return
            for c in keypad[digits[i]]:
                backtracking(i+1,curStr+c)
        if digits:
            backtracking(0,"")
        return res
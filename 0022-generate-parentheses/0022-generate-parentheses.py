class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(left,right,s):
            if len(s) == n*2:
                res.append(s)
                return
            if left < n:
                backtrack(left+1,right,s+'(')
            if right < left:
                backtrack(left,right+1,s+')')
        res = []
        backtrack(0,0,'')
        return res
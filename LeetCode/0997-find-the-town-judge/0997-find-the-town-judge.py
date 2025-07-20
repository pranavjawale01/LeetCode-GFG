class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trusts=[0]*n
        trusted=[0]*n
        if len(trust)==1:
            return trust[0][1]
        for i in range(len(trust)):
            a=trust[i][0]
            b=trust[i][1]
            trusts[a-1]+=1
            trusted[b-1]+=1    
        for i in range(n):
            if trusts[i]==0 and trusted[i]==n-1:
                return i+1
        return -1    
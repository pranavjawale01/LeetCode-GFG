class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if(strs==None or len(strs)==0):
            return ""
        
        ans = ""
        strs.sort()
        first = strs[0]
        last = strs[len(strs)-1]
        minLen = min(len(first),len(last))
        for i in range(minLen):
            if first[i] != last[i]:
                return ans
            else:
                ans += first[i]
        return ans
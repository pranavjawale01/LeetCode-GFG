class Solution:
    def stringSequence(self, target: str) -> List[str]:
        ans = []
        temp = ""
        
        for i in range(len(target)):
            temp += 'a'
            ans.append(temp)
            
            while temp[-1] != target[i]:
                temp = temp[:-1] + chr(ord(temp[-1]) + 1)
                ans.append(temp)
        
        return ans
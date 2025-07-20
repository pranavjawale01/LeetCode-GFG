class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        s = s.split(' ')
        x = int(len(str(s[-1])))
        return(x)
    
# class Solution:
#     def lengthOfLastWord(self, s: str) -> int:
#         i , count = len(s) - 1 , 0

#         while i >= 0 and s[i] == ' ':
#             i -= 1
        
#         while i >= 0 and s[i] != ' ':
#             i -= 1
#             count += 1
        
#         return count
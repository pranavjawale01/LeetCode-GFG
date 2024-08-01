class Solution:
    def countSeniors(self, details: List[str]) -> int:
        count = 0
        for x in details:
            age = (ord(x[11]) - ord('0')) * 10 + ord(x[12]) - ord('0')
            if age > 60 :
                count += 1
        return count
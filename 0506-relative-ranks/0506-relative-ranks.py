class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        result = [None] * n
        mp = {}
        
        for i in range(n):
            mp[score[i]] = i
        
        score.sort(reverse=True)
        
        for i in range(n):
            ath = mp[score[i]]
            if i == 0:
                result[ath] = "Gold Medal"
            elif i == 1:
                result[ath] = "Silver Medal"
            elif i == 2:
                result[ath] = "Bronze Medal"
            else:
                result[ath] = str(i + 1)
        
        return result
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        teams = 0
        for j in range(1, n-1):
            countSmallerLeft = 0
            countLargerLeft  = 0
            countSmallerRight = 0
            countLargerRight = 0
            for i in range(j):
                if rating[i] < rating[j]:
                    countSmallerLeft += 1
                elif rating[i] > rating[j]:
                    countLargerLeft += 1
    
            for k in range(j+1, n):
                if rating[j] < rating[k]:
                    countLargerRight += 1
                elif rating[j] > rating[k]:
                    countSmallerRight += 1
            teams += (countLargerLeft * countSmallerRight) + (countSmallerLeft * countLargerRight)
        return teams
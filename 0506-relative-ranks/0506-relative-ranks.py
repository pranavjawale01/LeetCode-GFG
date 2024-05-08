from queue import PriorityQueue

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        result = [None] * n
        pq = PriorityQueue()
        
        for i in range(n):
            pq.put((-score[i], i))
        
        rank = 1
        while not pq.empty():
            athlete = pq.get()
            idx = athlete[1]
            
            if rank == 1:
                result[idx] = "Gold Medal"
            elif rank == 2:
                result[idx] = "Silver Medal"
            elif rank == 3:
                result[idx] = "Bronze Medal"
            else:
                result[idx] = str(rank)
            
            rank += 1
        
        return result


# class Solution:
#     def findRelativeRanks(self, score: List[int]) -> List[str]:
#         n = len(score)
#         result = [None] * n
#         mp = {}
        
#         for i in range(n):
#             mp[score[i]] = i
        
#         score.sort(reverse=True)
        
#         for i in range(n):
#             ath = mp[score[i]]
#             if i == 0:
#                 result[ath] = "Gold Medal"
#             elif i == 1:
#                 result[ath] = "Silver Medal"
#             elif i == 2:
#                 result[ath] = "Bronze Medal"
#             else:
#                 result[ath] = str(i + 1)
        
#         return result
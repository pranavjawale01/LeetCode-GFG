class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        n = len(skills)
        frq = 0
        winner = 0
        for i in range(1, n):
            if skills[winner] > skills[i]:
                frq += 1
            else:
                winner = i
                frq = 1
            if frq == k:
                return winner
        return winner
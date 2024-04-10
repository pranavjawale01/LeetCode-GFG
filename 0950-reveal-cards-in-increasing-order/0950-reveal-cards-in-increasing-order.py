class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        n = len(deck)
        ans = [0] * n
        i , j = 0, 0
        skip = False
        while i < n:
            if ans[j] == 0:
                if skip == False:
                    ans[j] = deck[i]
                    i += 1
                skip = ~skip 
            j = (j + 1) % n
        return ans
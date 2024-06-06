class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n = len(hand)
        if n % groupSize != 0:
            return False
        count = Counter(hand)
        while count:
            curr = min(count)
            for i in range(curr, curr + groupSize):
                if count[i] == 0:
                    return False
                count[i] -= 1
                if count[i] == 0:
                    del count[i]
        return True
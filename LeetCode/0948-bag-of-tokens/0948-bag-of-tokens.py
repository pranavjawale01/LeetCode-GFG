class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        n, score, max_score = len(tokens), 0, 0
        l , r = 0, n -1
        tokens.sort()
        while l <= r:
            if power >= tokens[l]:
                power -= tokens[l]
                l += 1
                score += 1
                max_score = max(max_score, score)
            elif score >= 1:
                power += tokens[r]
                r -= 1
                score -= 1
            else:
                return max_score
        return max_score  
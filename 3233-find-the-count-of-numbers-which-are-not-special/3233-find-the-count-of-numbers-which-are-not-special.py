class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        threshold = int(math.sqrt(r))
        
        prime = [True] * (threshold + 1)
        prime[0] = prime[1] = False
        
        for i in range(2, int(math.sqrt(threshold)) + 1):
            if prime[i]:
                for j in range(i * i, threshold + 1, i):
                    prime[j] = False
        
        count = 0
        for i in range(2, threshold + 1):
            if prime[i]:
                sq = i * i
                if l <= sq <= r:
                    count += 1
        
        total_numbers = r - l + 1
        
        return total_numbers - count
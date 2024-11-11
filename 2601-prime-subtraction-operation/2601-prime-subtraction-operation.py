class Solution:
    def __init__(self):
        self.prime = [True] * 1000
        self.prime[0] = self.prime[1] = False
        self.prime_list = []
        self.sieve()
    
    def sieve(self):
        for i in range(2, int(1000**0.5) + 1):
            if self.prime[i]:
                for j in range(i * i, 1000, i):
                    self.prime[j] = False
        self.prime_list = [i for i in range(2, 1000) if self.prime[i]]
    
    def primeSubOperation(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                continue
            
            found = False
            for p in self.prime_list:
                if p >= nums[i]:
                    break
                
                if nums[i] - p < nums[i + 1]:
                    nums[i] -= p
                    found = True
                    break
            
            if not found:
                return False
        
        return True
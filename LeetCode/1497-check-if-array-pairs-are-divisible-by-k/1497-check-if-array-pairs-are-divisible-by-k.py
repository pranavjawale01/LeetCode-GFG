class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        brr = [0] * k
        for x in arr:
            rem = ((x % k) + k) % k
            brr[rem] += 1
        
        if brr[0] % 2 != 0:
            return False
        
        for rem in range(1, (k // 2) + 1):
            if brr[rem] != brr[k - rem]:
                return False
        
        return True
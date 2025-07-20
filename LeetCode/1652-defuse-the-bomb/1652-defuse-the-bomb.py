class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        if k == 0:
            return [0] * n
        
        extended_code = code + code
        result = [0] * n
        
        for i in range(n):
            if k > 0:
                result[i] = sum(extended_code[i + j + 1] for j in range(k))
            elif k < 0:
                result[i] = sum(extended_code[i + n + j] for j in range(k, 0))
        
        return result
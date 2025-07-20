class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        freq_map = defaultdict(int)
        result = []
        n = len(A)
        count = 0

        for i in range(n):
            freq_map[A[i]] += 1
            freq_map[B[i]] += 1

            if A[i] == B[i]:
                count += 1
            else:
                if freq_map[A[i]] == 2:
                    count += 1
                if freq_map[B[i]] == 2:
                    count += 1

            result.append(count)
        
        return result
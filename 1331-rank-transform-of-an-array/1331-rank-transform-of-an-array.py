class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr:
            return []

        sorted_unique = sorted(set(arr))
        rank_map = {val: rank + 1 for rank, val in enumerate(sorted_unique)}

        return [rank_map[x] for x in arr]
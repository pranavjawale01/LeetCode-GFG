class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        vec = sorted(nums)
        
        group_num = 0
        num_to_group = {}
        num_to_group[vec[0]] = group_num
        
        group_to_list = defaultdict(deque)
        group_to_list[group_num].append(vec[0])
        
        for i in range(1, n):
            if abs(vec[i] - vec[i - 1]) > limit:
                group_num += 1
            num_to_group[vec[i]] = group_num
            group_to_list[group_num].append(vec[i])
        
        res = [0] * n
        for i in range(n):
            num = nums[i]
            group = num_to_group[num]
            res[i] = group_to_list[group].popleft()
        
        return res
class Solution:
    def map_value(self, num: int, mapping: List[int]) -> int:
        if num == 0:
            return mapping[0]
        ans = 0
        place = 1
        while num > 0:
            ans += mapping[num % 10] * place
            place *= 10
            num //= 10
        return ans


    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        mapped_nums = [(self.map_value(num, mapping), num) for num in nums]
        mapped_nums.sort(key=lambda x: x[0])
        sorted_nums = [num for _, num in mapped_nums]
        return sorted_nums
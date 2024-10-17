class Solution:
    def maximumSwap(self, num: int) -> int:
        s = str(num)
        length = len(s)
        max_right = [0] * length
        max_right[length - 1] = length - 1
        
        for i in range(length - 2, -1, -1):
            right_max_idx = max_right[i + 1]
            right_max_element = s[right_max_idx]
            max_right[i] = i if s[i] > right_max_element else right_max_idx
            
        for i in range(length):
            max_right_idx = max_right[i]
            max_right_element = s[max_right_idx]
            if s[i] < max_right_element:
                s_list = list(s)
                s_list[i], s_list[max_right_idx] = s_list[max_right_idx], s_list[i]
                return int(''.join(s_list))        
        return num
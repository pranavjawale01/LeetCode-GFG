class Solution:
    def maximumSwap(self, num: int) -> int:
        max_right = [-1] * 10
        s = str(num)
        n = len(s)
        
        for i in range(n):
            idx = int(s[i])
            max_right[idx] = i
            
        for i in range(n):
            curr_digit = int(s[i])
            for digit in range(9, curr_digit, -1):
                if max_right[digit] > i:
                    s_list = list(s)
                    s_list[i], s_list[max_right[digit]] = s_list[max_right[digit]], s_list[i]
                    return int(''.join(s_list))
                    
        return num







# class Solution:
#     def maximumSwap(self, num: int) -> int:
#         s = str(num)
#         length = len(s)
#         max_right = [0] * length
#         max_right[length - 1] = length - 1
        
#         for i in range(length - 2, -1, -1):
#             right_max_idx = max_right[i + 1]
#             right_max_element = s[right_max_idx]
#             max_right[i] = i if s[i] > right_max_element else right_max_idx
            
#         for i in range(length):
#             max_right_idx = max_right[i]
#             max_right_element = s[max_right_idx]
#             if s[i] < max_right_element:
#                 s_list = list(s)
#                 s_list[i], s_list[max_right_idx] = s_list[max_right_idx], s_list[i]
#                 return int(''.join(s_list))        
#         return num
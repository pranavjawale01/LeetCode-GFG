class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        left, right = 0, len(s1) - 1
        while s1[left] == s2[left]:
            left += 1
        while s1[right] == s2[right]:
            right -= 1
        s2_list = list(s2)        
        s2_list[left], s2_list[right] = s2_list[right], s2_list[left]
        return s1 == ''.join(s2_list)
class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        st = set()
        for x in arr1:
            while x not in st and x > 0:
                st.add(x)
                x //= 10
        ans = 0
        for x in arr2:
            while x not in st and x > 0:
                x //= 10
            if x > 0:
                ans = max(ans, int(log10(x)) + 1)
        return ans
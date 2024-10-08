class Solution:
    def minSwaps(self, s: str) -> int:
        st = []
        for c in s:
            if c == '[':
                st.append(c)
            elif st:
                st.pop()
        return (len(st) + 1) // 2
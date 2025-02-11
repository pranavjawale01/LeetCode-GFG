class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        st = []
        n = len(part)

        for ch in s:
            st.append(ch)
            if len(st) >= n and "".join(st[-n:]) == part:
                for _ in range(n):
                    st.pop()

        return "".join(st)




# class Solution:
#     def removeOccurrences(self, s: str, part: str) -> str:
#         while part in s:
#             s = s.replace(part, "", 1)
#         return s
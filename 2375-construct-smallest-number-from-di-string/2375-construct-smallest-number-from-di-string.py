class Solution:
    def smallestNumber(self, pattern: str) -> str:
        n = len(pattern)
        ans = []
        counter = 1
        st = []

        for i in range(n + 1):
            st.append(str(counter))
            counter += 1
            if i == n or pattern[i] == 'I':
                while st:
                    ans.append(st.pop())

        return "".join(ans)
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        st = []
        n = len(s)
        idx = set()
        for i in range(n):
            if s[i] == '(':
                st.append(i)
            elif s[i] == ')':
                if st and s[st[-1]] == '(':
                    st.pop()
                else:
                    idx.add(i)
        idx.update(st)
        ans = ""
        for i in range(n):
            if i not in idx:
                ans += s[i]
        return ans
class Solution:
    def checkValidString(self, s: str) -> bool:
        open_st = []
        star = []
        for i in range(len(s)):
            if s[i] == '(':
                open_st.append(i)
            elif s[i] == '*':
                star.append(i)
            elif s[i] == ')':
                if open_st:
                    open_st.pop()
                elif star:
                    star.pop()
                else:
                    return False
        while open_st:
            if not star:
                return False
            elif open_st[-1] < star[-1]:
                open_st.pop()
                star.pop()
            else:
                return False
        return True
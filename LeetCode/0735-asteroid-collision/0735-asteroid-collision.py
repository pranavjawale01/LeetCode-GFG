class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        st = []
        ans = []

        for x in asteroids:
            if x > 0:
                st.append(x)
            else:
                while st and st[-1] > 0 and st[-1] < abs(x):
                    st.pop()
                if not st or st[-1] < 0:
                    ans.append(x)
                elif st[-1] == abs(x):
                    st.pop()

        n = len(ans)
        while st:
            ans.append(st.pop())

        ans[n:] = reversed(ans[n:])

        return ans
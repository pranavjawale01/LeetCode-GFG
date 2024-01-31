class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        output = [0] * n
        st = []

        for i in range(n-1, -1, -1):
            while st and temperatures[st[-1]] <= temperatures[i]:
                st.pop()
            if not st:
                output[i] = 0
            else:
                output[i] = st[-1] - i
            st.append(i)
        
        return output
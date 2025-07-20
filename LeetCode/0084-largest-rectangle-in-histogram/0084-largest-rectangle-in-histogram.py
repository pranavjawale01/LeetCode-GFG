class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n , i , ans = len(heights) , 0 , 0
        st = []
        
        while i < n:
            while st and heights[st[-1]] > heights[i]:
                t = st.pop()
                height = heights[t]
                
                if not st:
                    ans = max(ans , height * i)
                else:
                    length = i - st[-1] -1
                    ans = max(ans , height * length)
            st.append(i)
            i += 1
            
        while st:
            t = st.pop()
            height = heights[t]
            
            if not st:
                ans = max(ans , height * i)
            else:
                length = i - st[-1] -1
                ans = max(ans , height * length)
                
        return ans
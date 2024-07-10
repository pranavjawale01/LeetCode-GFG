class Solution:
    def minOperations(self, logs: List[str]) -> int:
        st = []
        for x in logs:
            if x == "../":
                if st:
                    st.pop()
            elif x != "./":
                st.append(x)
        return len(st)



###
class Solution:
    def minOperations(self, logs: List[str]) -> int:
        depth = 0
        for x in logs:
            if x == "../":
                depth = max(0, depth - 1)
            elif x != "./":
                depth += 1
        return depth
###
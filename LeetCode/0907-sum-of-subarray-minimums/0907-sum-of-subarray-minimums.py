class Solution:
    def getNSL(self, arr, n):
        result = [-1] * n
        st = []

        for i in range(n):
            if not st:
                result[i] = -1
            else:
                while st and arr[st[-1]] > arr[i]:
                    st.pop()

                result[i] = -1 if not st else st[-1]

            st.append(i)

        return result

    def getNSR(self, arr, n):
        result = [n] * n
        st = []

        for i in range(n - 1, -1, -1):
            if not st:
                result[i] = n
            else:
                while st and arr[st[-1]] >= arr[i]:
                    st.pop()

                result[i] = n if not st else st[-1]

            st.append(i)

        return result
    
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)

        NSL = self.getNSL(arr, n)
        NSR = self.getNSR(arr, n)

        M = 10**9 + 7
        total_sum = 0

        for i in range(n):
            d1 = i - NSL[i]
            d2 = NSR[i] - i

            total_ways_for_i_min = d1 * d2
            sum_i_in_total_ways = arr[i] * total_ways_for_i_min

            total_sum = (total_sum + sum_i_in_total_ways) % M

        return total_sum
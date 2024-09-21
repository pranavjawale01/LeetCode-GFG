class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        for i in range(1, n+1):
            ans.append(i)
        ans.sort(key=str)
        return ans
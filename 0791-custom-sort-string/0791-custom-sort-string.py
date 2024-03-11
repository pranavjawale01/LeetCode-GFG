class Solution:
    def customSortString(self, order: str, s: str) -> str:
        mp = defaultdict(int)
        for ch in s:
            mp[ch] += 1
        ans = ""
        for ch in order:
            if mp[ch] > 0:
                ans += ch * mp[ch]
                del mp[ch]
        for ch, count in mp.items():
            ans += ch * count
        return ans
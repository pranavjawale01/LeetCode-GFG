class Solution:
    def solve(self, mp: dict, s: int, e: int, vis: List[bool]) -> bool:
        vis[s] = True
        if s == e:
            return True
        reachable = False
        for x in mp.get(s, []):
            if not vis[x]:
                reachable |= self.solve(mp, x, e, vis)
        return reachable

    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        mp = {}
        for u, v in prerequisites:
            if u not in mp:
                mp[u] = []
            mp[u].append(v)
        
        ans = []
        for u, v in queries:
            vis = [False] * numCourses
            ans.append(self.solve(mp, u, v, vis))
        return ans
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        vec = [0] * 1001
        sum_ = 0
        for x in skill:
            sum_ += x
            vec[x] += 1
        
        teams = n // 2
        if sum_ % teams != 0:
            return -1
        
        target = sum_ // teams
        chem = 0
        for i in range(n):
            currSkill = skill[i]
            remainSkill = target - currSkill
            if remainSkill < 0 or remainSkill >= len(vec) or vec[remainSkill] <= 0:
                return -1
            chem += currSkill * remainSkill
            vec[remainSkill] -= 1
        
        return chem // 2





# class Solution:
#     def dividePlayers(self, skill: List[int]) -> int:
#         n = len(skill)
#         skill.sort()
#         i, j = 0, n - 1
#         s = skill[i] + skill[j]
#         chem = 0
#         while i < j:
#             currSkill = skill[i] + skill[j]
#             if currSkill != s:
#                 return -1
#             chem += skill[i] * skill[j]
#             i += 1
#             j -= 1
#         return chem
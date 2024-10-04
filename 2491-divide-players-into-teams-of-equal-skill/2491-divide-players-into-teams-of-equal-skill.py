class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        skill.sort()
        i, j = 0, n - 1
        s = skill[i] + skill[j]
        chem = 0
        while i < j:
            currSkill = skill[i] + skill[j]
            if currSkill != s:
                return -1
            chem += skill[i] * skill[j]
            i += 1
            j -= 1
        return chem
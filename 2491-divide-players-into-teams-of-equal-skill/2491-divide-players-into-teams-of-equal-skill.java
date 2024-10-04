class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        Arrays.sort(skill);
        int i = 0, j = n - 1;
        int s = skill[i] + skill[j];
        long chem = 0;
        while (i < j) {
            int currSkill = skill[i] + skill[j];
            if (currSkill != s) return -1;
            chem += (long)(skill[i]) * (long)(skill[j]);
            i++;
            j--;
        }
        return chem;
    }
}
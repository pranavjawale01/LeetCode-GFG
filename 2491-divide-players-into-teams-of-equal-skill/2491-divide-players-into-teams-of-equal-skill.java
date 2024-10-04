class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        int[] vec = new int[1001];
        int sum = 0;
        for (int x : skill) {
            sum += x;
            vec[x]++;
        }
        int teams = n / 2;
        if (sum % teams != 0) return -1;
        int target = sum / teams;
        long chem = 0;
        for (int i = 0; i < n; i++) {
            int currSkill = skill[i];
            int remainSkill = target - currSkill;
            if (vec[remainSkill] <= 0) {
                return -1;
            }
            chem += (long)(currSkill) * (long)(remainSkill);
            vec[remainSkill] -= 1;
        }
        return chem / 2;
    }
}









// class Solution {
//     public long dividePlayers(int[] skill) {
//         int n = skill.length;
//         Arrays.sort(skill);
//         int i = 0, j = n - 1;
//         int s = skill[i] + skill[j];
//         long chem = 0;
//         while (i < j) {
//             int currSkill = skill[i] + skill[j];
//             if (currSkill != s) return -1;
//             chem += (long)(skill[i]) * (long)(skill[j]);
//             i++;
//             j--;
//         }
//         return chem;
//     }
// }
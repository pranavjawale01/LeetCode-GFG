class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        vector<int> vec(1001, 0);
        int SUM = 0;
        for (int& s : skill) {
            SUM += s;
            vec[s]++;
        }

        int teams = n / 2;

        if (SUM % teams != 0) {
            return -1;
        }

        int target = SUM / teams;
        long long chem = 0;

        for (int i = 0; i < n; i++) {
            int currSkill = skill[i];
            int remainSkill = target - currSkill;

            if (vec[remainSkill] <= 0) {
                return -1;
            }

            chem += (long long)currSkill * (long long)(remainSkill);
            vec[remainSkill] -= 1;
        }

        return chem / 2;
    }
};

// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill) {
//         int n = skill.size();
//         sort(skill.begin(), skill.end());
//         int i = 0, j = n - 1;
//         int s = skill[i] + skill[j];
//         long long chem = 0;
//         while (i < j) {
//             int currSkill = skill[i] + skill[j];
//             if (currSkill != s) return -1;
//             chem += (long long) (skill[i]) * (long long) (skill[j]);
//             i++;
//             j--;
//         }
//         return chem;
//     }
// };
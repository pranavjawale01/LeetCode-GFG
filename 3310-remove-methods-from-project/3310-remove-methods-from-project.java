class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        Set<Integer> bug = new HashSet<>();
        bug.add(k);
        boolean flag;

        do {
            flag = false;
            for (int[] x : invocations) {
                int a = x[0], b = x[1];
                if (bug.contains(a) && !bug.contains(b)) {
                    bug.add(b);
                    flag = true;
                }
            }
        } while (flag);

        for (int[] x : invocations) {
            int a = x[0], b = x[1];
            if (!bug.contains(a) && bug.contains(b)) {
                List<Integer> ans = new ArrayList<>();
                for (int i = 0; i < n; i++) ans.add(i);
                return ans;
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!bug.contains(i)) ans.add(i);
        }
        return ans;
    }
}
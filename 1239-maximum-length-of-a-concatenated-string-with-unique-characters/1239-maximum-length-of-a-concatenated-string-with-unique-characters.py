class Solution {
    public int maxLength(List<String> arr) {
        List<Integer> uniqueCharStrings = new ArrayList<>();

        for (String s : arr) {
            Set<Character> set = new HashSet<>();
            
            for (char ch : s.toCharArray()) {
                set.add(ch);
            }

            if (set.size() != s.length()) {
                continue;
            }

            int val = 0;
            for (char ch : s.toCharArray()) {
                val |= 1 << (ch - 'a');
            }

            uniqueCharStrings.add(val);
        }

        int[] result = { 0 }; 
        dfs(0, 0, result, uniqueCharStrings);
        return result[0];
    }

    private void dfs(int idx, int temp, int[] result, List<Integer> uniqueCharStrings) {
        result[0] = Math.max(result[0], Integer.bitCount(temp));

        for (int i = idx; i < uniqueCharStrings.size(); i++) {
            if ((temp & uniqueCharStrings.get(i)) == 0) {
                dfs(i + 1, temp | uniqueCharStrings.get(i), result, uniqueCharStrings);
            }
        }
    }
}
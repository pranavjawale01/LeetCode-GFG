class Solution {
    public int countOfSubstrings(String word, int k) {
        int n = word.length();
        HashSet<Character> vowelsSet = new HashSet<>();
        vowelsSet.add('a');
        vowelsSet.add('e');
        vowelsSet.add('i');
        vowelsSet.add('o');
        vowelsSet.add('u');
        
        int ans = 0;

        for (int i = 0; i < n; i++) {
            HashSet<Character> vow = new HashSet<>();
            int conso = 0;

            for (int j = i; j < n; j++) {
                char currentChar = word.charAt(j);
                if (vowelsSet.contains(currentChar)) {
                    vow.add(currentChar);
                } else {
                    conso++;
                }
                
                if (vow.size() == 5 && conso == k) {
                    ans++;
                }
                
                if (conso > k) {
                    break;
                }
            }
        }
        return ans;
    }
}
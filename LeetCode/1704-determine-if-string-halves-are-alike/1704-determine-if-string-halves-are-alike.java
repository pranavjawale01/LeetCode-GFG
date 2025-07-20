class Solution {
    public boolean halvesAreAlike(String s) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
        int count = 0, mid = s.length() / 2;
        for (int i = 0; i < mid; i++) {
            char A = s.charAt(i);
            char B = s.charAt(mid + i);
            if (vowels.contains(A)) {
                count++;
            }
            if (vowels.contains(B)) {
                count--;
            }
        }
        return count == 0;
    }
}
class Solution {
    public List<String> stringSequence(String target) {
        List<String> ans = new ArrayList<>();
        int n = target.length();
        StringBuilder temp = new StringBuilder();
        
        for (int i = 0; i < n; i++) {
            temp.append('a');
            ans.add(temp.toString());
            
            while (temp.charAt(temp.length() - 1) != target.charAt(i)) {
                temp.setCharAt(temp.length() - 1, (char) (temp.charAt(temp.length() - 1) + 1));
                ans.add(temp.toString());
            }
        }
        
        return ans;
    }
}
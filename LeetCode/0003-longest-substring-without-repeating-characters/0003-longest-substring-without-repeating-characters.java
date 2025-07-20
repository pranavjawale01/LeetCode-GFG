class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int left = 0;
        int maxLength = 0;
        Map<Character,Integer> map = new HashMap<Character,Integer>();

        for(int right=0; right<n; right++)
        {
            char currentChar = s.charAt(right);
            if (map.containsKey(currentChar)) 
            {
                left = Math.max(left, map.get(currentChar) + 1);
            }
            map.put(currentChar, right);
            int currentLength = right - left + 1;
            maxLength = Math.max(maxLength, currentLength);
        }
        return maxLength;
    }
}
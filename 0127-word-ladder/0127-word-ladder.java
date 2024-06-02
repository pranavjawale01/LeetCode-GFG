class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> dict = new HashSet<>(wordList);
        
        if (!dict.contains(endWord)) {
            return 0;
        }
        
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        int count = 1;
        
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                String temp = q.poll();
                if (temp.equals(endWord)) {
                    return count;
                }
                dict.remove(temp);
                
                for (int j = 0; j < temp.length(); j++) {
                    char[] charArray = temp.toCharArray();
                    char originalChar = charArray[j];
                    for (char k = 'a'; k <= 'z'; k++) {
                        charArray[j] = k;
                        String newWord = new String(charArray);
                        if (dict.contains(newWord)) {
                            q.offer(newWord);
                            dict.remove(newWord);
                        }
                    }
                    charArray[j] = originalChar;
                }
            }
            count++;
        }
        
        return 0;
    }
}
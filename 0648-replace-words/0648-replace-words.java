class Solution {
    class TrieNode {
        TrieNode[] child;
        boolean isEnd;

        TrieNode() {
            child = new TrieNode[26];
            isEnd = false;
        }
    }

    TrieNode root;

    Solution() {
        root = new TrieNode();
    }

    void insert(String word) {
        TrieNode crawler = root;
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if (crawler.child[idx] == null) {
                crawler.child[idx] = new TrieNode();
            }
            crawler = crawler.child[idx];
        }
        crawler.isEnd = true;
    }

    String search(String word) {
        TrieNode crawler = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word.charAt(i) - 'a';
            if (crawler.child[idx] == null) {
                return word;
            }
            crawler = crawler.child[idx];
            if (crawler.isEnd) {
                return word.substring(0, i + 1);
            }
        }
        return word;
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        for (String word : dictionary) {
            insert(word);
        }
        String[] words = sentence.split(" ");
        StringBuilder result = new StringBuilder();
        for (String word : words) {
            if (result.length() > 0) {
                result.append(" ");
            }
            result.append(search(word));
        }
        return result.toString();
    }
}



// class Solution {
//     public String findWord(String word, Set<String> st) {
//         for (int i = 1; i <= word.length(); i++) {
//             if (st.contains(word.substring(0, i))) {
//                 return word.substring(0, i);
//             }
//         }
//         return word;
//     }
    
//     public String replaceWords(List<String> dictionary, String sentence) {
//         Set<String> st = new HashSet<>(dictionary);
//         StringBuilder result = new StringBuilder();
//         String[] words = sentence.split(" ");
//         for (String word : words) {
//             result.append(findWord(word, st)).append(" ");
//         }
//         return result.toString().trim();
//     }
// }
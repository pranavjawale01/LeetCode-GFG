class Solution {
    public int prefixCount(String[] words, String pref) {
        Trie trie = new Trie();
        for (String word : words) {
            trie.addWord(word);
        }
        return trie.countPrefix(pref);
    }

    private class Trie {
        private class Node {
            Node[] links;
            int count;

            Node() {
                links = new Node[26];
                count = 0;
            }
        }

        private Node root;

        Trie() {
            root = new Node();
        }

        void addWord(String word) {
            Node curr = root;
            for (char c : word.toCharArray()) {
                if (curr.links[c - 'a'] == null) {
                    curr.links[c - 'a'] = new Node();
                }
                curr = curr.links[c - 'a'];
                curr.count++;
            }
        }

        int countPrefix(String pref) {
            Node curr = root;
            for (char c : pref.toCharArray()) {
                if (curr.links[c - 'a'] == null) {
                    return 0;
                }
                curr = curr.links[c - 'a'];
            }
            return curr.count;
        }
    }
}






// class Solution {
//     public int prefixCount(String[] words, String pref) {
//         int n = pref.length();
//         int count = 0;
//         for (String x : words) {
//             if (x.length() >= n && x.substring(0, n).equals(pref)) {
//                 count++;
//             }
//         }
//         return count;
//     }
// }
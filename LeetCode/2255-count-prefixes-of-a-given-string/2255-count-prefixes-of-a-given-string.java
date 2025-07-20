class Solution {
    public int countPrefixes(String[] words, String s) {
        Trie trie = new Trie();
        int count = 0;
        trie.addWord(s);
        for (String x : words) {
            if (trie.find(x)) {
                count++;
            }
        }
        return count;
    }

    private class Trie {
        private class Node {
            Node[] links;
            Node() {
                links = new Node[26];
            }
        }

        private Node root;

        Trie() {
            root = new Node();
        }

        void addWord(String word) {
            Node curr = root;
            for (char c : word.toCharArray()) {
                if (curr.links[c-'a'] == null) {
                    curr.links[c-'a'] = new Node();
                }
                curr = curr.links[c-'a'];
            }
        }

        boolean find(String x) {
            Node curr = root;
            for (char c : x.toCharArray()) {
                if (curr.links[c-'a'] == null) {
                    return false;
                }
                curr = curr.links[c-'a'];
            }
            return true;
        }
    }
}






// class Solution {
//     public int countPrefixes(String[] words, String s) {
//         int count = 0;
//         for (String x : words) {
//             if (x.length() <= s.length() && s.substring(0, x.length()).equals(x)) {
//                 count++;
//             }
//         }
//         return count;
//     }
// }
class TrieNode {
    TrieNode[] children;
    public TrieNode() {
        children = new TrieNode[10];
    }
}

class Solution {
    public TrieNode getTrieNode() {
        return new TrieNode();
    }

    public void insert(int num, TrieNode root) {
        TrieNode crawl = root;
        String numstr = Integer.toString(num);
        for (char c : numstr.toCharArray()) {
            int idx = c - '0';
            if (crawl.children[idx] == null) {
                crawl.children[idx] = getTrieNode();
            }
            crawl = crawl.children[idx];
        }
    }

    public int search(int num, TrieNode root) {
        TrieNode crawl = root;
        String numstr = Integer.toString(num);
        int len = 0;
        for (char c : numstr.toCharArray()) {
            int idx = c - '0';
            if (crawl.children[idx] != null) {
                len++;
                crawl = crawl.children[idx];
            } else {
                break;
            }
        }
        return len;
    }

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        TrieNode root = getTrieNode();
        for (int num : arr1) {
            insert(num, root);
        }
        int ans = 0;
        for (int num : arr2) {
            ans = Math.max(ans, search(num, root));
        }
        return ans;
    }
}








// class Solution {
//     public int longestCommonPrefix(int[] arr1, int[] arr2) {
//         Set<Integer> st = new HashSet<>();
        
//         for (int x : arr1) {
//             int val = x;
//             while (!st.contains(val) && val > 0) {
//                 st.add(val);
//                 val /= 10;
//             }
//         }

//         int ans = 0;

//         for (int x : arr2) {
//             int num = x;
//             while (!st.contains(num) && num > 0) {
//                 num /= 10;
//             }
//             if (num > 0) {
//                 ans = Math.max(ans, (int) Math.log10(num) + 1);
//             }
//         }
        
//         return ans;
//     }
// }
class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> bankSet = new HashSet<>(Arrays.asList(bank));
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        queue.offer(startGene);
        visited.add(startGene);

        int level = 0;

        while (!queue.isEmpty()) {
            int n = queue.size();
            while (n-- > 0) {
                String curr = queue.poll();
                if (curr.equals(endGene)) {
                    return level;
                }
                char[] chars = curr.toCharArray();
                for (int i = 0; i < curr.length(); i++) {
                    char originalChar = chars[i];
                    for (char ch : "ACGT".toCharArray()) {
                        if (ch != originalChar) {
                            chars[i] = ch;
                            String neighbour = new String(chars);
                            if (bankSet.contains(neighbour) && !visited.contains(neighbour)) {
                                visited.add(neighbour);
                                queue.offer(neighbour);
                            }
                        }
                    }
                    chars[i] = originalChar;
                }
            }
            level++;
        }
        return -1;
    }
}
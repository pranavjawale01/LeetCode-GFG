class Solution {
    public void fillNeighbors(Queue<String> que, StringBuilder curr, Set<String> dead) {
        for (int i = 0; i < 4; i++) {
            char ch = curr.charAt(i);

            char dec = ch == '0' ? '9' : (char) (ch - 1);
            char inc = ch == '9' ? '0' : (char) (ch + 1);

            curr.setCharAt(i, dec);
            String decStr = curr.toString();
            if (!dead.contains(decStr)) {
                dead.add(decStr);
                que.add(decStr);
            }

            curr.setCharAt(i, inc);
            String incStr = curr.toString();
            if (!dead.contains(incStr)) {
                dead.add(incStr);
                que.add(incStr);
            }
            curr.setCharAt(i, ch);
        }
    }

    public int openLock(String[] deadends, String target)  {
        Set<String> dead = new HashSet<>(Arrays.asList(deadends));

        StringBuilder start = new StringBuilder("0000");
        if (dead.contains(start.toString()))
            return -1;

        Queue<String> que = new LinkedList<>();
        que.add(start.toString());

        int level = 0;
        while (!que.isEmpty()) {
            int n = que.size();

            while (n-- > 0) {
                String curr = que.poll();
                assert curr != null;
                if (curr.equals(target))
                    return level;

                fillNeighbors(que, new StringBuilder(curr), dead);
            }
            level++;
        }
        return -1;
    }
}
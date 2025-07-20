class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        List<Pair> vec = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            vec.add(new Pair(names[i], heights[i]));
        }
        vec.sort((a, b) -> b.height - a.height);
        for (int i = 0; i < n; i++) {
            names[i] = vec.get(i).name;
        }
        return names;
    }

    static class Pair {
        String name;
        int height;

        Pair(String name, int height) {
            this.name = name;
            this.height = height;
        }
    }
}
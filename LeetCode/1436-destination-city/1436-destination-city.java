class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> cities = new HashSet<String>();
        
        for (List<String> path: paths) {
            cities.add(path.get(0));
        }
        
        for (List<String> path: paths) {
            if (!cities.contains(path.get(1))) {
                return path.get(1);
            }
        }
        
        return "";
    }
}
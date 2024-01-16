class RandomizedSet {
    List<Integer> list = new ArrayList<>();
    Map<Integer, Integer> mp = new HashMap<>();
    Random rand = new Random();
    public RandomizedSet() {
        
    }
    
    public boolean insert(int val) {
        if (mp.containsKey(val)) {
            return false;
        }
        list.add(val);
        mp.put(val, list.size() - 1);
        return true;
    }
    
    public boolean remove(int val) {
        if (mp.containsKey(val)) {
            int lastElement = list.get(list.size() - 1);
            int index = mp.get(val);
            list.set(index, lastElement);
            mp.put(lastElement, index);
            list.remove(list.size() - 1);
            mp.remove(val);
            return true;
        }
        return false;
    }
    
    public int getRandom() {
        int n = list.size();
        int randomIndex = rand.nextInt(n);
        return list.get(randomIndex);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
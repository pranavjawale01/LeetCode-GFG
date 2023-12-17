struct cmp {
    bool operator()(pair<int, string> a, pair<int, string> b) const {
        if (a.first > b.first) return 1;
        if (a.first < b.first) return 0;
        return (a.second < b.second);
    }
};

class FoodRatings {
public:
    
    // cuisine to (rating and food)
    unordered_map<string, set<pair<int,string>, cmp>> s;
    // food to (cuisine and rating)
    unordered_map<string, pair<string, int>> m;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            m[foods[i]] = {cuisines[i], ratings[i]};
            s[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = m[food].first;
        int oldRating = m[food].second;
        s[cuisine].erase({oldRating, food});
        
        m[food] = {cuisine, newRating};
        s[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return s[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
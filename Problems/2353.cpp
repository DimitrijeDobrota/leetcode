class FoodRatings {
    unordered_map<string, set<pair<int, string>>> order;
    unordered_map<string, string> category;
    unordered_map<string, int> rating;

  public:
    FoodRatings(const vector<string> &foods, const vector<string> &cuisines, const vector<int> &ratings) {
        for (int i = 0; i < foods.size(); i++) {
            order[cuisines[i]].emplace(-ratings[i], foods[i]);
            category.emplace(foods[i], cuisines[i]);
            rating.emplace(foods[i], ratings[i]);
        }
    }

    void changeRating(const string &food, int newRating) {
        auto &st = order[category[food]];
        st.erase(st.find({-rating[food], food}));
        rating[food] = newRating;
        st.emplace(-rating[food], food);
    }

    string highestRated(const string &cuisine) { return order[cuisine].begin()->second; }
};

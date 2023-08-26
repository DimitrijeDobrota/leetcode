class Solution {
  public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end());
        vector<bool> res(candies.size());
        for (int i = 0; i < candies.size(); i++)
            res[i] = (maxi - candies[i]) <= extraCandies;
        return res;
    }
};

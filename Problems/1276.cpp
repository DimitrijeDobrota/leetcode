class Solution {
  public:
    vector<int> numOfBurgers(const int tomatoSlices, int const cheeseSlices) const {
        if (tomatoSlices % 2) return {};
        if (cheeseSlices * 4 < tomatoSlices) return {};
        if (cheeseSlices * 2 > tomatoSlices) return {};

        return {tomatoSlices / 2 - cheeseSlices, cheeseSlices * 2 - tomatoSlices / 2};
    }
};

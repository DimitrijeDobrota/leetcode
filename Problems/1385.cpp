class Solution {
  public:
    int findTheDistanceValue(const vector<int> &arr1, vector<int> &arr2, int d) const {
        std::ranges::sort(arr2);
        return std::ranges::count_if(arr1, [&](auto num) {
            const auto it = std::ranges::lower_bound(arr2, num - d);
            return it == std::end(arr2) || *it > num + d;
        });
    }
};

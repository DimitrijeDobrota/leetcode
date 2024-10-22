class Solution {
  public:
    bool containsNearbyAlmostDuplicate(const vector<int> &nums, int indexDiff, int valueDiff) const {
        multiset<int> st;

        for (int i = 0; i < size(nums); i++) {
            const auto it = st.insert(nums[i]);
            if (it != begin(st) && nums[i] - *prev(it) <= valueDiff) return true;
            if (next(it) != end(st) && *next(it) - nums[i] <= valueDiff) return true;

            if (size(st) > indexDiff) st.extract(nums[i - indexDiff]);
        }

        return false;
    }
};

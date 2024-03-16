class Solution {
  public:
    int findMaxLength(const vector<int> &nums) const {
        unordered_map<int, int> um;
        int res = 0, sum = 0;

        um.emplace(0, -1);
        for (int i = 0; i < size(nums); i++) {
            sum += nums[i] ? 1 : -1;
            auto it = um.find(sum);
            if (it != end(um))
                res = max(res, i - it->second);
            else
                um.emplace(sum, i);
        }

        return res;
    }
};

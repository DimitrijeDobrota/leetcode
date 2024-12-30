class Solution {
  public:
    vector<int> getSneakyNumbers(vector<int> &nums) const {
        vector<int> res;

        for (const int n : nums) {
            const int m = n < 0 ? -n - 1 : n;
            if (nums[m] < 0)
                res.push_back(m);
            else
                nums[m] = -nums[m] - 1;
        }

        return res;
    }
};

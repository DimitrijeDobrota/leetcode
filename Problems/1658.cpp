class Solution {
  public:
    int minOperations(const vector<int> &nums, int x) {
        const int goal = accumulate(begin(nums), end(nums), 0) - x;
        if (goal < 0) return -1;
        if (goal == 0) return nums.size();

        int sum = 0, start = 0, end = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum > goal)
                sum -= nums[start++];
            if (sum == goal) res = max(res, i - start + 1);
        }

        return res != 0 ? nums.size() - res : -1;
    }
};

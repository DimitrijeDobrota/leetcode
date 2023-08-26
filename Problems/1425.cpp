class Solution {
  public:
    int constrainedSubsetSum(vector<int> &nums, int k) {
        deque<int> q;
        int res = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] += !q.empty() ? q.front() : 0;
            res = max(res, nums[i]);
            while (!q.empty() && nums[i] > q.back())
                q.pop_back();
            if (nums[i] > 0) q.push_back(nums[i]);
            if (i >= k && !q.empty() && q.front() == nums[i - k]) q.pop_front();
        }
        return res;
    }
};

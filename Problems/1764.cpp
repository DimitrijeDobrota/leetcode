class Solution {
  public:
    bool canChoose(const vector<vector<int>> &groups, const vector<int> &nums) const {
        const int n = size(groups);
        int group = 0, crnt = 0, start = 0;
        for (int i = 0; i < size(nums) && group < n; i++) {
            if (nums[i] != groups[group][crnt])
                crnt = 0, i = start, start++;
            else if (++crnt == size(groups[group]))
                group++, crnt = 0, start = i;
        }

        return group == n;
    }
};

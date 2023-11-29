class Solution {
  public:
    vector<int> arrayChange(vector<int> &nums, const vector<vector<int>> &operations) const {
        static int position[1000001];

        for (int i = 0; i < nums.size(); i++) {
            position[nums[i]] = i;
        }

        for (const auto &op : operations) {
            nums[position[op[0]]] = op[1];
            position[op[1]] = position[op[0]];
        }

        return nums;
    }
}

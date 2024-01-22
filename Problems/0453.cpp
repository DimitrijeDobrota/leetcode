class Solution {
  public:
    int minMoves(const vector<int> &nums) const {
        const int n = size(nums);
        const int sum = accumulate(begin(nums), end(nums), 0);
        const int mini = *min_element(begin(nums), end(nums));
        return sum - mini * n;
    }
};

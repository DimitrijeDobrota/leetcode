class NumArray {
    vector<int> prefix;

  public:
    NumArray(const vector<int> &nums) : prefix(size(nums) + 1) {
        for (int i = 0, acc = 0; i < size(nums); i++) {
            prefix[i + 1] = acc += nums[i];
        }
    }

    int sumRange(int left, int right) const { return prefix[right + 1] - prefix[left]; }
};

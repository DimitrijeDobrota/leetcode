class NumArray {
    std::vector<int> prefix;

public:
    NumArray(const vector<int>& nums)
        : prefix(std::size(nums) + 1UZ, 0)
    {
        for (const auto idx: std::views::iota(0UZ, std::size(nums))) {
            prefix[idx + 1] = prefix[idx] + nums[idx];
        }
    }
    
    int sumRange(int left, int right) const {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
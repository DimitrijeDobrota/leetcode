class Solution {
public:
    int minMoves2(vector<int>& nums) const {
        const auto mid = std::begin(nums) + std::size(nums) / 2;
        std::ranges::nth_element(nums, mid);
        return std::ranges::fold_left(nums, 0, [&](auto acc, auto num) {
            return acc + abs(num - *mid);
        });
    }
};
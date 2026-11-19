class Solution {
  public:
    int minimizeSum(const std::vector<int> &nums) const {
        std::array min = {nums[0], nums[1], nums[2]};
        std::array max = {nums[0], nums[1], nums[2]};

        std::ranges::sort(min);
        std::ranges::sort(max, std::greater{});

        for (const auto num : nums | std::views::drop(3)) {
            if (num < min[0])
                min[2] = min[1], min[1] = min[0], min[0] = num;
            else if (num < min[1])
                min[2] = min[1], min[1] = num;
            else if (num < min[2])
                min[2] = num;

            if (num > max[0])
                max[2] = max[1], max[1] = max[0], max[0] = num;
            else if (num > max[1])
                max[2] = max[1], max[1] = num;
            else if (num > max[2])
                max[2] = num;
        }

        return std::min({
            max[1] - min[1],
            max[0] - min[2],
            max[2] - min[0],
        });
    }
};

class Solution {
  public:
    int minimizeSum(const std::vector<int> &nums) const {
        std::array<int, 3> min;
        std::array<int, 3> max;

        std::ranges::partial_sort_copy(nums, min);
        std::ranges::partial_sort_copy(nums, max, std::greater{});

        return std::min({
            max[1] - min[1],
            max[0] - min[2],
            max[2] - min[0],
        });
    }
};

class Solution {
public:
    int longestSubarray(const std::vector<int>& nums, int limit) const {
        std::deque<int> min_queue;
        std::deque<int> max_queue;

        std::size_t left = 0;
        std::size_t result = 0;
        for (const auto right: std::views::iota(0UZ, std::size(nums))) {
            while (!std::empty(min_queue) && nums[right] < min_queue.back()) min_queue.pop_back();
            while (!std::empty(max_queue) && nums[right] > max_queue.back()) max_queue.pop_back();
            min_queue.emplace_back(nums[right]);
            max_queue.emplace_back(nums[right]);

            while (max_queue.front() - min_queue.front() > limit) {
                if (nums[left] == min_queue.front()) min_queue.pop_front();
                if (nums[left] == max_queue.front()) max_queue.pop_front();
                left++;
            }

            result = std::max(result, right - left + 1);
        }

        return result;
    }
};
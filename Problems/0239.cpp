class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) const {
        std::priority_queue<std::pair<int, int>> pq;
        
        for (const auto [idx, num]: std::views::enumerate(nums) | std::views::take(k)) {
            pq.emplace(num, idx);
        }

        std::vector<int> result;
        result.reserve(std::size(nums) - k + 1);
        result.emplace_back(pq.top().first);

        for (const auto [idx, num]: std::views::enumerate(nums) | std::views::drop(k)) {
            pq.emplace(num, idx);
            while (pq.top().second <= idx - k) {
                pq.pop();
            }
            result.emplace_back(pq.top().first);
        }

        return result;
    }
};

class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) const {
        std::vector<int> result(std::size(nums) - k + 1);

        std::deque<int> queue;
        for (const auto [idx, num]: std::views::enumerate(nums)) {
            if (idx >= k && queue.front() == nums[idx - k]) queue.pop_front();

            while (!std::empty(queue) && num > queue.back()) queue.pop_back();
            queue.emplace_back(num);

            if (idx >= k - 1) result[idx - k + 1] = queue.front();
        }

        return result;
    }
};
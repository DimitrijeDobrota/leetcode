class Solution {
  public:
    int maximumRobots(const std::vector<int> &chargeTimes, const std::vector<int> &runningCosts,
                      long long budget) const {
        std::deque<int> max_queue;
        std::size_t sum = 0;

        std::size_t left = 0;
        for (const auto right : std::views::iota(0UZ, std::size(chargeTimes))) {
            while (!std::empty(max_queue) && chargeTimes[right] > max_queue.back())
                max_queue.pop_back();
            max_queue.push_back(chargeTimes[right]);
            sum += runningCosts[right];

            if (max_queue.front() + (right - left + 1) * sum > budget) {
                if (max_queue.front() == chargeTimes[left]) max_queue.pop_front();
                sum -= runningCosts[left];
                left++;
            }
        }

        return std::size(chargeTimes) - left;
    }
};

class Solution {
  public:
    long long countNonDecreasingSubarrays(const vector<int> &nums, int k) const {
        const auto n = std::size(nums);
        long long operations = 0;
        long long result = 0;

        std::priority_queue<std::pair<int, int>> pq;
        std::vector<std::vector<int>> count(n);
        std::vector<std::size_t> position(n, n);
        std::vector<int> stack;

        for (std::size_t left = 0, right = 0; right < n; right++) {
            while (!std::empty(stack) && nums[right] >= nums[stack.back()]) {
                position[stack.back()] = right;
                stack.pop_back();
            }

            if (!std::empty(stack)) {
                count[stack.back()].emplace_back(right);
            }
            stack.push_back(right);

            pq.emplace(nums[right], right);
            operations += std::max(0, pq.top().first - nums[right]);

            while (operations > k) {
                for (const auto idx : count[left]) {
                    operations -= (nums[left] - nums[idx]) * (std::min(position[idx], right + 1) - idx);
                }
                left++;
            }

            while (!std::empty(pq) && pq.top().second < left) {
                pq.pop();
            }

            result += right - left + 1;
        }

        return result;
    }
};

class Solution {
  public:
    long long countNonDecreasingSubarrays(const vector<int> &nums, int k) const {
        std::deque<std::pair<int, int>> blocks;
        const auto n = std::size(nums);
        long long operations = 0;
        long long result = 0;

        for (int left = n - 1, right = n - 1; left >= 0; --left) {
            int length = 1;

            while (!blocks.empty() && blocks.front().first <= nums[left]) {
                const auto [height, count] = blocks.front();
                blocks.pop_front();

                operations += 1LL * (nums[left] - height) * count;
                length += count;
            }

            blocks.emplace_front(nums[left], length);

            while (operations > k) {
                auto &[height, count] = blocks.back();

                operations -= height - nums[right];
                --right;

                if (--count == 0) {
                    blocks.pop_back();
                }
            }

            result += right - left + 1;
        }

        return result;
    }
};

template <class T, auto Comp>
class MinQueue
{
    inline static std::array<int, 100'000> m_queue{};
    int head = 0;
    int tail = 0;

public:
    void push(T value) {
        while (head < tail && Comp(value, m_queue[tail - 1])) tail--;
        m_queue[tail++] = value;
    }

    T min() const {
        return m_queue[head];
    }

    void pop(T value) {
        if (value == m_queue[head]) head++;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) const {
        const auto n = std::size(nums);

        MinQueue<int, std::greater{}> queue;        
        std::vector<int> res;
        res.reserve(n - k + 1);

        for (int i = 0; i < k; i++) queue.push(nums[i]);

        res.emplace_back(queue.min());
        for (int i = k; i < n; i++) {
            queue.push(nums[i]);
            queue.pop(nums[i - k]);
            res.emplace_back(queue.min());
        }
        return res;
    }
};

class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& input, std::size_t k) const {
        if (k == 1) return input;

        const std::span<const int> nums{input};
        std::vector<int> result(std::size(nums) - k + 1UZ);
        std::vector<int> suffix(k);

        for (std::size_t start = 0; start < std::size(result); start += k) {
            const auto block = nums.subspan(start, k);
            auto maximum = block.back();
            suffix[k - 1] = maximum;

            for (auto i = k - 1; i > 0; i--) {
                maximum = std::max(maximum, block[i - 1]);
                suffix[i - 1] = maximum;
            }

            result[start] = maximum;

            const auto count = std::min(k, std::size(result) - start);
            const auto next = nums.subspan(start + k, count - 1);
            auto prefix_max = std::numeric_limits<int>::lowest();

            for (std::size_t offset = 1; offset < count; offset++) {
                prefix_max = std::max(prefix_max, next[offset - 1]);
                result[start + offset] = std::max(suffix[offset], prefix_max);
            }
        }

        return result;
    }
};
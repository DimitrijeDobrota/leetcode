class Solution {
public:
    int longestOnes(const vector<int>& nums, int k) const {
        std::size_t left = 0; 
        std::size_t zeros = 0; 
        std::size_t result = 0;
        for (const auto right: std::views::iota(0UZ, std::size(nums))) {
            zeros += nums[right] == 0;

            while (left <= right && zeros > k) {
                zeros -= nums[left++] == 0;
            }

            result = std::max(result, right - left + 1UZ);
        }
        return result;
    }
};

class Solution {
public:
    int longestOnes(const vector<int>& nums, int k) const {
        const auto capacity = k + 1;
        std::vector<int> zeros(capacity, 0);
        std::size_t head = 0;
        std::size_t tail = 0;

        std::size_t left = 0; 
        std::size_t result = 0;
        for (const auto right: std::views::iota(0UZ, std::size(nums))) {
            if (nums[right] == 0) {
                zeros[tail] = right;
                tail = (tail + 1) % capacity;

                if (tail == head) {
                    left = zeros[head] + 1;
                    head = (head + 1) % capacity;
                }
            }

            result = std::max(result, right - left + 1UZ);
        }
        return result;
    }
};
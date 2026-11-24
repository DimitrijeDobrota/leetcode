class Solution {
  public:
    int maxLength(const std::vector<int> &nums) const {
        std::size_t result = 0;
        for (const auto i : std::views::iota(0UZ, std::size(nums))) {
            long long product = nums[i];
            long long gcd = nums[i];
            long long lcm = nums[i];
            for (const auto j : std::views::iota(i + 1, std::size(nums))) {
                gcd = std::gcd(gcd, nums[j]);
                lcm = std::lcm(lcm, nums[j]);
                product *= nums[j];
                if (product > gcd * lcm) break;
                if (product == gcd * lcm) {
                    result = std::max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};

class Solution {
  public:
    int maxLength(const std::vector<int> &nums) const {
        std::size_t product = 1;
        std::size_t result = 2;
        std::size_t left = 0;
        for (const auto right : std::views::iota(0UZ, std::size(nums))) {
            while (std::gcd(product, nums[right]) > 1) {
                product /= nums[left];
                left++;
            }
            product *= nums[right];
            result = std::max(result, right - left + 1);
        }
        return result;
    }
};

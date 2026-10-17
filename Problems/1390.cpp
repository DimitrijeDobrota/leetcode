class Solution {
  public:
    int sumFourDivisors(const vector<int> &nums) const {
        static constexpr int max_num = 100'001;
        static std::array<int, max_num> count;
        static std::array<int, max_num> sum;

        std::ranges::fill(count, 0);
        std::ranges::fill(sum, 1);

        const int n = std::ranges::max(nums);
        for (int candid = 2; candid <= n; candid++) {
            for (int j = candid; j <= n; j += candid) {
                sum[j] += candid;
                count[j]++;
            }
        }

        int res = 0;
        for (const auto num : nums) {
            if (count[num] != 3) continue;
            res += sum[num];
        }

        return res;
    }
};

class Solution {
  public:
    int sumFourDivisors(const vector<int> &nums) const {
        int res = 0;
        for (const auto num : nums) {
            const auto limit = std::sqrt(num);
            int divisor = 0;
            for (int candid = 2; candid <= limit; candid++) {
                if (num % candid != 0) continue;
                if (divisor == 0)
                    divisor = candid;
                else {
                    divisor = 0;
                    break;
                }
            }
            if (divisor != 0 && divisor * divisor != num) {
                res += 1 + num + divisor + num / divisor;
            }
        }
        return res;
    }
};

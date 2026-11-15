class Solution {
  public:
    int numOfSubarrays(const std::vector<int> &arr) const {
        static constexpr int mod = 1e9 + 7;
        std::array<int, 2> prev{};
        std::array<int, 2> crnt{};
        std::size_t result = 0;

        for (const auto num : arr) {
            const auto parity = num & 1;

            crnt[parity] = (1 + prev[0]) % mod;
            crnt[!parity] = prev[1] % mod;

            result = (result + crnt[1]) % mod;

            std::swap(prev, crnt);
        }

        return result;
    }
};

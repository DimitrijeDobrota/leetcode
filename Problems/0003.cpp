class Solution {
public:
    int lengthOfLongestSubstring(string_view s) const {
        std::array<std::size_t, 128> afterLast{};
        std::size_t result = 0;

        std::size_t left = 0;
        for (const auto right: std::views::iota(0UZ, std::size(s))) {
            left = std::max(left, afterLast[s[right]]);
            afterLast[s[right]] = right + 1;
            result = std::max(result, right - left + 1);
        }

        return result;
    }
};

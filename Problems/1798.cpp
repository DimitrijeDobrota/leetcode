class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int target = 1;
        std::ranges::sort(coins);
        for (const auto coin: coins) {
            if (coin > target) break;
            target = target + coin;
        }

        return target;
    }
};

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        static std::array<int, 40'001> count;

        std::ranges::fill(count, 0);
        for (const auto coin: coins) count[coin]++;

        int target = 1;
        for (const auto [coin, cnt]: std::views::enumerate(count)) {
            if (!cnt) continue;
            if (coin > target) break;
            target = target + coin * cnt;
        }

        return target;
    }
};
// Has hash collision bug for: [3770,48659,1,1,48659,1,3770,1,3770,1,48659]
//
class Solution {
  public:
    int smallestUniqueSubarray(const std::vector<int> &nums) const {
        const auto n = std::size(nums);

        static constexpr auto base = 911382323UZ;
        static constexpr auto mod = 1000000007UZ;

        std::vector<std::size_t> hash(n + 1);
        std::vector<std::size_t> power(n + 1);

        power[0] = 1;
        for (const auto idx : std::views::iota(0UZ, n)) {
            hash[idx + 1] = (hash[idx] * base + nums[idx]) % mod;
            power[idx + 1] = power[idx] * base % mod;
        }

        std::unordered_map<std::size_t, int> count;
        const auto check = [&](const auto len) {
            count.clear();

            for (const auto left : std::views::iota(0UZ, n - len + 1UZ)) {
                const auto right = left + len;
                const auto key = (hash[right] - hash[left] * power[len] % mod + mod) % mod;
                count[key]++;
            }

            return std::ranges::contains(count | std::views::nums, 1);
        };

        auto low = 1UZ;
        auto high = n;
        while (low < high) {
            const auto mid = low + (high - low) / 2;
            if (check(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

// Reduce a chance of a bug by using 2 hashes, still not guaranteed
//
class Solution {
  public:
    int smallestUniqueSubarray(const std::vector<int> &nums) const {
        const auto n = std::size(nums);

        static constexpr std::array<std::uint64_t, 2> base = {911382323, 972663749};
        static constexpr std::array<std::uint64_t, 2> mod = {1000000007, 1000000009};

        std::vector<std::array<std::uint64_t, 2>> hash(n + 1);
        std::vector<std::array<std::uint64_t, 2>> power(n + 1);

        power[0] = {1, 1};
        for (const auto idx : std::views::iota(0UZ, n)) {
            for (const auto h : std::views::iota(0UZ, 2UZ)) {
                hash[idx + 1][h] = (hash[idx][h] * base[h] + nums[idx]) % mod[h];
                power[idx + 1][h] = power[idx][h] * base[h] % mod[h];
            }
        }

        std::array<std::uint64_t, 2> key;
        std::unordered_map<std::uint64_t, int> count;
        const auto check = [&](const auto len) {
            count.clear();

            for (const auto left : std::views::iota(0UZ, n - len + 1UZ)) {
                const auto right = left + len;
                for (const auto h : std::views::iota(0UZ, 2UZ)) {
                    key[h] = (hash[right][h] + mod[h] - hash[left][h] * power[len][h] % mod[h]) % mod[h];
                }
                count[key[0] * mod[1] + key[1]]++;
            }

            return std::ranges::contains(count | std::views::nums, 1);
        };

        auto low = 1UZ;
        auto high = n;
        while (low < high) {
            const auto mid = low + (high - low) / 2;
            if (check(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
class Solution {
  public:
    int smallestUniqueSubarray(std::vector<int> &nums) const {
        const auto n = std::size(nums);

        std::vector<int> suffix(n);
        std::ranges::iota(suffix, 0);

        auto rank = nums;
        std::size_t maxRank = std::ranges::max(rank);

        const auto rankAt = [&](const auto idx) { return idx < n ? rank[idx] : 0; };
        std::vector<int> count(std::max(n, maxRank) + 1);
        std::vector<int> buffer(n);
        const auto countingSort = [&] {
            const auto active = count | std::views::take(maxRank + 1);
            std::ranges::fill(active, 0);
            for (const auto bucket : rank)
                count[bucket]++;
            std::partial_sum(std::ranges::begin(active), std::ranges::end(active),
                             std::ranges::begin(active));
            for (const auto idx : suffix | std::views::reverse) {
                auto &bucketEnd = count[rank[idx]];
                buffer[--bucketEnd] = idx;
            }
            suffix.swap(buffer);
        };
        countingSort();

        std::vector<int> next(n);
        for (auto width = 1UZ; width < n; width *= 2) {
            std::ranges::iota(buffer | std::views::take(width), n - width);
            std::ranges::transform(
                suffix | std::views::filter([&](const std::size_t idx) { return idx >= width; }),
                std::ranges::begin(buffer) + width, [&](const auto idx) { return idx - width; });
            suffix.swap(buffer);
            countingSort();

            next[suffix[0]] = 1;
            for (const auto idx : std::views::iota(1UZ, n)) {
                const auto left = suffix[idx - 1];
                const auto right = suffix[idx];
                const auto different =
                    rank[left] != rank[right] || rankAt(left + width) != rankAt(right + width);
                next[right] = next[left] + different;
            }
            rank.swap(next);
            maxRank = rank[suffix.back()];
            if (maxRank == n) break;
        }

        std::vector<int> order(n);
        for (const auto idx : std::views::iota(0UZ, n))
            order[suffix[idx]] = idx;

        std::vector<int> lcp(n);
        auto matched = 0UZ;
        for (const auto left : std::views::iota(0UZ, n)) {
            const auto idx = order[left];
            if (idx == 0) {
                matched = 0;
                continue;
            }
            const std::size_t right = suffix[idx - 1];
            while (left + matched < n && right + matched < n &&
                   nums[left + matched] == nums[right + matched]) {
                matched++;
            }
            lcp[idx] = matched;
            if (matched) matched--;
        }

        auto answer = n;
        for (const auto idx : std::views::iota(0UZ, n)) {
            const auto repeated = std::max(lcp[idx], idx + 1 < n ? lcp[idx + 1] : 0);
            const auto length = repeated + 1UZ;
            if (length <= n - suffix[idx]) answer = std::min(answer, length);
        }
        return answer;
    }
};

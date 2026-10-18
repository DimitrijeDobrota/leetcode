class Solution {
  public:
    vector<int> closestPrimes(int left, int right) {
        static std::array<std::uint8_t, 1001> is_prime;
        static constexpr int block_size = 10'000;
        const int limit = std::sqrt(right);

        if (left <= 2 && right <= 2) return {-1, -1};

        std::ranges::fill(is_prime, 1);
        std::vector<int> primes;

        std::vector<int> res = {-1, -1};
        auto record = [best_gap = right - left + 1, previous = 0, &res](int candid) mutable {
            if (previous && candid - previous < best_gap) {
                best_gap = candid - previous;
                res = {previous, candid};
            }
            previous = candid;
        };

        for (int candid = 2; candid <= limit; candid++) {
            if (!is_prime[candid]) continue;
            for (int next = candid * candid; next <= limit; next += candid) {
                is_prime[next] = false;
            }

            if (candid >= left) record(candid);
            primes.emplace_back(candid);
        }

        std::array<std::uint8_t, block_size> block;
        for (int block_start = std::max(limit + 1, left); block_start <= right; block_start += block_size) {
            const int block_end = std::min(block_size, right - block_start + 1);

            std::ranges::fill(block, 1);
            for (const auto prime : primes) {
                const int multiplier = (block_start + prime - 1) / prime;
                const int start_idx = multiplier * prime - block_start;

                for (int j = start_idx; j < block_end; j += prime) {
                    block[j] = false;
                }
            }

            for (int block_candid = 0; block_candid < block_end; block_candid++) {
                if (!block[block_candid]) continue;
                record(block_start + block_candid);
            }
        }

        return res;
    }
};

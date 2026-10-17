class Solution {
public:
    int countPrimes(int n) const {
        static std::array<std::uint8_t, 5000001> is_prime;
        const int limit = std::sqrt(n);

        if (n <= 2) return 0;

        int res = 0;
        std::ranges::fill(is_prime, 1);
        for (int candid = 2; candid <= limit; candid++) {
            if (!is_prime[candid]) continue;
            for (int next = candid * candid; next < n; next += candid) {
                is_prime[next] = false;
            }
            res++;
        }
        for (int candid = limit + 1; candid < n; candid++) {
            if (is_prime[candid]) res++;
        }
        return res;
    }
};

class Solution {
public:
    int countPrimes(int n) const {
        static std::array<std::uint8_t, 5'000'001> is_prime;
        static constexpr int block_size = 10'0000;
        const int limit = std::sqrt(n);

        if (n <= 2) return 0;

        std::ranges::fill(is_prime, 1);
        std::vector<int> primes;
        primes.reserve(limit);
        for (int candid = 2; candid <= limit; candid++) {
            if (!is_prime[candid]) continue;
            primes.emplace_back(candid);
            for (int next = candid * candid; next <= limit; next += candid) {
                is_prime[next] = false;
            }
        }

        int res = std::size(primes);
        std::array<std::uint8_t, block_size> block;
        for (int block_start = limit + 1; block_start < n; block_start += block_size) {
            const int block_end = std::min(block_size, n - block_start);

            std::ranges::fill(block, 1);
            for (const auto prime: primes) {
                const int multiplier = (block_start + prime - 1) / prime;
                const int start_idx = multiplier * prime - block_start;

                for (int j = start_idx; j < block_end; j += prime) {
                    block[j] = false;
                }
            }

            for (int candid = 0; candid < block_end; candid++)
            {
                if (!block[candid]) continue;
                res++;
            }
        }

        return res;
    }
};
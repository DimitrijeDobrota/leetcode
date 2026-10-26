#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    int largestComponentSize(const vector<int> &nums) const {
        static std::array<int, 100'001> least_prime;
        static std::array<int, 100'001> remainder;
        static std::array<int, 100'001> primes;
        static std::array<int, 100'001> owner;
        static std::size_t primes_size;

        const auto n = std::size(nums);
        const auto max = std::ranges::max(nums);

        primes_size = 0;
        std::ranges::fill(least_prime, 0);
        std::ranges::fill(remainder, 1);

        for (int candid = 2; candid <= max; candid++) {
            if (least_prime[candid] == 0) {
                primes[primes_size++] = candid;
                least_prime[candid] = candid;
            }

            for (int j = 0; candid * primes[j] <= max; j++) {
                remainder[candid * primes[j]] = candid;
                least_prime[candid * primes[j]] = primes[j];
                if (primes[j] == least_prime[candid]) break;
            }
        }

        UnionFind uf(n);
        std::ranges::fill(owner, -1);
        for (auto [idx, value] : std::views::enumerate(nums)) {
            auto num = value;
            while (num > 1) {
                const int prime = least_prime[num];
                if (owner[prime] == -1)
                    owner[prime] = idx;
                else
                    uf.join(idx, owner[prime]);

                do {
                    num = remainder[num];
                } while (num > 1 && least_prime[num] == prime);
            }
        }

        return uf.max_size();
    }
};

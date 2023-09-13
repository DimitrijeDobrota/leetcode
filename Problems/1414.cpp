class Solution {
    typedef array<int, 45> cache_t;
    static inline constexpr const cache_t cache = []() constexpr -> cache_t {
        cache_t cache;
        cache[0] = cache[1] = 1;
        for (int i = 2; i < cache.size(); i++)
            cache[i] = cache[i - 1] + cache[i - 2];
        return cache;
    }();

  public:
    int findMinFibonacciNumbers(int k) {
        int res = 0;
        for (auto it = upper_bound(begin(cache), end(cache), k); k > 0; it--)
            while (k >= *it)
                k -= *it, res++;
        return res;
    }
};

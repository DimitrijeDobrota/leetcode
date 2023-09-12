typedef vector<string> cache_t;
static inline const cache_t cache = []() -> cache_t {
    cache_t cache(101);
    for (int i = 0; i <= 100; i++)
        cache[i] = to_string(i);
    return cache;
}();

class Solution {
  public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (gcd(i, j) != 1) continue;
                ans.push_back(cache[i] + '/' + cache[j]);
            }
        }
        return ans;
    }
};

class Solution {
  public:
    int nthSuperUglyNumber(int n, const vector<int> &primes) const {
        using type_t = tuple<long long, int, int>;
        priority_queue<type_t, vector<type_t>, greater<>> pq;

        for (int i = 0; i < size(primes); i++) {
            pq.emplace(primes[i], primes[i], 0);
        }

        static int nums[100002] = {1, 0};
        for (int i = 1; i < n;) {
            const auto [num, prime, idx] = pq.top();
            pq.pop();
            if (num != nums[i - 1]) nums[i++] = num;
            pq.emplace(1ll * prime * nums[idx + 1], prime, idx + 1);
        }

        return nums[n - 1];
    }
};

class Solution {
    static bool possible(const vector<int> &bloomDay, int m, int k, int n) {
        int adj = 0;

        for (const auto day : bloomDay) {
            adj = day <= n ? adj + 1 : 0;
            if (adj == k) adj = 0, m--;
        }

        return m <= 0;
    }

  public:
    int minDays(const vector<int> &bloomDay, int m, int k) const {
        if ((long long)m * k > size(bloomDay)) return -1;

        int low = 1, high = *max_element(begin(bloomDay), end(bloomDay));

        while (low < high) {
            const int mid = low + (high - low) / 2;
            if (possible(bloomDay, m, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

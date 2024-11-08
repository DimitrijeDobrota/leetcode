class Solution {
    int res = INT_MAX;

    bool doable(const vector<int> &nums, int cuts, long long maxi) {
        long long acc = 0;

        for (const int num : nums) {
            if (acc + num <= maxi)
                acc += num;
            else {
                if (--cuts < 0) return false;
                acc = num;
            }
        }

        return true;
    }

  public:
    int splitArray(const vector<int> &nums, int k) {
        long long low = 0, high = 0;

        for (const long long n : nums) {
            low = max(low, n);
            high += n;
        }

        while (low < high) {
            const auto mid = low + (high - low) / 2;
            if (doable(nums, k - 1, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

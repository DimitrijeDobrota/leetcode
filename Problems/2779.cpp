// Binary search: O(n * logn)
class Solution {
  public:
    int maximumBeauty(vector<int> &nums, int k) const {
        sort(begin(nums), end(nums));
        int res = 1;

        for (int i = 0; i < size(nums); i++) {
            const auto it = upper_bound(begin(nums), end(nums), 2 * k + nums[i]);
            res = max(res, (int)distance(begin(nums) + i, it));
        }

        return res;
    }
};

// Line sweep: O(n)
class Solution {
  public:
    int maximumBeauty(const vector<int> &nums, int k) const {
        int mini = INT_MAX, maxi = INT_MIN;
        static int count[200002];

        memset(count, 0x00, sizeof(count));
        for (const int n : nums) {
            const int a = max(n - k, 0);
            const int b = n + k + 1;

            count[a]++;
            count[b]--;

            mini = min(mini, a);
            maxi = max(maxi, b);
        }

        int res = 1;
        for (int i = mini, acc = 0; i <= maxi; i++) {
            acc += count[i];
            res = max(res, acc);
        }

        return res;
    }
};

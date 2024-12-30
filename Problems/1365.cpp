// sort + count
class Solution {
  public:
    vector<int> smallerNumbersThanCurrent(const vector<int> &nums) const {
        const int n = size(nums);
        static int idxs[501];
        vector<int> res(n);

        iota(idxs, idxs + n, 0);
        sort(idxs, idxs + n, [&](int a, int b) { return nums[a] < nums[b]; });

        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[idxs[i]] != nums[idxs[i - 1]]) {
                cnt = i;
            }
            res[idxs[i]] = cnt;
        }

        return res;
    }
};

// count
class Solution {
  public:
    vector<int> smallerNumbersThanCurrent(const vector<int> &nums) const {
        const int n = size(nums);
        static int count[101];
        vector<int> res(n);

        memset(count, 0x00, sizeof(count));
        for (const int n : nums)
            count[n + 1]++;
        for (int i = 1; i <= 100; i++)
            count[i] += count[i - 1];
        for (int i = 0; i < size(nums); i++)
            res[i] = count[nums[i]];

        return res;
    }
};

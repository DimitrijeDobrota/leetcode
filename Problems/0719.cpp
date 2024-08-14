class Solution {
    int count(const vector<int> &nums, int tgt) const {
        int res = 0;

        for (int l = 0, r = 1; r < size(nums); r++) {
            while (nums[r] - nums[l] > tgt)
                l++;
            res += r - l;
        }

        return res;
    }

  public:
    int smallestDistancePair(vector<int> &nums, int k) const {
        sort(begin(nums), end(nums));

        int low = 0, high = nums.back() - nums.front();
        while (low < high) {
            const int mid = low + (high - low) / 2;
            const int cnt = count(nums, mid);

            if (cnt < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

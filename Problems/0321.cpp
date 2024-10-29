class Solution {
    static bool greater(const vector<int> &nums1, const vector<int> &nums2, int i, int j) {
        while (i < size(nums1) && j < size(nums2) && nums1[i] == nums2[j])
            i++, j++;
        return j == size(nums2) || (i < size(nums1) && nums1[i] > nums2[j]);
    }

    static vector<int> merge(const vector<int> &nums1, const vector<int> &nums2, int k) {
        vector<int> res(k);

        for (int i = 0, j = 0, l = 0; l < k; l++) {
            res[l] = greater(nums1, nums2, i, j) ? nums1[i++] : nums2[j++];
        }

        return res;
    }

    static vector<int> maxArr(const vector<int> &nums, int k) {
        const int n = size(nums);
        vector<int> res(k);

        for (int i = 0, j = 0; i < n; i++) {
            while (n - i + j > k && j > 0 && res[j - 1] < nums[i])
                j--;
            if (j < k) res[j++] = nums[i];
        }

        return res;
    }

  public:
    vector<int> maxNumber(const vector<int> &nums1, const vector<int> &nums2, int k) const {
        const int n = size(nums1), m = size(nums2);
        vector<int> res(k);

        for (int i = max(0, k - m); i <= k && i <= n; i++) {
            const auto candid = merge(maxArr(nums1, i), maxArr(nums2, k - i), k);
            res = max(res, candid);
        }

        return res;
    }
};

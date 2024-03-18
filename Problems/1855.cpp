class Solution {
  public:
    int maxDistance(const vector<int> &nums1, const vector<int> &nums2) const {
        const int n = size(nums1), m = size(nums2);
        int res = 0, i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i] > nums2[j])
                i++;
            else
                res = max(res, j++ - i);
        }

        return res;
    }
};

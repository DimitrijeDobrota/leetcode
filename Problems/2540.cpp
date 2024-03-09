class Solution {
  public:
    int getCommon(const vector<int> &nums1, const vector<int> &nums2) const {
        const int n = size(nums1), m = size(nums2);

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) return nums1[i];
            if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }

        return -1;
    }
};

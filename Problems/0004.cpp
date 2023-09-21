class Solution {
  public:
    double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
        const int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        if (n % 2)
            return binary(nums1, nums2, n / 2, 0, n1 - 1, 0, n2 - 1);
        else
            return (binary(nums1, nums2, n / 2 - 1, 0, n1 - 1, 0, n2 - 1) +
                    binary(nums1, nums2, n / 2, 0, n1 - 1, 0, n2 - 1)) /
                   2.0;
    }

    double binary(const vector<int> &nums1, const vector<int> &nums2, int k, int s1, int e1, int s2, int e2) {
        if (s1 > e1) return nums2[k - s1];
        if (s2 > e2) return nums1[k - s2];

        const int m1 = s1 + (e1 - s1) / 2;
        const int m2 = s2 + (e2 - s2) / 2;

        if (m1 + m2 < k) {
            return nums1[m1] > nums2[m2] ? binary(nums1, nums2, k, s1, e1, m2 + 1, e2)
                                         : binary(nums1, nums2, k, m1 + 1, e1, s2, e2);
        } else {
            return nums1[m1] > nums2[m2] ? binary(nums1, nums2, k, s1, m1 - 1, s2, e2)
                                         : binary(nums1, nums2, k, s1, e1, s2, e2 - 1);
        }
        return -1;
    }
};

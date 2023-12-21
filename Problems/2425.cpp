class Solution {
  public:
    int xorAllNums(const vector<int> &nums1, const vector<int> &nums2) const {
        int a = 0, b = 0;
        for (const int n : nums1)
            a ^= n;
        for (const int n : nums2)
            b ^= n;
        return (nums2.size() % 2 * a) ^ (nums1.size() % 2 * b);
    }
};

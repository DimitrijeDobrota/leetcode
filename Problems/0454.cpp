class Solution {
  public:
    int fourSumCount(const vector<int> &nums1, const vector<int> &nums2, const vector<int> &nums3,
                     const vector<int> &nums4) const {
        const int n = size(nums1);
        unordered_map<int, int> um;
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                um[nums1[i] + nums2[j]]++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += um[-(nums3[i] + nums4[j])];
            }
        }

        return res;
    }
};

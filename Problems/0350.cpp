class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_multiset<int> s(nums1.begin(), nums1.end());

        vector<int> res;
        for (int n : nums2) {
            const auto it = s.find(n);
            if (it == s.end()) continue;
            s.erase(it);
            res.push_back(n);
        }
        return res;
    }
};
